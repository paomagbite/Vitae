/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : main
 * @created     : Monday Nov 08, 2021 17:09:45 HKT
 */

#include <iostream>

#include "event_needs.h"
#include "world.h"

int main()
{

    World world;

    world.addActor();

    std::cout << "Link exists: " << world.locations[1]->links[0]->distance << "\n";

    NeedUpdate needUpdate(world.curActor);


    needUpdate.run();

    
    return 0;
}

