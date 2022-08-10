//
// Created by yz5083 on 08.08.22.
//

#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>
#include <G4VisExecutive.hh>
#include "DetectorConstruction.h"
#include "PhysicsList.h"
#include "ActionInitialization.h"
#include "RunAction.h"
#include <G4SystemOfUnits.hh>
#include <G4NistManager.hh>


int main(int argc, char** argv){
    auto sampleMaterial =  G4NistManager::Instance()->FindOrBuildMaterial("G4_TISSUE_SOFT_ICRP");
    int numPhotons = 1E5;
    char runCommand[80];
    sprintf(runCommand, "/run/beamOn %i", numPhotons);


    auto runManager = new G4RunManager();
    runManager->SetUserInitialization(new DetectorConstruction(sampleMaterial));
    runManager->SetUserInitialization(new PhysicsList());
    runManager->SetUserInitialization(new ActionInitialization(2*mm, 1*mm, 30.4*keV));
    runManager->Initialize();

    auto ui = new G4UIExecutive(argc, argv);
    auto visManager = new G4VisExecutive();
    visManager->Initialise();

    auto uiManager = G4UImanager::GetUIpointer();

    uiManager->ApplyCommand(runCommand);
    //uiManager->ApplyCommand("/tracking/storeTrajectory 1");
    //uiManager->ApplyCommand("/vis/open OGL");
    //uiManager->ApplyCommand("/vis/drawVolume");
    //uiManager->ApplyCommand("/vis/scene/add/trajectories");
    //uiManager->ApplyCommand("/vis/scene/add/hits");

//uiManager->ApplyCommand(runCommand);

    ui->SessionStart();

    delete visManager;
    delete ui;
    delete runManager;
}