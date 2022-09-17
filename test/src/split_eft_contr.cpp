//#include "TDRStyle.h "
#include <TROOT.h>
#include <TStyle.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TClass.h>
#include <iostream>

 using namespace std;
 
int main(int argc, char*argv[]){

   char observable[20];
   sprintf(observable, "%s",argv[1]);
   char eftop[20];
   sprintf(eftop, "%s",argv[2]);  
   char histogram[20];
   sprintf(histogram, "h_%s",argv[1]);  // in teoria è lo stesso per tutti
   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   
   
   /* Wilson coefficient = 1 */
   char infile_1[50];
   sprintf(infile_1, "histos/%s/%s_1_full.root",argv[1],argv[2]);
   TFile f_1(infile_1);
   f_1.ls();
   TH1F *h_1;
   gDirectory->GetObject(histogram, h_1);
   
   /* Wilson coefficient = -1 */
   char infile_m1[50];
   sprintf(infile_m1, "histos/%s/%s_m1_full.root",argv[1],argv[2]);
   TFile f_m1(infile_m1);
   f_m1.ls();
   TH1F *h_m1;
   gDirectory->GetObject(histogram, h_m1);
   
   /* Standard Model */
   char infile_0[50];
   sprintf(infile_0, "histos/%s/SM_full.root",argv[1]);
   TFile f_0(infile_0);
   f_0.ls();
   TH1F *h_0;
   gDirectory->GetObject(histogram, h_0);
   
   /* EFT single contribution */
   double  xmin    = h_1->GetXaxis()->GetXmin();
   double  xmax    = h_1->GetXaxis()->GetXmax();
   int     bins    = h_1->GetXaxis()->GetNbins();
   TH1F    *h_quad = new TH1F(histogram,"",bins,xmin,xmax);
   TH1F    *h_int  = new TH1F(histogram,"",bins,xmin,xmax);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  double n_1, n_m1, n_0, n_quad, n_int;
  
  for(int i=0; i<bins; i++){	n_1  = h_1->GetBinContent(i);
                                n_m1 = h_m1->GetBinContent(i);
                                n_0  = h_0->GetBinContent(i);   
                                n_quad = 0.5*(n_1 + n_m1) - n_0;
                                n_int = 0.5*(n_1 - n_m1);
                               
                                h_quad -> SetBinContent(i,n_quad);
                                h_int  -> SetBinContent(i,n_int);
                                 
                                // cout << "Events for cW = 1: "  << n_1  << endl;  
                                // cout << "Events for cW = -1: " << n_m1 << endl;  
                                // cout << "Events for SM: "      << n_0  << endl;
                                // cout << "Events for quadratic contribution: " << n_quad << endl;
                                // cout << "Events for linear contribution: "    << n_int  << endl;
                                // cout << endl;                                                                 
  } 
    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile2[50];
  sprintf    (outfile2, "histos/%s/%s_quad_full.root",argv[1],argv[2]);
  TFile*     risultati2=new TFile(outfile2, "RECREATE");
  h_quad     -> Write();
  risultati2 -> Close();
  
cout << "Linear contribution  stored in " << outfile2 << endl;
  
  char outfile1[50];
  sprintf    (outfile1, "histos/%s/%s_int_full.root",argv[1],argv[2]);
  TFile*     risultati1=new TFile(outfile1, "RECREATE");
  h_int      -> Write();
  risultati1 -> Close();  

cout << "Quadratic contribution  stored in " << outfile1 << endl;
cout << " " << endl;
cout << "~~~~~~~~~~~~~~" << endl;
cout << " " << endl;

}
