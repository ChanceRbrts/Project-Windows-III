//
//  Homing.h
//  Project_Music
//
//  Created by Chance Roberts on 12/4/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef Homing_h
#define Homing_h
#include "Instance.h"
class Homing : public Instance{
    float flyingTime;
    float R, G, B;
public:
    Homing(float X, float Y, float bpm, float beatStart, float beatEnd, float r = 255, float g = 0, float b = 255);
    void updateWithPlayer(Instance* i, double deltaTime);
    std::vector<std::string> draw();
    void setF(std::string get, float set);
};
#endif /* Homing_h */
