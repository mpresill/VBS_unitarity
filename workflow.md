This set of instructions serves as a guide for "dummies" to reproduce everything is presented in the paper.
Here is a summary of Costanza's thesis to guide the whole work.



# Computation of helicity amplitudes in Mathematica
Several Mathematica extensions must be installed to calculate the scattering amplitudes of the process:
- ```FeynRules``` package, available for download [here](https://feynrules.irmp.ucl.ac.be/), for the generation of EFT models;
- ```FeynInstall``` script, available [here](http://www.feynarts.de/), for the installation of ```FeynArts``` and ```FormCalc``` packages, necessary to draw the Feynman diagrams and to calculate the amplitudes;
- an additional package is also needed, that is ```VecSet```, defined [here](https://github.com/vsht/formcalc-mirror/blob/master/tools/VecSet.m), which contains functions to define components of four-vectors.

## Model generation
First step is the generation of EFT models. To decrease the computational load, it is preferable to generate a different model for each EFT contribution. The Mathematica notebook for model generation is contained in the [FeynArts Models](https://github.com/mpresill/VBS_unitarity/tree/main/FeynArts%20Models) folder. To select the EFT contribution you want to include, simply delete the extra Lagrangian pieces. Cards loaded in the notebook must be downloaded [here](https://github.com/SMEFTsim/SMEFTsim). Once all the models associated with the operators involved have been generated, they must be moved to ```FeynArts/Models``` folder.
## Amplitude computation
Codes for amplitude computation are stored [here](https://github.com/mpresill/VBS_unitarity/tree/main/Amplitudes%20Calculation%20Mathematica). Each code differs from the others for the loaded model and for the combination of helicity in the initial and final states. First of all 
```FeynArts```, ```FormCalc``` and ```VecSet``` packages are loaded. Following, the code consists of seven parts with the same structure:

```
1     name = "VBSssWW"
2     process = {V[3],V[3] -> V[3],V[3]}
3     top = CreateTopologies[0, 2->2];
4     VBStop = InsertFields[top,process,GenericModel->"cW",Model->"cW"]
5     ht = DiagramExtract[VBStop,4]
6     FormDot = TermCollect;
7     ampht = CalcFeynAmp[CreateFeynAmp[ht]];
8     res2 = Unabbr[ampht];
9     higgst = Simplify[ToComponents[res2,"++--"]];

```

Line 2 establishes the process (each particle has a code defined in the model, e.g V[3] is associated to W bosons). In lines 3-4 Feynman Diagrams are generated and can be displayed with the command ```Print```. In line 5 a specific diagram is extracted; in fact each diagram is calculated separately to ensure faster calculations. For the same reason the condition in line 6 is imposed, in which it is required to carry out less elaborate simplifications during the calculation. This significantly reduces the run time. In lines 7-8 the amplitude is generated and, in last line, helicities of initial and final states are specified.
Same steps are repeated for all diagrams associated with the process (3 t-channels, 3 u-channels and 1 contact diagram, for a total of 7 diagrams). Each part is separated by a line break in the code, which would otherwise be too heavy to run. In the end all seven diagrams are added up.

## Further simplifications by-hand
The obtained expression, actually, is not pretty at all. Further calculation by-hand can be performed to achieve an acceptable expression for the amplitude. You can copy the result in a new Mathematica notebook and start imposing some simplifications:

- only linear contribution to amplitude, i.e. ~ O(c_i), can be selected using the ```Collect``` function of Mathematica:
```
In[1] = Collect[expression, variable]
```
that collects different powers of specified variable in the expression, e.g.:
```
In[1] = Collect[b x^2 + 5 x + 7 x^2 + 9 a x + 2, x]
Out[1] = 2 + (5+9a)x + (7+b)x^2
```
After collection, the factors ~ O(1) and ~ O(c_i^2) are easily identifiable and can be deleted by-hand;
- High-energy limit can be imposing the neglection of masses as compared to p; it can be done with ```/.``` syntax of Mathematica:
```
In[1] = expression /. condition 1; condition 2; ...
```
for example:
```
In[1] = sqrt(p^2 + mW2)   /. p^2 + mW2 = p^2
Out[1] = p
```
- Using same method Mandelstam variables can be redefined as functions of center of mass energy S, as follows:
```
T = -(1+cos(theta))*S/2
U = -(1-cos(theta))*S/2
```
In that way can be highlighted the term of the amplitude that violates unitarity ( ~ O(S)).

These steps considerably simplify the expression of the amplitude, reporting only the term of interest for the calculation of the unitarity constraints. The last few steps can be done easily with by-hand calculations.

# MC simulation 
step 1: after producing gridpack in the ```genproductions/bin/Madgraph5_aMCatNLO``` or if you already have the gridpack you can copy it in this directory.

step 2: make directory and untar gridpack into that directory.

```
mkdir work
cd work
tar xf ../*.xz
```

step 3: assign vlaues to mentioned variables according to your need.

```
NEVENTS=10000 
RANDOMSEED=12345 
NCPU=1
```

step 4: run gridpack to produce LHE files
```
./runcmsgrid.sh $NEVENTS $RANDOMSEED $NCPU
```
detailed information is available here : https://twiki.cern.ch/twiki/bin/view/Main/CMSDAS2018_GEN_Draft

# From LHE to histograms

## Lhe to root conversione: ExRootAnalysis
The starting file is a .root file obtained from the .lhe file using the ```ExRootAnalysis``` package, available [here](https://madgraph.mi.infn.it/Downloads/ExRootAnalysis/). Follow the instructions in ```README``` file for the installation.
Conversion from lhe to root can be done with following command line:

```
./ExRootLHEFConverter Miao.lhe Miao.root
```
Structure of rootfiles is the following:
- ```Event``` branch contains information about events ID and events weight;
- ```Rwgt``` branch contains reweighting weights;
- ```Particle``` branch contains all kinematic informations about the event. 

Note: In order to read tree and branches of these root files, ```ExRootTreeReader.h``` and ```ExRootClasses.h``` libraries are needed. Make sure they have been installed correctly.

## Configuration of tools

Codes for the production of histograms are available in [test](https://github.com/mpresill/VBS_unitarity/tree/main/test) repository. 
Download the folder and run the configuration script:

```
chmod +x config.sh
./config.sh
```

Put in ```data``` folder your .root file. 
Files for operators entering VBS ssWW are available [here](https://cernbox.cern.ch/index.php/s/00ujWKQyEtiVkHI). Sample for reweighting application is ```full.root```; other files contain single operator contributions.


## Histograms production: "definitivo" code
The code used to produce histograms is named ```definitivo``` and source file is stored in [src](https://github.com/mpresill/VBS_unitarity/tree/main/test/src). 
Code requires three arguments:
- first one is the name of observable;
- second one is ```full``` or ```single```, based on whether you are using the sample for reweighting or the samples for single-operator analysis;
- third one selects the operator: for full sample analysis you have to specify coefficient and value (e.g. cW_m0p1 for cW = -0.1), for single operator analysis it is necessary to specify the coefficient and the EFT term (e.g. cW_int for linear contribution and cW_quad for quadratic contribution).
Examples are given below:

```
./definitivo deltaEtajj full cW_1
./definitivo deltaEtajj single cW_quad
```




```
w = xsec*lum/n
```
where ```xsec``` is the cross section of the process, calculated directly by MadGraph in the generation and inserted by hand in the code (specific information can be replaced by few lines that implement the searching for the cross section value directly in the .root file); ```lum``` is luminosity, set to 100 inverse fb by default; ```n``` is the number of events.
Histograms thus obtained are collected in an unique output file. It's a .root file named with the name of the contribution considered, e.g.

Note: .root files thus obtained are useful for visualize observable distributions, but are NOT combine friendly. 

### Producing combine friendly files: "merge" code

Combine requires specific names for background's (SM) and signal's (SM+EFT) histograms. ```merge``` code arranges histograms previously produced into a single .root file which can be easily read by combine. The code requires the observable of interest as argument:

```
./merge observable
```

Path of histograms produced with ```definitivo``` must be properly specified in the code. EFT contribution to include in the file must be selected in the code too (there's a section for each EFT operator, just comment the ones you want to exclude). The output file is a .root file named ```observable.root```.
This file can interface directly with combine for likelihood scan application.

## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
