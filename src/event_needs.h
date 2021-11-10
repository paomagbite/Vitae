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
    void notify() override {};
    void notify(Actor* actor) {
        this->actor = actor;
        for (int i = 0; i < handlers.size(); i++) {
            this->handlers[i]->update();
        }
        // std::cout << "I'm notifying now\n";
    }

    Actor* actor;

    std::vector<IHandler*> handlers;

    const int eventID;
};

class NeedHandler : public IHandler {
public:
    // adds the event to the handler so it can access the necessary data
    NeedEvent* event;
};

class UpdateNeedHandler : public NeedHandler {
public:
    UpdateNeedHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }

    void update() {
        this->event->actor->needs.hunger -= 0.32;
        this->event->actor->needs.energy -= 0.104;
    }

    NeedEvent* event;
};

class EatHandler : public NeedHandler {
public:
    EatHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }

    void update() {
        this->event->actor->needs.hunger = 100;
    }
};

class SleepHandler : public NeedHandler {
public:
    SleepHandler(NeedEvent* needEvent) {
        this->event = needEvent;
    }
    void update() {
        this->event->actor->needs.energy = 100;
    }
};


#endif /* end of include guard SRC_EVENT_NEEDS_H */
