#include <iostream>

#include "TCanvas.h"
#include "TSystem.h"
#include "TObject.h"
#include <TApplication.h>

#include "MediumMagboltz.hh"
#include "FundamentalConstants.hh"
#include "ComponentAnalyticField.hh"
#include "GeometrySimple.hh"
#include "SolidTube.hh"
#include "Sensor.hh"
#include "AvalancheMC.hh"
#include "ViewSignal.hh"
#include "TH1.h"
#include "TF1.h"
#include "Plotting.hh"
#include "AvalancheMicroscopic.hh"
#include "ViewGeometry.hh"
#include "TrackHeed.hh"
#include "ViewDrift.hh"
#include "Random.hh"
#include "TFile.h"
//#include "PlottingEngineRoot.hh"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace Garfield;

int main(int argc, char * argv[]) {

  //Set Output file
  //std::cout << "Creating output file " << "output.root" << std::endl;
//  TFile *fout = new TFile ( "output.root", "RECREATE");
//  if ( fout->IsZombie() )
 //// {
 //   std::cout << "**ERROR! Cannot open file [" << "output.root" << "]" << std::endl;
// //   return 1;
//  }
  

  TApplication app("app", &argc, argv);
 // PlottingEngineRoot* plottingEngine = new PlottingEngineRoot();
  plottingEngine.SetDefaultStyle();

 std::cout << "Run example 1 " << std::endl;
 ComponentAnalyticField* cmp = new ComponentAnalyticField();

  // Wire radius [cm]
  const double rWire = 25.e-4;
  // Outer radius of the tube [cm]
  const double rTube = 1.46;
  // Half-length of the tube [cm]
  const double lTube = 10.;
  GeometrySimple* geo = new GeometrySimple();
  // Make a tube
  // (centered at the origin, inner radius: rWire, outer radius: rTube).
  SolidTube* tube = new SolidTube(0., 0., 0., rWire, rTube, lTube);
  // Add the solid to the geometry, together with the medium inside.
  MediumMagboltz* gas = new MediumMagboltz();
  gas->LoadGasFile("ar_93_co2_7.gas");

  // Make a gas medium
 // MediumMagboltz* gas = new MediumMagboltz();
  //gas->LoadIonMobility("../../Data/IonMobility_Ar+_Ar.txt");

  geo->AddSolid(tube, gas);
  // Pass a pointer to the geometry class to the component.
  cmp->SetGeometry(geo);

  // Voltages
  const double vWire = 3270.;
  const double vTube = 0.;
  // Add the wire in the center.
  cmp->AddWire(0., 0., 2 * rWire, vWire, "s");
  // Add the tube.
  cmp->AddTube(rTube, vTube, 0, "t");

  std::cout << " ******* geometry and voltages set ********** " << std::endl;

  cmp->AddReadout("s");

  Sensor* sensor = new Sensor();
  // Calculate the electric field using the Component object cmp.
  sensor->AddComponent(cmp);
  // Request signal calculation for the electrode named "s",
  // using the weighting field provided by the Component object cmp.
  sensor->AddElectrode(cmp, "s");

  const double tMin = 0.;
  const double tMax = 2.;
  const double tStep = 0.02;
  const int nTimeBins = int((tMax - tMin) / tStep);
  sensor->SetTimeWindow(0., tStep, nTimeBins);

  AvalancheMC* aval = new AvalancheMC();
  //aval->EnableDebugging();
  aval->SetSensor(sensor);
  // Switch on signal calculation.
  aval->EnableSignalCalculation();
  // Do the drift line calculation in time steps of 50 ps.
  aval->SetTimeSteps(0.05);
  // Starting position [cm] and time [ns] of the initial electron.
  // The electron is started at 100 micron above the wire.
  const double x0 = 0.;
  const double y0 = rWire + 100.e-4;

  const double z0 = 0.;
  const double t0 = 0.;
  // Simulate an avalanche.
  aval->AvalancheElectron(x0, y0, z0, t0);

  ViewSignal* signalView = new ViewSignal();
  signalView->SetSensor(sensor);
  signalView->PlotSignal("s");

   // Create a viewer.
  ViewGeometry* view = new ViewGeometry();
  // Set the pointer to the geometry.
 // view->SetGeometry(geo);
 // view->Plot();

 std::cout << " test : " << std::endl;
 double test;
 std::cin >> test ;


 return 0;
  //fout->Write();
  //delete fout;
}
