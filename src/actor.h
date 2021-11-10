/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : actor
 * @created     : Monday Nov 08, 2021 21:08:33 HKT
 */

#pragma once
#ifndef SRC_ACTOR_H

#define SRC_ACTOR_H

#include "needs.h"

class Actor {
public:
    Actor(int time) {
        this->needs.timeLastUpdate = time;
    }
    Needs needs;

    int eventStart = 0;
    int eventDuration = 0;

    int eventID = 0;
};


#endif /* end of include guard SRC_ACTOR_H */

