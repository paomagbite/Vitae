/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : location
 * @created     : Wednesday Nov 10, 2021 19:48:52 HKT
 */

#pragma once
#ifndef SRC_LOCATION_H

#define SRC_LOCATION_H

#include <vector>

#include "actor.h"

struct Link;
class Location {
public:
    Location(bool outdoor = 1);

    void addLink(Location* toLocation, int distance, bool addToOtherLoc = 1); 


    bool getIfOutdoor() {
        return outdoor_;
    }

    std::vector<Link*> links;

private:
    bool outdoor_;


    bool locPresentInLinks_(Location* loc);
    
};

struct Link {
    const Location* loc;

    const int distance;
    const bool outdoor;

    Link(Location* loc, int distance) : loc(loc), distance(distance), outdoor(loc->getIfOutdoor()) {}
};


#endif /* end of include guard SRC_LOCATION_H */

