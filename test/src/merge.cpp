#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include <cmath>
#include <iostream>
#include <filesystem>
using namespace std;

int main(int argc, char*argv[]){

  TFile   *file = NULL; 
  TH1F    *h    = NULL;         
  char    path[100];  
  char    observable[20];
  sprintf (observable, "h_%s",argv[1]);
  char    outfile[30];
  sprintf (outfile, "histos4datacards/%s.root",argv[1]);
  TFile*  risultato = new TFile(outfile, "RECREATE");
  char*   dirname   = "SR_inclusive_2017";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_full.root",argv[1]);
  file = TFile::Open(path);
  h    = (TH1F*) file -> Get(observable);
  risultato -> cd();
  risultato -> mkdir(dirname); 
  risultato -> cd(dirname);
  h         -> Write("VBS_SSWW_SM");
  file      -> Clear();
  h         -> Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_full.root",argv[1]);
  file = TFile::Open(path);
  h    = (TH1F*) file -> Get(observable);
  double h_int = h -> Integral();
  h         -> Scale(1./h_int);
  risultato -> cd();
  risultato -> cd(dirname);
  h         -> Write("BkgPdf");
  file      -> Clear();
  h         -> Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("data_obs");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("Bkg");
  file->Clear();
  h->Clear();
  
// SM for likelihood scan 

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);         
  h->Write("sm");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_quad");
  file->Clear();
  h->Clear();

// SM + cW
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_quad");
  file->Clear();
  h->Clear();

// All cW for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cW");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cW");
  file->Clear();
  h->Clear();
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_quad");
  file->Clear();
  h->Clear();

// SM + cHW
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_int_quad");
  file->Clear();
  h->Clear();

// All cHW for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHW");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHW");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHWB

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_quad");
  file->Clear();
  h->Clear();

// SM + cHWB
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_int_quad");
  file->Clear();
  h->Clear();

// All cHWB for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHWB");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHWB");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHDD

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHDD_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHDD_quad");
  file->Clear();
  h->Clear();

// SM + cHDD
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_int_quad");
  file->Clear();
  h->Clear();

// All cHDD for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHDD");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHDD");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHbox

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_quad");
  file->Clear();
  h->Clear();

// SM + cHbox
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_int_quad");
  file->Clear();
  h->Clear();

// All cHbox for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHbox");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHbox");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FERMIONIC OPERATORS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHq1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq1_quad");
  file->Clear();
  h->Clear();

// SM + cHq1
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq1_int_quad");
  file->Clear();
  h->Clear();

// All cHq1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHq1");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHq1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHq3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq3_quad");
  file->Clear();
  h->Clear();

// SM + cHq3
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq3_int_quad");
  file->Clear();
  h->Clear();

// All cHq3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHq3");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHq3");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHl1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHl1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl1_quad");
  file->Clear();
  h->Clear();

// SM + cHl1
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl1_int_quad");
  file->Clear();
  h->Clear();

// All cHl1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHl1");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHl1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHl3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHl3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl3_quad");
  file->Clear();
  h->Clear();

// SM + cHl3
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl3_int_quad");
  file->Clear();
  h->Clear();

// All cHl3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHl3");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHl3");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cqq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq1_quad");
  file->Clear();
  h->Clear();

// SM + cqq1
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq1_int_quad");
  file->Clear();
  h->Clear();

// All cqq1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq1");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cqq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq3_quad");
  file->Clear();
  h->Clear();

// SM + cqq3
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq3_int_quad");
  file->Clear();
  h->Clear();

// All cqq3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq3");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq3");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq11~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cqq11

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq11_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq11_quad");
  file->Clear();
  h->Clear();

// SM + cqq11
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq11_int_quad");
  file->Clear();
  h->Clear();

// All cqq11 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq11");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq11");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq31~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cqq31

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq31_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq31_quad");
  file->Clear();
  h->Clear();

// SM + cqq31
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq31_int_quad");
  file->Clear();
  h->Clear();

// All cqq31 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq31");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq31");
  file->Clear();
  h->Clear();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cll~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cll

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll_quad");
  file->Clear();
  h->Clear();

// SM + cll
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll_int_quad");
  file->Clear();
  h->Clear();

// All cll for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cll");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cll");
  file->Clear();
  h->Clear();
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cll1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cll1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_int_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll1_quad");
  file->Clear();
  h->Clear();

// SM + cll1
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll1_int_quad");
  file->Clear();
  h->Clear();

// All cll1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_quad_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cll1");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_1_full.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cll1");
  file->Clear();
  h->Clear();
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  risultato->Close();

}

