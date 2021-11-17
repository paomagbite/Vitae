/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : world
 * @created     : Wednesday Nov 10, 2021 15:19:21 HKT
 */

#include "world.h"

World::World() {
    actors.push_back(new Actor);
    curActor = actors[0];

    addLocation();
    addLocation();

    locations[0]->addLink(locations[1], 10);
}

void World::addActor() {
    actors.push_back(new Actor());
}

void World::nextActor() {
    // this loop is important
    if (!(curActorSpot == actors.size())){
        curActor = actors[curActorSpot];
        curActorSpot++;
    }
    else {
        curActor = actors[0];
        curActorSpot = 0;
    }
}

void World::addLocation() {
    locations.push_back(new Location);
}
