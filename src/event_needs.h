/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : event_needs
 * @created     : Tuesday Nov 09, 2021 13:44:02 HKT
 */

#pragma once
#ifndef SRC_EVENT_NEEDS_H

#define SRC_EVENT_NEEDS_H

#include "event.h"
// base class for all events regarding needs
class NeedEvent : public IEvent {
public:
    // must input the ID for this to work
    NeedEvent(int ID) : eventID(ID) {}
    // implements the specific add handler
    void add(IHandler* iHandler) override {
        this->handlers.push_back(iHandler);
    }
    // implemnts the specific remove handler
    void remove(IHandler* iHandler) override {
    handlers.erase(std::remove(handlers.begin(), handlers.end(), iHandler), handlers.end());
    }

    // overrides virtual notify and implements event specific notify
    void notify() override {
        for (int i = 0; i < handlers.size(); i++) {
            this->handlers[i]->update();
        }
        // std::cout << "I'm notifying now\n";
    }

    Actor* actor;

    std::vector<IHandler*> handlers;

    const int eventID;
};

//base class for need handlers
class NeedHandler : public IHandler {
public:
    // adds the event to the handler so it can access the necessary data
    NeedEvent* event;
};

// update need handler contains need update logic
class UpdateNeedHandler : public NeedHandler {
public:
    UpdateNeedHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }

    void update() {
        this->world->curActor->needs.hunger -= 0.32;
        this->world->curActor->needs.energy -= 0.104;
    }

    NeedEvent* event;
};

class EatHandler : public NeedHandler {
public:
    EatHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }

    void update() {
        this->world->curActor->needs.hunger = 100;
    }
};

class SleepHandler : public NeedHandler {
public:
    SleepHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }
    void update() {
        this->world->curActor->needs.energy = 100;
    }
};


#endif /* end of include guard SRC_EVENT_NEEDS_H */
