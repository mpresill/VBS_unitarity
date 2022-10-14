#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include "ExRootTreeReader.h"
#include "ExRootClasses.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <TString.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;

//~~~~~~~~~~~~~ OBSERVABLE FUNCTIONS DECLARATION ~~~~~~~~~~~~~  

void Get_deltaEtajj(TH1F* observable, char* name_single, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_deltaPhijj(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_MET(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_M1T(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_Mo1(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_mjj(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);
void Get_mll(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins);

void Get_PT(TH1F* observable_l1, TH1F* observable_l2, TH1F* observable_j1, TH1F* observable_j2, 
     const TClonesArray* branchParticle, int npart, double w, double xminl, double xmaxl, double xminj1, double xmaxj1, double xminj2, double xmaxj2, int bins);
void Get_Eta(TH1F* observable_l1, TH1F* observable_l2, TH1F* observable_j1, TH1F* observable_j2, 
     const TClonesArray* branchParticle, int npart, double w, double xminl, double xmaxl, double xminj1, double xmaxj1, double xminj2, double xmaxj2, int bins);

void Get_Zeppenfeld(TH1F* observable_1, TH1F* observable_2, TH1F* observable_12, const TClonesArray* branchParticle, int npart, double w,
     double xmin, double xmax, int bins);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char*argv[]){

// Three arguments are required: first one is the observable; second one is the string "full" for all-operator analysis, or the 
// string "single" for one-operator analysis; third one is the specification of Wilson coefficient and, in first case, its value 
// and sign, e.g. "cW_m0p1" for cW = -0.1 for full analysis or "cW_int"/"cW_quad" for one-operator analysis.

  char infile[50];
  if(strcmp(argv[2],"full")==0)   sprintf(infile, "data/%s.root",argv[2]);
  else                            sprintf(infile, "data/%s.root",argv[3]);
  
  cout << "The input files were found." << endl;
  cout << "-- Reading: " << infile << endl;
  
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  const TClonesArray *branchEvent    = treeReader->UseBranch("Event");
  const TClonesArray *branchRwgt     = treeReader->UseBranch("Rwgt");

  //~~~~~~~~~~~~~ weights fixed parameters ~~~~~~~~~~~~~

  int    n   = treeReader->GetEntries();
  double lum = 100*1000;
  
  /*  creo un array con le possibili stringhe in input (coeff_value)  */

  TString coeff[15] = {"cW","cHW","cHWB","cHbox","cHDD","cHl1","cHl3","cll","cll1","cHq1","cHq3","cqq1","cqq11","cqq3","cqq31"};
  TString values[20] = {"_m1","_1","_m0p9","_0p9","_m0p8","_0p8","_m0p7","_0p7","_m0p6","_0p6","_m0p5","_0p5","_m0p4","_0p4","_m0p3","_0p3","_m0p2","_0p2","_m0p1","_0p1"};

  vector<TString> spec;
  spec.push_back("SM");
  for(int k=0; k<15; k++){
  	for(int l=0; l<20; l++){ 
  	     	spec.push_back(coeff[k]+values[l]);
        }
  }
  
  int position = 1000;
  if(strcmp(argv[2],"full")==0){
  	for(int m=0; m<301; m++){	
  		if	(strcmp(argv[3],spec[m].Data())==0)	position = m;
    	}
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~ histograms for combine ~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  double xmax  = 100;
  double xmin  = 0;
  double xmaxl = 100; 
  double xminl = 0; 
  double xmaxj = 100; 
  double xminj = 0;
  double xmaxj1 = 100; 
  double xminj1 = 0;
  double xmaxj2 = 100; 
  double xminj2 = 0;
  
  int bins = 10;
  
  if	    (strcmp(argv[1],"deltaEtajj") == 0){  xmax  = 8;
  						  xmin  = 0;
  }             
  else if   (strcmp(argv[1],"deltaPhijj") == 0){  xmax  = 6.30;
  						  xmin  = 3.14;

  }                
  else if   (strcmp(argv[1],"MET")        == 0){  xmax  = 600;
  						  xmin  = 0;

  }                           
  else if   (strcmp(argv[1],"M1T")        == 0){  xmax  = 1000;
  						  xmin  = 0;

  }                           
  else if   (strcmp(argv[1],"Mo1")        == 0){  xmax  = 1200;
  						  xmin  = 0;

  }                            
  else if   (strcmp(argv[1],"mjj")        == 0){  xmax  = 3500;
  						  xmin  = 0;

  }                           
  else if   (strcmp(argv[1],"mll")        == 0){  xmax  = 700;
  						  xmin  = 0;

  }                           
  else if   (strcmp(argv[1],"PT")         == 0){  xmaxl = 250;
  						  xminl = 0;
  						  xmaxj1 = 1000;
  						  xminj1 = 0; 
   						  xmaxj2 = 500;
  						  xminj2 = 0; 
  }                            						
  else if   (strcmp(argv[1],"Eta")        == 0){  xmaxl = 2.5;
  						  xminl = -2.5;
  						  xmaxj1 = 5;
  						  xminj1 = -5;
   						  xmaxj2 = 5;
  						  xminj2 = -5;  
  }               
  else if   (strcmp(argv[1],"Zeppenfeld") == 0){  xmax  = 1.7;
  						  xmin = -1.7;
  }                    
  
  
//  int NBINS, NBINSl, NBINSj, NBINS1, NBINS2, NBINS12;
//  double_t edges[NBINS + 1], edgesl[NBINSl + 1], edgesj[NBINSj + 1], edges1[NBINS1 + 1], edges2[NBINS2 + 1], edges12[NBINS12 + 1];
  
  //~~~~ Multiparticle Observables (1 histogram) ~~~~
  
  char name_single[50];
  sprintf(name_single,"h_%s",argv[1]);
  
  /* (1) normal binning */ 
  TH1F *observable = new TH1F(name_single,"",bins,xmin,xmax);
  //=new TH1F(name_single,"",bins,xmin,xmax);
    
  /* (2) variable width bins */ 
  // TH1F *observable=new TH1F(name_single,"",NBINS,edges);

  //~~~~ Eta-like Observables (4 histograms) ~~~~
  
  char name_4l1[50];
  sprintf(name_4l1,"h_%s_l1",argv[1]);
  char name_4l2[50];
  sprintf(name_4l2,"h_%s_l2",argv[1]);
  char name_4j1[50];
  sprintf(name_4j1,"h_%s_j1",argv[1]);
  char name_4j2[50];
  sprintf(name_4j2,"h_%s_j2",argv[1]);
  
  /* (1) normal binning */ 
  TH1F *observable_l1=new TH1F(name_4l1,"",bins,xminl,xmaxl);
  TH1F *observable_l2=new TH1F(name_4l2,"",bins,xminl,xmaxl);
  TH1F *observable_j1=new TH1F(name_4j1,"",bins,xminj1,xmaxj1);
  TH1F *observable_j2=new TH1F(name_4j2,"",bins,xminj2,xmaxj2);
  
  /* (2) variable width bins */
  // TH1F *observable_l1=new TH1F(name_4l1,"",NBINSl,edgesl);
  // TH1F *observable_l2=new TH1F(name_4l2,"",NBINSl,edgesl);
  // TH1F *observable_j1=new TH1F(name_4j1,"",NBINSj,edgesj);
  // TH1F *observable_j2=new TH1F(name_4j2,"",NBINSj,edgesj);
  
  //~~~~ Zeppenfeld Observables (3 histograms) ~~~~
  
  /* (1) normal binning */
  TH1F *observable_1=new  TH1F("h_Zeppenfeld_1","",bins,xmin,xmax);
  TH1F *observable_2=new  TH1F("h_Zeppenfeld_2","",bins,xmin,xmax);
  TH1F *observable_12=new TH1F("h_Zeppenfeld_12","",bins,xmin,xmax);
  
  /* (2) variable width bins */
  // TH1F *observable_1=new  TH1F("h_Zeppenfeld_1","",NBINS1,edges1);
  // TH1F *observable_2=new  TH1F("h_Zeppenfeld_2","",NBINS2,edges2);
  // TH1F *observable_12=new TH1F("h_Zeppenfeld_12","",NBINS12,edges12);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Unitarity bounds ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string   op    = argv[3];
string   cW    = "cW_";
string   cHW   = "cHW_";
string   cHWB  = "cHWB_";
string   cHDD  = "cHDD_";
string   cHbox = "cHbox_";

const char*    found_cW    = strstr(op.c_str(), cW.c_str());
const char*    found_cHW   = strstr(op.c_str(), cHW.c_str());
const char*    found_cHWB  = strstr(op.c_str(), cHWB.c_str());
const char*    found_cHDD  = strstr(op.c_str(), cHDD.c_str());
const char*    found_cHbox = strstr(op.c_str(), cHbox.c_str());

double bound;

if       (found_cHW)    bound = 7100;
else if  (found_cW)     bound = 1800;
else if  (found_cHDD)   bound = 7100;
else if  (found_cHbox)  bound = 5000;
else                    bound = 10000000000;

cout << endl;
cout << "########### PARAMETERS INFORMATION ###########" << endl;
  cout << "#                                            #" << endl;
cout << "#   Luminosity: " << lum << " inverse pb            #" << endl;
cout << "#   Operator: " << op << "                           #" << endl;
cout << "#   Unitarity bound: " << bound/1000 << " TeV" << "                 #" << endl;

if      (strcmp(argv[4],"unit")==0)    cout << "#   Cuts application: YES                    #" << endl;
else if (strcmp(argv[4],"nounit")==0)  cout << "#   Cuts application: NO                     #"  << endl;
cout << "#                                            #" << endl;

vector<double> E;
vector<double> Px;
vector<double> Py;
vector<double> Pz;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int number_events   = n;
int selected_events = n;


  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart = branchParticle->GetEntries();
    if(branchParticle->GetEntries()==0) continue;
    if(npart!=10){  number_events   = number_events - 1;
                    selected_events = selected_events - 1;
                    continue;
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~ UNITARITY BOUNDS ~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    for(int j=0; j<npart; j++){    
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if      (j==2&&abs(Particle->PID)==24){   E.push_back(Particle->E);
        				   	Px.push_back(Particle->Px);
        			           	Py.push_back(Particle->Py);
                                           	Pz.push_back(Particle->Pz);    
      }
      else if (j==3&&abs(Particle->PID)==24){   E.push_back(Particle->E);
        					Px.push_back(Particle->Px);
        					Py.push_back(Particle->Py);
        					Pz.push_back(Particle->Pz);    
      } 
    }  

    TLorentzVector p3(Px[0],Py[0],Pz[0],E[0]);
    TLorentzVector p4(Px[1],Py[1],Pz[1],E[1]);
    TLorentzVector p     = p3 + p4;
    double         s     = p*p;
    double         sqrtS = sqrt(s);
    if (strcmp(argv[3],"SM")!=0 && strcmp(argv[4],"unit")==0 && sqrtS>bound){   E.clear();
									        Px.clear();
									        Py.clear();
										Pz.clear(); 
										selected_events = selected_events - 1;
										continue;
    }
    else{                                                                       E.clear();
									        Px.clear();
									        Py.clear();
										Pz.clear(); 
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~ EVENT WEIGHT ~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    double ev_wgt = 1.;
    TRootLHEFEvent *Event = (TRootLHEFEvent*) branchEvent->At(0);  		  // each branch has a number of entries (1 for Event, number 
    ev_wgt = Event->Weight;                                                       // of weights for Rwgt, number of particles for Particle)
                                      		
    // Reweighting Weight

    /*  creo un array con i pesi  */

    double rwgt = 1.;

/*    if(strcmp(argv[2],"full")==0){	for(int r=0; r<301; r++){	TRootWeight *Rwgt = (TRootWeight*) branchRwgt->At(r);
      									weights.push_back(Rwgt->Weight);
    					}
    					rwgt = weights[position];
    } */
    
    if(strcmp(argv[2],"full")==0){	TRootWeight *Rwgt = (TRootWeight*) branchRwgt->At(position);
      					rwgt = Rwgt->Weight;
    }
     
    //~~~ TOTAL WEIGHT ~~~

    double w;
    double xsec = ev_wgt*n;     /*     pb      */
    double lum = 100*1000;      /* Inverse pb  */
    if(strcmp(argv[2],"full")==0)          w = xsec*lum*rwgt;
    else if(strcmp(argv[2],"single")==0)   w = xsec*lum;  

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~ OBSERVABLE ~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    if      (strcmp(argv[1],"deltaEtajj")==0)           Get_deltaEtajj(observable, name_single, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"deltaPhijj")==0)           Get_deltaPhijj(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"MET")==0)             	Get_MET(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"M1T")==0)             	Get_M1T(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"Mo1")==0)             	Get_Mo1(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"mjj")==0)             	Get_mjj(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"mll")==0)             	Get_mll(observable, branchParticle, npart, w, xmin, xmax, bins);
    else if (strcmp(argv[1],"PT")==0)              	Get_PT(observable_l1, observable_l2, observable_j1, observable_j2, branchParticle, npart, w, xminl, xmaxl, xminj1, xmaxj1, xminj2, xmaxj2, bins);
    else if (strcmp(argv[1],"Eta")==0)             	Get_Eta(observable_l1, observable_l2, observable_j1, observable_j2, branchParticle, npart, w, xminl, xmaxl, xminj1, xmaxj1,  xminj2, xmaxj2, bins);
    else if (strcmp(argv[1],"Zeppenfeld")==0)      	Get_Zeppenfeld(observable_1, observable_2, observable_12, branchParticle, npart, w, xmin, xmax, bins); 
  }
  

  
  cout << "#   Number of VBS ssWW events = "       << number_events << "         #" << endl;
  cout << "#   Number of 'on unitarity' events = " << selected_events << "   #" << endl;
  cout << "#                                            #" << endl;
  cout << "##############################################" << endl;
  cout << endl;
  
  cout << "Histograms were successfully filled." << endl;
  cout << endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COMBINE-FRIENDLY OUTPUT FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~ no unit ~~~~~~~~~~~~~~
  
  /* Single observable */
  
  char outfile[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile, "histos_unit/%s/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile, "histos/%s/%s_%s.root",argv[1],argv[3],argv[2]);
  TFile* risultati=new TFile(outfile, "RECREATE");
  
  /* PT and Eta */
  
  char outfile_l1[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_l1, "histos_unit/%s_l1/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_l1, "histos/%s_l1/%s_%s.root",argv[1],argv[3],argv[2]);  
  TFile* risultati_l1=new TFile(outfile_l1, "RECREATE");
  
  char outfile_l2[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_l2, "histos_unit/%s_l2/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_l2, "histos/%s_l2/%s_%s.root",argv[1],argv[3],argv[2]);  
  TFile* risultati_l2=new TFile(outfile_l2, "RECREATE");
  
  char outfile_j1[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_j1, "histos_unit/%s_j1/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_j1, "histos/%s_j1/%s_%s.root",argv[1],argv[3],argv[2]);  
  TFile* risultati_j1=new TFile(outfile_j1, "RECREATE");
  
  char outfile_j2[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_j2, "histos_unit/%s_j2/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_j2, "histos/%s_j2/%s_%s.root",argv[1],argv[3],argv[2]);  
  TFile* risultati_j2=new TFile(outfile_j2, "RECREATE");
 
  /* Zeppenfeld */
  
  char outfile_1[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_1, "histos_unit/%s_1/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_1, "histos/%s_1/%s_%s.root",argv[1],argv[3],argv[2]);
  TFile* risultati_1=new TFile(outfile_1, "RECREATE");
  
  char outfile_2[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_2, "histos_unit/%s_2/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_2, "histos/%s_2/%s_%s.root",argv[1],argv[3],argv[2]);
  TFile* risultati_2=new TFile(outfile_2, "RECREATE");
  
  char outfile_12[50];
  if      (strcmp(argv[4],"unit")==0)   sprintf(outfile_12, "histos_unit/%s_12/%s_%s.root",argv[1],argv[3],argv[2]);
  else if (strcmp(argv[4],"nounit")==0) sprintf(outfile_12, "histos/%s_12/%s_%s.root",argv[1],argv[3],argv[2]);
  TFile* risultati_12=new TFile(outfile_12, "RECREATE");

  cout << endl;
  cout << "NOTE: SysErrors are not inhibiting the operation of the program." << endl;
  cout << endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    
  if(strcmp(argv[1],"Eta")==0||strcmp(argv[1],"PT")==0){  
  		risultati_l1  -> cd(); 
  		observable_l1 -> Write();
  		risultati_l1  -> Close();
  		
  		risultati_l2  -> cd();
  		observable_l2 -> Write();
  		risultati_l2  -> Close();
  		
  		risultati_j1  -> cd();
  		observable_j1 -> Write();
  		risultati_j1  -> Close();
  		
  		risultati_j2  -> cd();
  		observable_j2 -> Write();
  		risultati_j2  -> Close(); 
  }                
  else if(strcmp(argv[1],"Zeppenfeld")==0){ 
                risultati_1   -> cd();               
       		observable_1  -> Write();
       		risultati_1   -> Close();
       		
       		risultati_2   -> cd();
  		observable_2  -> Write();
  		risultati_2   -> Close();
  		
  		risultati_12  -> cd();
  		observable_12 -> Write();
  		risultati_12  -> Close();
  }   
  else{   	risultati     -> cd();
                observable    -> Write();
                risultati     -> Close();
  }
  
  cout << "The output files were successfully generated." << endl;
  
  if(strcmp(argv[1],"Eta")==0||strcmp(argv[1],"PT")==0){  cout << "-- Outfile: " << outfile_l1 << endl;
  							  cout << "-- Outfile: " << outfile_l2 << endl;
  							  cout << "-- Outfile: " << outfile_j1 << endl;
  							  cout << "-- Outfile: " << outfile_j2 << endl;
  }
  else if(strcmp(argv[1],"Zeppenfeld")==0){ 		  cout << "-- Outfile: " << outfile_1  << endl;
  							  cout << "-- Outfile: " << outfile_2  << endl;
  							  cout << "-- Outfile: " << outfile_12 << endl;
  }
  else                                                    cout << "-- Outfile: " << outfile    << endl;
    
  cout << endl;
  cout << "###############################" << endl;
  cout << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OBSERVABLES DEFINITION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~ deltaEtajj ~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_deltaEtajj(TH1F* observable, char* name_single, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){
  
  /* definition and filling */

  double delta;
  double eta1;
  double eta2;
  
  for(int j=0; j<npart; j++){         //  j sono gli indici delle particelle
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if(abs(Particle->PID)<10&&j==npart-1)      eta2 = Particle->Eta;
    else if(abs(Particle->PID)<10&&j==npart-2) eta1 = Particle->Eta;
  }

  delta = abs(eta1 - eta2);
  int    nbins = observable->GetNbinsX();
  double ovfl  = xmax - (xmax-xmin)/(nbins+3);
  double undfl = xmin + (xmax-xmin)/(nbins+3);

  if      (delta < xmin) observable->Fill(undfl,w);
  else if (delta > xmax) observable->Fill(ovfl,w);
  else                   observable->Fill(delta,w);

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~ deltaPhijj ~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_deltaPhijj(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  double delta;
  double phi1;
  double phi2;
           
  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if	     (abs(Particle->PID)<10&&j==npart-1)  phi2 = Particle->Phi; 
    else if  (abs(Particle->PID)<10&&j==npart-2)  phi1 = Particle->Phi; 
  }  
      
  delta = abs(phi1 - phi2);
  int    nbins = observable->GetNbinsX();
  double ovfl = xmax - (xmax-xmin)/(nbins+3);
  
  if	   (delta>xmax)		observable->Fill(ovfl,w);
  else if  (delta<=3.14159265)	observable->Fill(2*3.14159265-delta,w);
  else			        observable->Fill(delta,w); 

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ MET ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_MET(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  //  int    nbins = observable->GetNbinsX();
  double ovfl  = xmax - xmax/(bins+3);
  double px1, py1, px2, py2;
  double met, px, py, pz, e, Met;
  TLorentzVector v1;
  TLorentzVector v2;

  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if		(Particle->PT==0)             		  continue;        
    if          (abs(Particle->PID)>10&&j==npart-3){	  px1 = Particle->Px;
      							  py1 = Particle->Py;
      							  px = Particle->Px;
      							  py = Particle->Py;
      							  pz = Particle->Pz;
      							  e = Particle->E;
      							  v1.SetPxPyPzE(px,py,pz,e);
    }
    else if	(abs(Particle->PID)>10&&j==npart-4){	  px2 = Particle->Px;
                                 			  py2 = Particle->Py;
                                                          px = Particle->Px;
      							  py = Particle->Py;
       			         			  pz = Particle->Pz;
        		         			  e = Particle->E;
                                                          v2.SetPxPyPzE(px,py,pz,e);
    }
  }   
  
  Met = (v1 + v2).Pt();
  px  = px1 + px2;
  py  = py1 + py2;  
  met = sqrt(px*px+py*py);
  
  if   (met>xmax)  observable->Fill(ovfl,w);
  else             observable->Fill(met,w);    

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ M1T ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_M1T(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  TLorentzVector v1, v2, l1, l2;
  int    nbins = observable->GetNbinsX();
  double ovfl  = xmax - xmax/(nbins+3);

  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if		(Particle->PT==0)             		  continue;                               
    if		(abs(Particle->PID)>10&&j==npart-5){      l1.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                 			  l1.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if     (abs(Particle->PID)>10&&j==npart-6){      l2.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                                          l2.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if     (abs(Particle->PID)>10&&j==npart-3){      v1.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                                          v1.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if     (abs(Particle->PID)>10&&j==npart-4) {     v2.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                                          v2.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    } 
  }
      
  double mll2   = (l1 + l2).M()*(l1 + l2).M();
  double ptll2  = (l1 + l2).Pt()*(l1 + l2).Pt();
  double ptmiss = (v1 + v2).Pt();
  double m1t    = sqrt(pow(sqrt(mll2+ptll2)+ptmiss,2) - (l1 + l2 + v1 + v2).Pt()*(l1 + l2 + v1 + v2).Pt());  
  
  if   (m1t>xmax)  observable->Fill(ovfl,w);
  else             observable->Fill(m1t,w);  

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ Mo1 ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_Mo1(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  TLorentzVector v1, v2, l1, l2;
  int    nbins = observable->GetNbinsX();
  double ovfl  = xmax - xmax/(nbins+3);

  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if		(Particle->PT==0)             		  continue;                                 
    if		(abs(Particle->PID)>10&&j==npart-5){ 	  l1.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                           	 	  l1.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if(abs(Particle->PID)>10&&j==npart-6){ 	  l2.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                                	  l2.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if(abs(Particle->PID)>10&&j==npart-3){ 	  v1.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                	        	  v1.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    }
    else if(abs(Particle->PID)>10&&j==npart-4){ 	  v2.SetPtEtaPhiM(Particle->PT,Particle->Eta,Particle->Phi,Particle->M);
                                                	  v2.SetPxPyPzE(Particle->Px,Particle->Py,Particle->Pz,Particle->E);
    } 
  }
      
  double ptmiss = (v1 + v2).Pt();
  double mo1    = sqrt((l1.Pt() + l2.Pt() + ptmiss)*(l1.Pt() + l2.Pt() + ptmiss) - (l1 + l2 + v1 + v2).Pt()*(l1 + l2 + v1 + v2).Pt());       
      
  if   (mo1>xmax)  observable->Fill(ovfl,w);
  else             observable->Fill(mo1,w);   

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ mjj ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_mjj(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  TLorentzVector v;
  int    nbins = observable->GetNbinsX();
  double ovfl = xmax - xmax/(nbins+3);
    
  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      
    if (j==npart-1||j==npart-2){ double px = Particle->Px;
        		         double py = Particle->Py;
        		         double pz = Particle->Pz;
        		         double e = Particle->E;
        			 v.SetPxPyPzE(px + v.Px(),py + v.Py(),pz + v.Pz(),e + v.E());
    }
  }  
     
  double mjj=v.M();
  if   (mjj>xmax)  observable->Fill(ovfl,w);
  else             observable->Fill(mjj,w);
  v.Clear(); 

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ mll ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_mll(TH1F* observable, const TClonesArray* branchParticle, int npart, double w, double xmin, double xmax, int bins){

  /* definition and filling */

  vector<double> E;
  vector<double> Px;
  vector<double> Py;
  vector<double> Pz;
  
  for(int j=0; j<branchParticle->GetEntries(); j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);  
    if (abs(Particle->PID)==11||abs(Particle->PID)==13||abs(Particle->PID)==15){ E.push_back(Particle->E);
        									 Px.push_back(Particle->Px);
   									         Py.push_back(Particle->Py);
    									         Pz.push_back(Particle->Pz);            
    }
  }
      
  TLorentzVector l1(Px[0],Py[0],Pz[0],E[0]);
  TLorentzVector l2(Px[1],Py[1],Pz[1],E[1]);
  double         mll   = (l1+l2).M();
  int            nbins = observable->GetNbinsX();
  double         ovfl  = xmax - xmax/(nbins+3);

  if   (mll>xmax)  observable->Fill(ovfl,w);
  else             observable->Fill(mll,w);
        
  E.clear();
  Px.clear();
  Py.clear();
  Pz.clear();

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~ Zeppenfeld ~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_Zeppenfeld(TH1F* observable_1, TH1F* observable_2, TH1F* observable_12, const TClonesArray* branchParticle, int npart, double w,
     double xmin, double xmax, int bins){

    /* definition and filling */
  
    double zeppy12, zeppy1, zeppy2;
    double etal1, etal2, etaj1, etaj2, maxx;
    double pt1, pt2;
    
    for(int j=0; j<npart; j++){           /* j sono gli indici delle particelle */
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if	(abs(Particle->PID)<10&&j==npart-1)   etaj2 = Particle->Eta; 
      else if   (abs(Particle->PID)<10&&j==npart-2)   etaj1 = Particle->Eta; 
      else if   (abs(Particle->PID)>10&&j==npart-6){  etal2 = Particle->Eta;
                                                      pt2 = Particle->PT;
      } 
      else if	(abs(Particle->PID)>10&&j==npart-5){  etal1 = Particle->Eta;
                                                      pt1   = Particle->PT; 
      }   
    }  
    
    if(pt2>pt1){    maxx  = etal2;
                    etal2 = etal1;
                    etal1 = maxx;                    
    }

    cout << "Eta_l1 = " << etal1 << endl;
    cout << "Eta_l2 = " << etal2 << endl;
    cout << "Eta_j1 = " << etaj1 << endl;
    cout << "Eta_j2 = " << etaj2 << endl;
    
    double ll = etal1 + etal2, jj = etaj1 + etaj2;

    zeppy12 = (ll-0.5*jj)/abs(etaj1-etaj2);
    zeppy1  = (etal1-0.5*jj)/abs(etaj1-etaj2);
    zeppy2  = (etal2-0.5*jj)/abs(etaj1-etaj2);
        
    int nbins = observable_12->GetNbinsX();
    double ovfl = xmax - (xmax-xmin)/(nbins+3);
    double undfl = xmin + (xmax-xmin)/(nbins+3);

    if	     (zeppy12>xmax)  observable_12->Fill(ovfl,w);
    else if  (zeppy12<xmin)  observable_12->Fill(undfl,w);
    else		     observable_12->Fill(zeppy12,w);

    if	     (zeppy1>xmax)   observable_1->Fill(ovfl,w);
    else if  (zeppy1<xmin)   observable_1->Fill(undfl,w);
    else		     observable_1->Fill(zeppy1,w);  

    if       (zeppy2>xmax)   observable_2->Fill(ovfl,w);
    else if  (zeppy2<xmin)   observable_2->Fill(undfl,w);
    else		     observable_2->Fill(zeppy2,w);  
    
    cout << endl;
    
    cout << "Zeppenfeld_1 = " << zeppy1 << endl;
    cout << "Zeppenfeld_2 = " << zeppy2 << endl;
    cout << "Zeppenfeld_12 = " << zeppy12 << endl;
    cout << endl;
    cout << endl;
    
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~ Eta ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_Eta(TH1F* observable_l1, TH1F* observable_l2, TH1F* observable_j1, TH1F* observable_j2, 
     const TClonesArray* branchParticle, int npart, double w, double xminl, double xmaxl, double xminj1, double xmaxj1, double xminj2, double xmaxj2, int bins){

  /* definition and filling */

  vector<double> PTj;
  vector<double> PTl;
  vector<double> Etaj;
  vector<double> Etal;
     
  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if		(abs(Particle->PID)<10&&(j==npart-1||j==npart-2)){				PTj.push_back(Particle->PT);
      				  								Etaj.push_back(Particle->Eta);
    } 
    else if	(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13) {      PTl.push_back(Particle->PT);
      				  								Etal.push_back(Particle->Eta);
    } 
  }      

  if	   (PTj[0]>PTj[1]){ 	int    nbins1 = observable_j1->GetNbinsX();
                      	        double ovfl1  = xmaxj1 - (xmaxj1-xminj1)/(nbins1+3);
                      		double undfl1 = xminj1 + (xmaxj1-xminj1)/(nbins1+3);
                      		if       (Etaj[0]>xmaxj1)  observable_j1->Fill(ovfl1,w);
                      		else if  (Etaj[0]<xminj1)  observable_j1->Fill(undfl1,w);
	              		else                       observable_j1->Fill(Etaj[0],w);      
	                        int    nbins2 = observable_j2->GetNbinsX();
                     	        double ovfl2  = xmaxj2 - (xmaxj2-xminj2)/(nbins2+3);
                                double undfl2 = xminj2 + (xmaxj2-xminj2)/(nbins2+3);
                                if       (Etaj[1]>xmaxj2)  observable_j2->Fill(ovfl2,w);
                                else if  (Etaj[1]<xminj2)  observable_j2->Fill(undfl2,w);
	                        else                       observable_j2->Fill(Etaj[1],w);                       
  }
  else if  (PTj[0]<PTj[1]){     int    nbins1 = observable_j1->GetNbinsX();
                                double ovfl1  = xmaxj1 - (xmaxj1-xminj1)/(nbins1+3);
                      		double undfl1 = xminj1 + (xmaxj1-xminj1)/(nbins1+3);
                      		if       (Etaj[1]>xmaxj1)  observable_j1->Fill(ovfl1,w);
                      		else if  (Etaj[1]<xminj1)  observable_j1->Fill(undfl1,w);
	              		else                       observable_j1->Fill(Etaj[1],w);      
	                        int    nbins2 = observable_j2->GetNbinsX();
                      		double ovfl2  = xmaxj2 - (xmaxj2-xminj2)/(nbins2+3);
                      		double undfl2 = xminj2 + (xmaxj2-xminj2)/(nbins2+3);
                      		if       (Etaj[0]>xmaxj2)  observable_j2->Fill(ovfl2,w);
                      		else if  (Etaj[0]<xminj2)  observable_j2->Fill(undfl2,w);
	              		else                       observable_j2->Fill(Etaj[0],w); 
  }      
     
  if       (PTl[0]>PTl[1]){     int    nbins1 = observable_l1->GetNbinsX();
                      		double ovfl1  = xmaxl - (xmaxl-xminl)/(nbins1+3);
                      		double undfl1 = xminl + (xmaxl-xminl)/(nbins1+3);
                      		if       (Etal[0]>xmaxl)  observable_l1->Fill(ovfl1,w);
                      		else if  (Etal[0]<xminl)  observable_l1->Fill(undfl1,w);
	              		else                      observable_l1->Fill(Etal[0],w);     
	                        int    nbins2 = observable_l2->GetNbinsX();
                      		double ovfl2  = xmaxl - (xmaxl-xminl)/(nbins2+3);
                      		double undfl2 = xminl + (xmaxl-xminl)/(nbins2+3);
                      		if       (Etal[1]>xmaxl)  observable_l2->Fill(ovfl2,w);
                      		else if  (Etal[1]<xminl)  observable_l2->Fill(undfl2,w);
	              		else                      observable_l2->Fill(Etal[1],w);                       
  }
  else if  (PTl[0]<PTl[1]){     int    nbins1 = observable_l1->GetNbinsX();
                                double ovfl1  = xmaxl - (xmaxl-xminl)/(nbins1+3);
                      	 	double undfl1 = xminl + (xmaxl-xminl)/(nbins1+3);
                      		if       (Etal[1]>xmaxl)  observable_l1->Fill(ovfl1,w);
                      		else if  (Etal[1]<xminl)  observable_l1->Fill(undfl1,w);
	              		else			  observable_l1->Fill(Etal[1],w);      
	                        int    nbins2 = observable_l2->GetNbinsX();
                      		double ovfl2  = xmaxl - (xmaxl-xminl)/(nbins2+3);
                      		double undfl2 = xminl + (xmaxl-xminl)/(nbins2+3);
                      		if       (Etal[0]>xmaxl)  observable_l2->Fill(ovfl2,w);
                      		else if  (Etal[0]<xminl)  observable_l2->Fill(undfl2,w);
	              		else 			  observable_l2->Fill(Etal[0],w); 
  }      

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~` PT ~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Get_PT(TH1F* observable_l1, TH1F* observable_l2, TH1F* observable_j1, TH1F* observable_j2, 
     const TClonesArray* branchParticle, int npart, double w, double xminl, double xmaxl, double xminj1, double xmaxj1, double xminj2, double xmaxj2, int bins){

  /* definition and filling */

  vector<double> PTj;
  vector<double> PTl;
     
  for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
    if		(Particle->PT==0)  				        		     continue;
    if		(abs(Particle->PID)<10&&(j==npart-1||j==npart-2))	                     PTj.push_back(Particle->PT);
    else if	(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13)     PTl.push_back(Particle->PT);
  }    
   
  if		(PTj[0]>PTj[1]){  	int    nbins1 = observable_j1->GetNbinsX();
                      			double ovfl1  = xmaxj1 - xmaxj1/(nbins1+3);
                      			if     (PTj[0]>xmaxj1)  observable_j1->Fill(ovfl1,w);
	              			else                    observable_j1->Fill(PTj[0],w);      
	              			int    nbins2 = observable_j2->GetNbinsX();
                      			double ovfl2  = xmaxj2 - xmaxj2/(nbins2+3);
                      			if     (PTj[1]>xmaxj2)  observable_j2->Fill(ovfl2,w);
	              			else                    observable_j2->Fill(PTj[1],w);                       
  }
  else if	(PTj[0]<PTj[1]){  	int    nbins1 = observable_j1->GetNbinsX();
                      			double ovfl1  = xmaxj1 - xmaxj1/(nbins1+3);
                      			if     (PTj[1]>xmaxj1)  observable_j1->Fill(ovfl1,w);
	              			else                    observable_j1->Fill(PTj[1],w);      
	              			int    nbins2 = observable_j2->GetNbinsX();
                      			double ovfl2  = xmaxj2 - xmaxj2/(nbins2+3);
                      			if     (PTj[0]>xmaxj2)  observable_j2->Fill(ovfl2,w);
	              			else                    observable_j2->Fill(PTj[0],w); 
  }          
  
  if		(PTl[0]>PTl[1]){  	int    nbins1 = observable_l1->GetNbinsX();
                      			double ovfl1  = xmaxl - xmaxl/(nbins1+3);
                      			if     (PTl[0]>xmaxl)  observable_l1->Fill(ovfl1,w);
	              			else                   observable_l1->Fill(PTl[0],w);      
	              			int    nbins2 = observable_l2->GetNbinsX();
                      			double ovfl2  = xmaxl - xmaxl/(nbins2+3);
                      			if     (PTl[1]>xmaxl)  observable_l2->Fill(ovfl2,w);
	              			else                   observable_l2->Fill(PTl[1],w);                       
  }
  else if	(PTl[0]<PTl[1]){  	int    nbins1 = observable_l1->GetNbinsX();
   	                                double ovfl1  = xmaxl - xmaxl/(nbins1+3);
                     			if     (PTl[1]>xmaxl)  observable_l1->Fill(ovfl1,w);
	              			else                   observable_l1->Fill(PTl[1],w);     
	              			int    nbins2 = observable_l2->GetNbinsX();
                      			double ovfl2  = xmaxl - xmaxl/(nbins2+3);
                     			if     (PTl[0]>xmaxl)  observable_l2->Fill(ovfl2,w);
	              			else                   observable_l2->Fill(PTl[0],w); 
  }      



}   




