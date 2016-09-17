//
//  Non-Player.cpp
//  Project_Music
//
//  Created by Chance Roberts on 2/5/16.
//  Copyright © 2016 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Non-Player.h"

NonPlayer::NonPlayer(int X, int Y, float GapW, float GapH, float minY){
    Instance(0,0,1);
    qX = X;
    qY = Y;
    w = 32;
    h = 64;
    harmful = false;
    index = "Non-Player";
    visible = true;
    gapW = GapW;
    gapH = GapH;
    miniY = minY;
}

void NonPlayer::updateWithPlayer(Instance *i, double deltaTime){
    Instance::updateWithPlayer(i, deltaTime);
    float oX = i->getF("x");
    float oY = i->getF("y");
    int pQX = 0;
    int pQY = 0;
    if (oX > gapW){
        oX -= gapW;
        pQX = 1;
    }
    if (oY > gapH+miniY){
        oY -= gapH;
        pQY = 1;
    }
    if (x > -w && y > -h){
        x = oX+gapW*qX;
        y = oY+gapH*qY;
    }
    dX = 0;
    dY = 0;
    visible = !(qX == pQX && qY == pQY);
}

std::vector<std::string> NonPlayer::draw(){
    std::vector<std::string> ret;
    if (visible){
        ret = {std::to_string(x), std::to_string(y), std::to_string(w), std::to_string(h), "220", "220", "220", std::to_string(255*visible)};
    }
    else{
        ret = {"0","0","0","0","0","0","0","0"}; //I officially give up. :(
    }
    return ret;
}