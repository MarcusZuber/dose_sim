//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_PHYSICSLIST_H
#define DOSE_PHYSICSLIST_H

#include <G4VModularPhysicsList.hh>

class PhysicsList: public G4VModularPhysicsList{
public:
    PhysicsList();
    ~PhysicsList() override = default;
};


#endif //DOSE_PHYSICSLIST_H
