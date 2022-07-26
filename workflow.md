This set of instructions serves as a guide for "dummies" to reproduce everything is presented in the paper.
Here is a summary of Costanza's thesis to guide the whole work.



# Computation of helicity amplitudes in Mathematica


# MC simulation 


# From LHE to histograms

Codes for the production of histograms are available in the repository [here](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/src%20(w%7Co%20bound)) (in ```src (w bound)``` directory the same codes are present, with the addition of some lines that implement the unitarity cut). The starting file is a .root file obtained from the .lhe file using the ExRootAnalysis package. For the installation of the libraries needed for the correct working of the package follow the instruction [here](https://cp3.irmp.ucl.ac.be/projects/ExRootAnalysis/wiki/UserManual).
Somewhere (need to review where and how) there is an executable file named ```ExRootLHEFConverter```. Putting the .lhe file in the same directory, the conversion can be done with following command line:

```
./ExRootLHEFConverter Miao.lhe Miao.root
```

## Costanza's workflow

Root files for one-operator contibutions are stored in [this](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/data) repository. EFT linear and quadratic contributions have been produced separately. In order to read tree and branches of these root files, ```ExRootTreeReader.h``` and ```ExRootClasses.h``` libraries are needed (available [here](https://github.com/delphes/delphes/tree/master/external/ExRootAnalysis)). ```Particle``` branch contains all kinematic informations about the event: for example, ```Particle.PT``` is a histograms filled with PTs of all particles entering the event. Starting from here, it is possible to obtain the kinematic information relating to the single particles (pseudorapidity, transverse momenta, etc.) and construct more complex observables (transverse masses, etc.). 
### "all_observable" codes
The codes used to construct histograms of a specific observable are written in C++ and are stored in [src (w bound)](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/src%20(w%20bound)) and [src (w/o bound)](https://github.com/mpresill/VBS_unitarity/tree/main/combine/Analysis%20tools/src%20(w%7Co%20bound)) repositories, under the name ```all_observable``` (where "observable" is the observable of interest). Codes require as argument the name of the root file, e.g.

```
./all_mjj SM
./all_mjj cW_int
./all_mjj cW_quad
```
For the correct working of the codes, path of .root files and of the output file must be modified directly in the code (it may be possible to add two input arguments corresponding to two paths, to make the codes more general). Taking as an example the code ``` all_Eta```, it uses the PDG particle numbering scheme to search in ```Particle.Eta``` branch the value of pseudorapidity of outcoming charged particles (two leptons in the final state and two quarks that hadronize).
```
if(abs(Particle->PID)<10&&(j==npart-1||j==npart-2)) {
      				  PTj.push_back(Particle->PT);
      				  Etaj.push_back(Particle->Eta); } 
      else if(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13) {
      				  PTl.push_back(Particle->PT);
      				  Etal.push_back(Particle->Eta); }
```


## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
