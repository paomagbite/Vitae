/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : main
 * @created     : Monday Nov 08, 2021 17:09:45 HKT
 */

#include <iostream>

#include "event_needs.h"

int main()
{
    // important that you make it so that there is a 
    // variable to use...
    World* world = new World;

    IHandler::world = world;

    int time = 0;

    for (int i = 0; i < 5; i++) {
        world->addActor();
    }
    ///*
    Location house(false);
    Location livingRoom(false);
    Location bathRoom(false);

    livingRoom.addLink(&bathRoom, 3);
   // */

    NeedEvent updateNeed(UPDATE_NEEDS);
    UpdateNeedHandler updateNeedHandler(&updateNeed);

    updateNeed.add(&updateNeedHandler);

    NeedEvent eat(EAT);
    EatHandler eatHandler(&eat);
    eat.add(&eatHandler);

    NeedEvent sleep(SLEEP);
    SleepHandler sleeptHandler(&sleep);
    sleep.add(&sleeptHandler);

    world->spit();
    std::cout << world << std::endl;
    std::cout << updateNeedHandler.world << std::endl;


    for(;time < 20000; time++) {

        for (int i = 0; i < world->actors.size(); i++) {
            
            updateNeed.notify();
            if (world->curActor->needs.hunger < 10) {
                eat.notify();
                std::cout << "Actor ate!\n";
            }
            if (world->curActor->needs.energy < 10) {
                sleep.notify();
                std::cout << "Actor sleept!\n";
            }
            world->nextActor();
        }
    }


    

    
    return 0;
}

