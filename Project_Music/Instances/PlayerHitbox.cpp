//
//  PlayerHitbox.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/28/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "PlayerHitbox.h"
PlayerHitbox::PlayerHitbox(Instance *player){
    Instance((player->getF("x")+player->getF("w")/2-1)/32,(player->getF("y")+player->getF("h")-1)/32,1);
    maxTime = player->getF("maxHitTime");
    index = "Hitbox";
    w = 2;
    h = 2;
    position = 1;
}

void PlayerHitbox::finishUpdate(double deltaTime){
    return;
}

void PlayerHitbox::finishUpdate(Instance *player){
    x = player->getF("x")+player->getF("w")/2-1;
    if (position == 0){
        y = player->getF("y")+player->getF("h")/4-1;
    }
    else if (position == 2){
        y = player->getF("y")+player->getF("h")*3/4-1;
    }
    else{
        y = player->getF("y")+player->getF("h")/2-1;
    }
    pX = player->getF("x");
    pY = player->getF("y");
    pW = player->getF("w");
    pH = player->getF("h");
    time = player->getF("hitTime");
}

void PlayerHitbox::setPosition(int set){
    if (set <= 2 && set >= 0) position = set;
}

int PlayerHitbox::getPosition(){
    return position;
}

std::vector<std::string> PlayerHitbox::draw(){
    std::vector<std::string> ret;
    if (time == 0){
        ret = {std::to_string(x),std::to_string(y),std::to_string(w),std::to_string(h),"0","0","0","255"};
    }
    else{
        ret = {std::to_string(pX),std::to_string(pY),std::to_string(pW),std::to_string(pH),"0","150","255",std::to_string(255*time/maxTime)};
    }
    return ret;
}