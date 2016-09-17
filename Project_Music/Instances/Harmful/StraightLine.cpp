//
//  StraightLine.cpp
//  Project_Music
//
//  Created by Chance Roberts on 12/7/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include "StraightLine.h"

StraightLine::StraightLine(float X, float Y, float W, float H, float DX, float DY, float r, float g, float b) : Instance(X,Y,1){
    w = W;
    h = H;
    dX = DX;
    dY = DY;
    R = r;
    G = g;
    B = b;
    harmful = true;
    index = "StraightLine";
}

std::vector<std::string> StraightLine::draw(){
    std::vector<std::string> ret = {std::to_string(x), std::to_string(y), std::to_string(w), std::to_string(h), std::to_string(R), std::to_string(G), std::to_string(B), "255"};
    return ret;
}
