//
// Created by yz5083 on 08.08.22.
//

#include "SteppingAction.h"
#include "DetectorConstruction.h"
#include "EventAction.h"
#include "G4Step.hh"
#include "G4RunManager.hh"


SteppingAction::SteppingAction(EventAction *eventAction)
        : fEventAction(eventAction) {}


SteppingAction::~SteppingAction() = default;


void SteppingAction::UserSteppingAction(const G4Step *step) {
    if (!fScoringVolume) {
        const auto detConstruction = dynamic_cast<const DetectorConstruction *>(
                G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        fScoringVolume = detConstruction->GetScoringVolume();
    }

    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    if (volume != fScoringVolume) return;

    fEventAction->addDepositedEnergy(step->GetTotalEnergyDeposit());
}


