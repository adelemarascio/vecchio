#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TMatrixD.h"
#include "TFitResult.h"
#include "TFile.h"


void setStyle(){
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}
void grafico(){
 
  // Instance of the graph
  char filename[20];
  std::cin >> filename;
  TGraph * graph =new TGraph (filename, "%lg %lg");
    
  graph->SetTitle("Diffrazione da fenditura ;Distanza (mm);Ampiezza");
  // Cosmetics
  graph->SetMarkerStyle(kOpenCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);
  // The canvas on which we'll draw the graph
  TCanvas *mycanvas = new TCanvas();
  // Define a linear function
  TF1 *f = new TF1("diffraction","",.5,10.5);
  // Let's make the function line nicer
  f->SetLineColor(kRed); f->SetLineStyle(2);
  // Fit it to the graph and draw it
  graph->Fit(f);

  // Draw the graph !
  gStyle->SetOptFit(111);
  graph ->Fit(f);
  gStyle ->SetOptFit(111);
  graph ->Draw("APE");
}