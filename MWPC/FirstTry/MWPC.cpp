#include <iostream>

#include "TCanvas.h"
#include "TSystem.h"
#include "TObject.h"
#include <TApplication.h>

#include "MediumMagboltz.hh"
#include "FundamentalConstants.hh"
#include "ComponentAnalyticField.hh"
#include "GeometrySimple.hh"
//#include "SolidTube.hh"
#include "SolidBox.hh"
//#include "Sensor.hh"
//#include "AvalancheMC.hh"
//#include "ViewSignal.hh"
//#include "PlottingEngineRoot.hh"
#include "ViewGeometry.hh"
//#include "AvalancheMicroscopic.hh"
#include "Plotting.hh"
//#include "TrackHeed.hh"
//#include "ViewDrift.hh"
//#include "Random.hh"
#include "TH1.h"
#include "TF1.h"
#include "TFile.h"


#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace Garfield;

int main(int argc, char * argv[]){


  TApplication app("app", &argc, argv);
  plottingEngine.SetDefaultStyle();

  // Load the Magboltz gas file
  MediumMagboltz* gas = new MediumMagboltz();
  gas->LoadGasFile("ar_90_c4h10_10_B2T_90deg.gas");

  // 
  // one anode plane between 2 cathode planes
  //

  // Units given in [cm]
  const double dAnode = 0.001; // Anode wire diameter
  const double dCathode = 0.005; // Cathode wire diameter
  const double pitch = 0.2; // Total height
  const double planeDistance = 0.635; // Pitch
  const double totalHeight = 2*planeDistance;

  // Electrode potentials
  const double vAnode = 2700.;
  const double vCathode = 0.;

  const double width = 10.;
  const double length = 10.;

  GeometrySimple* geo = new GeometrySimple(); 
  SolidBox* box = new SolidBox(0.,0., 0., width/2.0, totalHeight/2.0, length/2.0); 
  geo->AddSolid(box, gas); 

  // Create a viewer.
  ViewGeometry* view = new ViewGeometry();
  //keeps crashing over viewgeometry
  // Set the pointer to the geometry.
  //view->SetGeometry(geo);
 // view->Plot();

// std::cout << " test : " << std::endl;

 double test;
 std::cin >> test;
 


  return 0;

}
