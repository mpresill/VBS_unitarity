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
After the running of ```all_observable``` code we have then a .root file containing histograms filled with observable of interest. Fore more complex observables, these ones are defined and constructed directly in the code. Considering for example the invariant mass of jets:

```  
for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart=branchParticle->GetEntries();
    if(npart!=10) continue;
    TLorentzVector v;
    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);  
      if(j==npart-1||j==npart-2)
        {
        double px = Particle->Px;
        double py = Particle->Py;
        double pz = Particle->Pz;
        double e = Particle->E;
        v.SetPxPyPzE(px + v.Px(),py + v.Py(),pz + v.Pz(),e + v.E());
        }
     }       
      double mjj=v.M();
      int nbins = Mjj->GetNbinsX();
      double ovfl = xmax - xmax/(nbins+3);
	if(mjj>xmax){
	           Mjj->Fill(ovfl,w);
	           }
	else{Mjj->Fill(mjj,w);
      v.Clear(); 
  }
```

## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
