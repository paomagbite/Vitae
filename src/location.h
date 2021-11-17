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
    Location(bool outdoor = 0);

    // adds link, default is to add link in the desitnation location as well
    void addLink(Location* toLocation, int distance, bool addToOtherLoc = 1); 


    //get if indoor or outdoor so player can see weather if outside
    bool getIfOutdoor() {
        return outdoor_;
    }
    
    // contains location links to other locations
    std::vector<Link*> links;

private:
    bool outdoor_;

    // private func to check if location is in desintation links
    bool locPresentInLinks_(Location* loc);
    
};

struct Link {
    const Location* loc;

    const int distance;
    const bool outdoor;

    Link(Location* loc, int distance) : loc(loc), distance(distance), outdoor(loc->getIfOutdoor()) {}
};


#endif /* end of include guard SRC_LOCATION_H */

