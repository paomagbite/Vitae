/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : location
 * @created     : Friday Nov 12, 2021 14:10:53 HKT
 */

#include "location.h"

Location::Location(bool outdoor)
{
    this->outdoor_ = outdoor;
};

bool Location::locPresentInLinks_(Location* checkLocation) {
    for (int i = 0; i < checkLocation->links.size(); i++) {
        if(checkLocation->links[i]->loc == this) {
            return true;
        }
    }
    return false;
}

void Location::addLink(Location* toLocation, int distance, bool addToOtherLoc) {
        this->links.push_back(new Link(toLocation, distance));
        
        if (!locPresentInLinks_(toLocation) && addToOtherLoc) {
            toLocation->addLink(this, distance);
        }
}
