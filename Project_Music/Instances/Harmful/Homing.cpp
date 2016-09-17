//
//  Homing.cpp
//  Project_Music
//
//  Created by Chance Roberts on 12/4/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <iostream>
#include "Homing.h"
#include <tgmath.h>

Homing::Homing(float X, float Y, float bpm, float beatStart, float beatEnd, float r, float g, float b) : Instance(X,Y,1){
    x = X;
    y = Y;
    flyingTime = 60*(beatEnd-beatStart)/bpm;
    w = 8;
    h = 8;
    R = r;
    G = g;
    B = b;
    harmful = true;
    index = "Homing";
}

void Homing::updateWithPlayer(Instance *i, double deltaTime){
    Instance::updateWithPlayer(i, deltaTime);
    float prevTime = flyingTime;
    flyingTime -= deltaTime;
    if (prevTime >= 0){
        dX = 0;
        dY = 0;
    }
    if (flyingTime <= 0 && prevTime >= 0){
        float tX = i->getF("x")+i->getF("w")/2-(x+w/2);
        float tY = i->getF("y")+i->getF("h")/2-(y+h/2);
        dX = 480*tX/(sqrtf(tX*tX+tY*tY));
        dY = 480*tY/(sqrtf(tX*tX+tY*tY));
    }
}

std::vector<std::string> Homing::draw(){
    std::vector<std::string> ret = {std::to_string(x), std::to_string(y), std::to_string(w), std::to_string(h), std::to_string(R), std::to_string(G), std::to_string(B), "255"};
    return ret;
}

void Homing::setF(std::string get, float set){
    Instance::setF(get, set);
    if (get == "r") R = set;
    else if (get == "g") G = set;
    else if (get == "b") B = set;
};