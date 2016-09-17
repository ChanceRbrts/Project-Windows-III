//
//  Solid.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include "Solid.h"
Solid::Solid(float X, float Y) : Instance(X,Y,1){
    solid = true;
    immovable = true;
    hasGravity = false;
    index = "Solid";
}

Solid::Solid(float X, float Y, float W, float H) : Instance(X,Y,1){
    Instance(X,Y,1);
    solid = true;
    immovable = true;
    hasGravity = false;
    index = "Solid";
    w = W;
    h = H;
}

std::vector<std::string> Solid::draw(){
    std::vector<std::string> ret;
    ret.push_back(std::to_string(x));
    ret.push_back(std::to_string(y));
    ret.push_back(std::to_string(w));
    ret.push_back(std::to_string(h));
    ret.push_back("0");
    ret.push_back("0");
    ret.push_back("0");
    ret.push_back("255");
    return ret;
}