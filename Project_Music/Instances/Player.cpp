//
//  Player.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Player.h"

Player::Player(float X, float Y, float HP) : Instance(X,Y,HP){
    h = 64;
    hasGravity = true;
    solid = true;
    index = "Player";
    hitB = new PlayerHitbox(this);
    maxHitTime = 1;
}

void Player::updateWithControls(bool* con, bool* conPressed, double deltaTime){
    Instance::updateWithPlayer(this, deltaTime);
    if (con[LEFT] && !con[RIGHT]){
        dX -= 320*deltaTime;
        if (dX < -320 || (dX < -160 && !con[RUN])){
            dX += 320*deltaTime;
            if (dX > -320 || (dX > -160 && !con[RUN])){
                if (con[RUN]) dX = -320;
                else dX = -160;
            }
        }
    }
    else if (con[RIGHT] && !con[LEFT]){
        dX += 320*deltaTime;
        if (dX > 320 || (dX > 160 && !con[RUN])){
            dX -= 320*deltaTime;
            if (dX < 320 || (dX < 160 && !con[RUN])){
                if (con[RUN]) dX = 320;
                else dX = 160;
            }
        }
    }
    else{
        if (dX > 0){
            dX -= 640*deltaTime;
            if (dX <= 0) dX = 0;
        }
        else{
            dX += 640*deltaTime;
            if (dX >= 0) dX = 0;
        }
    }
    if (conPressed[JUMP] && onGround){
        dY -= (360+abs(int(dX/2)));
        onGround = false;
    }
    if (hitB){
        if (con[UP] && !con[DOWN]){
            hitB->setPosition(0);
        }
        else if (con[DOWN] && !con[UP]){
            hitB->setPosition(2);
        }
        else{
            hitB->setPosition(1);
        }
    }
    if (hitTime > 0){
        hitTime -= deltaTime;
        if (hitTime < 0) hitTime = 0;
    }
}

void Player::collision(Instance* o, double deltaTime){
    Instance::collision(o, deltaTime);
    if (hitTime == 0){
        float hX = hitB->getF("x");
        float hY = 0;
        if (hitB->getPosition() == 0) hY = y+h/4-1;
        else if (hitB->getPosition() == 1) hY = y+h/2-1;
        else hY = y+h*3/4-1;
        float hW = hitB->getF("w");
        float hH = hitB->getF("h");
        if (o->index != "Solid" && o->index != "Hitbox" && o->index != "Non-Player"){
            if (((o->getF("x")+o->getF("dX")*deltaTime <= hX+hW+dX*deltaTime && o->getF("x")+o->getF("w") >= hX) || (o->getF("x")+o->getF("w")+o->getF("dX")*deltaTime >= hX+dX*deltaTime && o->getF("x") <= hX+hW)) && ((o->getF("y")+o->getF("dY")*deltaTime <= hY+hH+dY*deltaTime && o->getF("y")+o->getF("h") >= hY) || (o->getF("y")+o->getF("h")+o->getF("dY")*deltaTime >= hY+dY*deltaTime && o->getF("y") <= hY+hH))){
                hitTime = maxHitTime;
                hits++;
            }//*/
        }
    }
}

void Player::createHitbox(Instances *i){
    Instances *hitbox = new Instances();
    hitbox->i = hitB;
    for (Instances* in = i; in; in = in->next){
        if (in->i->index == "Player"){
            hitbox->next = in->next;
            i->next = hitbox;
            break;
        }
    }
}

float Player::getF(std::string get){
    float ret = Instance::getF(get);
    if (get == "maxHitTime") ret = maxHitTime;
    else if (get == "hitTime") ret = hitTime;
    else if (get == "hits") ret = hits;
    return ret;
}

void Player::finishUpdate(double deltaTime){
    Instance::finishUpdate(deltaTime);
    hitB->finishUpdate(this);
}

std::vector<std::string> Player::draw(){
    std::vector<std::string> ret = {std::to_string(x), std::to_string(y), std::to_string(w), std::to_string(h), "255", "255", "255", "255"};
    return ret;
};