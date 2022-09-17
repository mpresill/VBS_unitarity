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

## ExRootAnalysis
The starting file is a .root file obtained from the .lhe file using the ```ExRootAnalysis``` package, available [here](https://madgraph.mi.infn.it/Downloads/ExRootAnalysis/). Follow the instructions in ```README``` file for the installation.
Conversion from lhe to root can be done with following command line:

```
./ExRootLHEFConverter Miao.lhe Miao.root
```
Note: In order to read tree and branches of these root files, ```ExRootTreeReader.h``` and ```ExRootClasses.h``` libraries are needed. Make sure they have been installed correctly.

## Costanza's workflow

Codes for the production of histograms are available in [test](https://github.com/mpresill/VBS_unitarity/tree/main/test) repository. 
Download the folder and run the configuration file:

```
chmod +x config.sh
./config.sh
```




```Particle``` branch contains all kinematic informations about the event: for example, ```Particle.PT``` is a histograms filled with PTs of all particles entering the event. Starting from here, it is possible to obtain the kinematic information relating to the single particles (pseudorapidity, transverse momenta, etc.) and construct more complex observables (transverse masses, etc.). 
### Histograms production: "all_observable" codes
The codes used to construct histograms of a specific observable are written in C++ and are stored in [src (w bound)](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/src%20(w%20bound)) and [src (w/o bound)](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/src%20(w%7Co%20bound)) repositories, under the name ```all_observable``` (where "observable" is the observable of interest). Codes require as argument the name of the root file, e.g.

```
./all_mjj SM
./all_mjj cW_int
./all_mjj cW_quad
```
For the correct working of the codes, path of .root files and of the output file must be modified directly in the code (it may be possible to add two input arguments corresponding to two paths, to make the codes more general). Taking as an example the code ``` all_Eta```, it uses the PDG particle numbering scheme to search in ```Particle.Eta``` branch the value of pseudorapidity of outcoming charged particles (two leptons in the final state and two quarks that hadronize), event for event (NB: in some cases, the index of the particle in the event is used instead of PDG number for the identification).
```
if(abs(Particle->PID)<10&&(j==npart-1||j==npart-2)) {
      				  Etaj.push_back(Particle->Eta); }    
else if(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13) {
      				  Etal.push_back(Particle->Eta); }
```

Pseudorapidities of these particles are then collected in different histograms (one for each different type of particle): the latter are normalized with following weight

```
w = xsec*lum/n
```
where ```xsec``` is the cross section of the process, calculated directly by MadGraph in the generation and inserted by hand in the code (specific information can be replaced by few lines that implement the searching for the cross section value directly in the .root file); ```lum``` is luminosity, set to 100 inverse fb by default; ```n``` is the number of events.
Histograms thus obtained are collected in an unique output file. It's a .root file named with the name of the contribution considered, e.g.

```
SM.root
cW_int.root
cW_quad.root
```
!!! WARNING !!! This naming system works as long as the folder where the output is produced is not the same folder where the input files are stored.
After the running of ```all_observable``` code we have then a .root file containing histograms filled with observable of interest. Fore more complex observables, these ones are defined and constructed directly in the code. 
For mixed-contributions histograms, ```hadd``` command should be used.
Summarizing, the list of commands to obtain distribution for, e.g., cW contributions to invariant mass of jets, are:

```
./all_mjj SM
./all_mjj cW_int
./all_mjj cW_quad
hadd -f SM_cW_int_quad.root SM.root cW_int.root cW_quad.root  
```
NB: Root files thus obtained are useful for visualize observable distributions, but are NOT combine friendly. 

### Producing combine friendly files: "merge" and "merge_multipart" codes

Combine requires specific names for histograms of background's (SM) and signal's (SM+EFT) histograms. ```merge``` and ```merge_multipart``` codes arrange histograms previously produced into a single .root file which can be easily read by combine. ```merge``` requires as first input the observable that you want to consider, and as second input the particle to which that observable is associated. For example, to study transverse momenta of higher energy jet the command line is:

```
./merge PT j1
```
```merge_multipart``` has as its only argument the observable of interest:

```
./merge_multipart mjj
```
Path of histograms produced with ```all_observable``` must be properly specified in the code. EFT contribution to include in the file must be selected in the code too (there's a section for each EFT operator, just comment the ones you want to exclude). The output file is a .root file named with the considered observable. Some examples are listed below.

```
Eta_l1.root
PT_j2.root
mll.root
```
These files can interface directly with combine for likelihood scan application.

## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
