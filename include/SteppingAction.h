//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_STEPPINGACTION_H
#define DOSE_STEPPINGACTION_H

#include <G4UserSteppingAction.hh>
#include <G4LogicalVolume.hh>

class EventAction;

class SteppingAction: public G4UserSteppingAction{
public:
    explicit SteppingAction(EventAction* eventAction);
    ~SteppingAction() override;
    void UserSteppingAction(const G4Step*) override;

private:
    EventAction* fEventAction = nullptr;
    G4LogicalVolume* fScoringVolume = nullptr;
};


#endif //DOSE_STEPPINGACTION_H
