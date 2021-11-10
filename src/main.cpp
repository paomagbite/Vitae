/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : main
 * @created     : Monday Nov 08, 2021 17:09:45 HKT
 */

#include <iostream>

#include "event_needs.h"

int main()
{
    std::vector<Actor*> actors;

    std::vector<NeedEvent*> events;

    int time = 0;

    for (int i = 0; i < 5; i++) {
        actors.push_back(new Actor(time));
    }

    events.push_back(new NeedEvent(UPDATE_NEEDS));
    UpdateNeedHandler updateNeedHandler(events[0]);
    NeedEvent updateNeed(UPDATE_NEEDS);
    // UpdateNeedHandler updateNeedHandler(&updateNeed);

    updateNeed.add(&updateNeedHandler);

    NeedEvent eat(EAT);
    EatHandler eatHandler(&eat);
    eat.add(&eatHandler);

    NeedEvent sleep(SLEEP);
    SleepHandler sleeptHandler(&sleep);
    sleep.add(&sleeptHandler);


    for(;time < 2000; time++) {

        for (int i = 0; i < actors.size(); i++) {
            updateNeed.notify(actors[i]);

            if (actors[i]->needs.hunger < 10) {
                eat.notify(actors[i]);
                std::cout << "Actor ate!\n";
            }
            if (actors[i]->needs.energy < 10) {
                sleep.notify(actors[i]);
                std::cout << "Actor sleept!\n";
            }
        }
    }


    

    
    return 0;
}

