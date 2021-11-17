/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : event_needs
 * @created     : Tuesday Nov 09, 2021 13:44:02 HKT
 */

#pragma once
#ifndef SRC_EVENT_NEEDS_H

#define SRC_EVENT_NEEDS_H

#include "event.h"
#include "actor.h"

class NeedUpdate : public Event<NeedUpdate> {
public:
    NeedUpdate(Actor* curActor) {
        this->actor_ = curActor;
    }
    
    void run() {
        this->actor_->needs.hunger -= 0.32;
        this->actor_->needs.energy -= 0.104;
    }

private:
    Actor* actor_;
};

#endif /* end of include guard SRC_EVENT_NEEDS_H */
