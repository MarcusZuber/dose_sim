//
// Created by yz5083 on 08.08.22.
//

#include <G4AccumulableManager.hh>
#include <G4RunManager.hh>
#include <G4Run.hh>
#include "RunAction.h"
#include "PrimaryGenerator.h"
#include "DetectorConstruction.h"
#include <G4SystemOfUnits.hh>


void RunAction::EndOfRunAction(const G4Run* run) {
    auto numEvents = run->GetNumberOfEvent();
    if (numEvents==0)
        return;
    G4AccumulableManager::Instance()->Merge();
    auto total_energy = E_dep.GetValue();
    auto primaryGenerator = dynamic_cast<const PrimaryGenerator *>(
            G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());

    auto beamArea = primaryGenerator->getBeamArea();

    const auto detConstruction = dynamic_cast<const DetectorConstruction *>(
            G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    auto sampleMass = detConstruction->GetScoringVolume()->GetMass();

    auto target_flux_density = 1.6E9 / (mm * mm);
    auto simulated_flux_density = (numEvents / beamArea) / (mm*mm);

    G4cout << "Number of primary photons: " << numEvents << G4endl;
    G4cout << "Photons / mm^2: " << simulated_flux_density << G4endl;
    G4cout << "Total deposited Energy (J): " << total_energy / joule << G4endl;
    G4cout << "Sample mass (kg): " << sampleMass/kg << G4endl;
    G4cout << "Total dose (J/kg): " << total_energy / sampleMass / (joule/kg) << G4endl;
    G4cout << "fraction of target and sim flux density: " << target_flux_density/simulated_flux_density << G4endl;
    G4cout << "Total dose rate at 1.6E9 photons/mm^2/s (J/kg/s): " << total_energy / sampleMass * (target_flux_density/simulated_flux_density) / (joule/kg) << G4endl;



}

RunAction::RunAction() {
    G4AccumulableManager::Instance()->RegisterAccumulable(E_dep);
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4RunManager::GetRunManager()->SetRandomNumberStore(false);
    G4AccumulableManager::Instance()->Reset();

}

void RunAction::addDepositedEnergy(G4double energy) {
    E_dep += energy;
}
