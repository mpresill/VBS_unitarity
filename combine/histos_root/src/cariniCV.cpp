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

 using namespace std;
 
int main(int argc, char*argv[]){
 
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location 
  gStyle->SetTitleY(0.96); //title Y location 
  gStyle->SetPaintTextFormat(".2f");

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");
 tdrStyle->SetCanvasBorderMode(0);
 tdrStyle->SetCanvasColor(kWhite);
 tdrStyle->SetCanvasDefH(600); //Height of canvas
 tdrStyle->SetCanvasDefW(600); //Width of canvas
 tdrStyle->SetCanvasDefX(0);   //POsition on screen
 tdrStyle->SetCanvasDefY(0);
 //For the Pad:
 tdrStyle->SetPadBorderMode(0);
 //tdrStyle->SetPadBorderSize(Width_t size = 1);
 tdrStyle->SetPadColor(kWhite);
 tdrStyle->SetPadGridX(false);
 tdrStyle->SetPadGridY(false);
 tdrStyle->SetGridColor(0);
 tdrStyle->SetGridStyle(3);
 tdrStyle->SetGridWidth(1);
 //For the frame:
 tdrStyle->SetFrameBorderMode(0);
 tdrStyle->SetFrameBorderSize(1);
 tdrStyle->SetFrameFillColor(0);
 tdrStyle->SetFrameFillStyle(0);
 tdrStyle->SetFrameLineColor(1);
 tdrStyle->SetFrameLineStyle(1);
 tdrStyle->SetFrameLineWidth(1);
 //For the histo:
 tdrStyle->SetHistFillColor(0);
 //tdrStyle->SetHistFillStyle(0);
 tdrStyle->SetHistLineColor(1);
 tdrStyle->SetHistLineStyle(0);
 tdrStyle->SetHistLineWidth(1);
 //tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
 //tdrStyle->SetNumberContours(Int_t number = 20);
 //tdrStyle->SetEndErrorSize(0);
 tdrStyle->SetErrorX(0.);
//tdrStyle->SetErrorMarker(20);
 tdrStyle->SetMarkerStyle(20);
 //For the fit/function:
 tdrStyle->SetOptFit(1);
 tdrStyle->SetFitFormat("5.4g");
 //tdrStyle->SetFuncColor(1);
 tdrStyle->SetFuncStyle(1);
 tdrStyle->SetFuncWidth(1);
 //For the date:
 tdrStyle->SetOptDate(0);
 //tdrStyle->SetDateX(Float_t x = 0.01);
 //tdrStyle->SetDateY(Float_t y = 0.01);
 //For the statistics box:
 tdrStyle->SetOptFile(0);
 tdrStyle->SetOptStat(""); // To display the mean and RMS:   SetOptStat("mr");
 //tdrStyle->SetStatColor(kWhite);
 tdrStyle->SetStatColor(kGray);
 tdrStyle->SetStatFont(42);
 tdrStyle->SetTextSize(11);
 tdrStyle->SetTextAlign(11);
 tdrStyle->SetStatTextColor(1);
 tdrStyle->SetStatFormat("6.4g");
 tdrStyle->SetStatBorderSize(0);
 tdrStyle->SetStatX(1.); //Starting position on X axis
 tdrStyle->SetStatY(1.); //Starting position on Y axis
 tdrStyle->SetStatFontSize(0.025); //Vertical Size
 tdrStyle->SetStatW(0.25); //Horizontal size 
 //tdrStyle->SetStatStyle(Style_t style = 1001)
//Margins:
 tdrStyle->SetPadTopMargin(0.095);
 tdrStyle->SetPadBottomMargin(0.125);
 tdrStyle->SetPadLeftMargin(0.14);
 tdrStyle->SetPadRightMargin(0.1);
 
  
  // For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  tdrStyle->SetTitleH(0.045); // Set the height of the title box
  //tdrStyle->SetTitleW(0); // Set the width of the title box
  tdrStyle->SetTitleX(0.20); // Set the position of the title box
  tdrStyle->SetTitleY(1.0); // Set the position of the title box
  //tdrStyle->SetTitleStyle(Style_t style = 1001);
  tdrStyle->SetTitleBorderSize(0);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(0); 
  tdrStyle->SetPadTickY(0);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  tdrStyle->cd();
///////////////// FINE CONFIG
 

   char observable[20];
   sprintf(observable, "%s",argv[1]);
   char eftop[20];
   sprintf(eftop, "%s",argv[2]);
 
   
   const char *part1 = "_SMvsSM+";
   const char *part2 = "_";
   const char *part3 = "VBS_SSWW_SM_";
   const char *part4 = ".png";
   const char *part5 =  "SM_";
   
   
   char name[50];
   sprintf(name,"histos4datacards/CvsV/%s/%s_%s.png",argv[1],argv[2],argv[1]);
   
   char legint[50];
   sprintf(legint, "SM + %s lin",argv[2]);
   
   char legquad[50];
   sprintf(legquad, "SM + %s quad",argv[2]);
   
   char legintquad[50];
   sprintf(legintquad, "SM + %s lin + quad",argv[2]);


//-------------------------------------------------------------------------------------
   
   TFile *f;
   TH1F *h1;
   TH1F *h2;
   TH1F *h3;
   TH1F *h4;
   
   char infile[50];
   sprintf(infile, "histos4datacards/%s.root",argv[1]);

   char histint[100];
   sprintf(histint, "SR_inclusive_2017/VBS_SSWW_SM_%s_int",argv[2]);

   char histquad[100];
   sprintf(histquad, "SR_inclusive_2017/VBS_SSWW_SM_%s_quad",argv[2]);
   
   char histintquad[100];
   sprintf(histintquad, "SR_inclusive_2017/VBS_SSWW_SM_%s_int_quad",argv[2]);
  
   f = TFile::Open(infile);
   h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
   h1->Sumw2(); 
   double w1 = h1->Integral();
   h1->Scale(1./w1);
   
   h2 = (TH1F*) f->Get(histint);
   h2->Sumw2();
   double w2 = h2->Integral();
   h2->Scale(1./w2);

   h3 = (TH1F*) f->Get(histquad);
   h3->Sumw2();
   double w3 = h3->Integral();
   h3->Scale(1./w3);
   
   h4 = (TH1F*) f->Get(histintquad);
   h4->Sumw2();
   double w4 = h4->Integral();
   h4->Scale(1./w3);
   
   
   h1->SetLineColor(kYellow-9);
   h1->SetLineWidth(2);
   h1->SetFillColor(kYellow-9),
   h1->SetFillStyle(3001);
   
   h2->SetLineColor(kOrange-3);
   h2->SetLineWidth(2);
   h2->SetLineStyle(2);
   
   h3->SetLineColor(kBlue);
   h3->SetLineWidth(2);
   h3->SetLineStyle(2);
   
   h4->SetLineColor(kRed);
   h4->SetLineWidth(2);

	TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
	TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
	c1_1->Draw();
	c1_1->cd();
	c1_1->SetTopMargin(0.1);
	c1_1->SetBottomMargin(0.15);
	c1_1->SetRightMargin(0.045);
	c1_1->SetLeftMargin(0.15);
	
	if(strcmp(argv[1],"PT_el")==0||strcmp(argv[1],"PT_mu")==0||strcmp(argv[1],"PT_ta")==0||strcmp(argv[1],"PT_j")==0||strcmp(argv[1],"mll")==0||strcmp(argv[1],"mjj")==0)
  	  { 
	    gPad->SetLogy(); 
	  }
	
	
	
        h1->Draw("HISTO");
        h2->Draw("histsame");
        h3->Draw("histsame");
        h4->Draw("histsame");

	h1->GetXaxis()->SetTitleOffset(1.);
	h1->GetXaxis()->SetLabelSize(0.045);
	h1->GetXaxis()->SetTitleSize(0.06);
	h1->GetYaxis()->SetTitleOffset(1.2);
	h1->GetYaxis()->SetTitle("Normalized Events");

	h1->GetXaxis()->SetTitle(observable);
	h1->GetYaxis()->SetLabelSize(0.045);
	h1->GetYaxis()->SetTitleSize(0.06);

        TLatex latexLabel;
	latexLabel.SetTextSize(0.04);
	latexLabel.SetNDC();
	latexLabel.DrawLatex(0.16, 0.93, "CMS   100 fb^-1");
	TLatex latexLabel2;
	latexLabel2.SetTextSize(0.04);

	latexLabel2.SetNDC();
	latexLabel2.DrawLatex(0.75, 0.93, "13 TeV");

 TLegend *leg = new TLegend(0.68, 0.75, 0.99, 0.89);
 leg->SetShadowColor(0);
 leg->SetBorderSize(1);
 leg->SetTextSize(0.03);
 leg->SetFillColor(0);
 leg->AddEntry(h1, "SM",  "f");
 leg->AddEntry(h2, legint, "l");
 leg->AddEntry(h3, legquad, "l");
 leg->AddEntry(h4, legintquad, "l");
	

 leg->Draw();

 c1->SaveAs(name);
 int i=0;
 return i;
}
