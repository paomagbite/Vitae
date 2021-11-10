/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : event
 * @created     : Tuesday Nov 09, 2021 13:14:55 HKT
 */

#pragma once
#ifndef SRC_EVENT_H

#define SRC_EVENT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "world.h"
#include "event_types.h"

// Observer Interface
//static int observer_id;
class IHandler {
public:
  virtual void update() = 0;

    static World* world;
};

World* IHandler::world = new World;

// Observable interface
class IEvent {
public:
  virtual void add(IHandler* iHandler) = 0;

  virtual void remove(IHandler* iHandler) = 0;

  virtual void notify() = 0;
};
#endif /* end of include guard SRC_EVENT_H */

