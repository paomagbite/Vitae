/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : needs
 * @created     : Monday Nov 08, 2021 17:41:33 HKT
 */

#pragma once
#ifndef SRC_NEEDS_H

#define SRC_NEEDS_H


struct Needs {
    float hunger = 100;
    float energy = 100;
    float toilet = 100;
    float hygiene = 100;
    float arousal = 100;

    int timeLastUpdate = 0;
};


#endif /* end of include guard SRC_NEEDS_H */

