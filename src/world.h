/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : world
 * @created     : Wednesday Nov 10, 2021 15:03:18 HKT
 */

#pragma once
#ifndef SRC_WORLD_H

#define SRC_WORLD_H

#include <iostream>
#include <vector>

#include "actor.h"

// class holding all game data
class World {
public:
    World();
    // adds new actor to the game
    void addActor();
    // void removeActor(); // not going to use this one for now
   
    //makes the current actor processed the next one in queue
    void nextActor();

    void spit() {
        std::cout << "Hey\n";
    }

    std::vector<Actor*> actors;

    Actor* curActor;
    int curActorSpot = 0;
};


#endif /* end of include guard SRC_WORLD_H */

