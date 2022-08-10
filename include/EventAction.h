//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_EVENTACTION_H
#define DOSE_EVENTACTION_H


#include "G4UserEventAction.hh"
#include <globals.hh>


class RunAction;

class EventAction : public G4UserEventAction
{
public:
    explicit EventAction(RunAction* runAction);
    ~EventAction() override;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;

    void addDepositedEnergy(G4double energy) { depositedEnergy += energy; }

private:
    RunAction* fRunAction = nullptr;
    G4double   depositedEnergy = 0.;
};




#endif //DOSE_EVENTACTION_H
