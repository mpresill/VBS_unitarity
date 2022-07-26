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

Root files for one-operator contibutions are stored in [this](https://cernbox.cern.ch/index.php/s/SJ9wITRWR5LOqeo) repository. EFT linear and quadratic contributions have been produced separately. In order to read tree and branches of these root files, ```ExRootTreeReader.h``` and ```ExRootClasses.h``` libraries are needed.\\
Miao


## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
