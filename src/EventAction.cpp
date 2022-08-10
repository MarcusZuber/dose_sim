//
// Created by yz5083 on 08.08.22.
//

#include "EventAction.h"
#include "RunAction.h"

EventAction::EventAction(RunAction* runAction)
        : fRunAction(runAction)
{}


EventAction::~EventAction()
= default;


void EventAction::BeginOfEventAction(const G4Event*)
{
    depositedEnergy = 0.;
}


void EventAction::EndOfEventAction(const G4Event*)
{
    fRunAction->addDepositedEnergy(depositedEnergy);
}