//
//  Solid.h
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef Solid_h
#define Solid_h
#include "Instance.h"
class Solid : public Instance{
public:
    Solid(float X, float Y);
    Solid(float X, float Y, float W, float H);
    std::vector<std::string> draw();
};

#endif /* Solid_h */
