//
//  Instance.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Instance.h"
Instance::Instance(){
    Instance(0,0,1);
}

Instance::Instance(float X, float Y = 0, float HP = 1){
    x = X;
    y = Y;
    w = 32;
    h = 32;
    hp = HP;
    dX = 0;
    dY = 0;
    hasGravity = false;
    onGround = false;
    solid = false;
    immovable = false;
    harmful = false;
    index = "Instance";
}

Instance::~Instance(){}

void Instance::updateWithPlayer(Instance *i, double deltaTime){
    if (hasGravity) gravity(deltaTime);
    
}

void Instance::gravity(double deltaTime){
    dY += 700*deltaTime;
    if (dY > 4200){
        dY -= 1400*deltaTime;
        if (dY < 4200) dY = 4200;
    }
}

void Instance::finishUpdate(double deltaTime){
    x += dX*deltaTime;
    y += dY*deltaTime;
}

void Instance::extraCollision(Instance *o, float colPoint){}

std::vector<std::string> Instance::draw(){std::vector<std::string> ret; return ret;}

void Instance::collision(Instance* o, double deltaTime){
    if (o->getF("dX") < -10000 || o->getF("dX") > 10000 || o->getF("dY") < -10000 || o->getF("dY") > 10000) return; //Seriously. This shouldn't happen. :(
    if (y+h+dY*deltaTime > o->getF("y")+o->getF("dY")*deltaTime && y+h <= o->getF("y") && x+w+dX*deltaTime > o->getF("x")+o->getF("dX")*deltaTime && x+dX*deltaTime < o->getF("x")+o->getF("w")+o->getF("dX")*deltaTime){
        if (solid && o->getB("solid")){
            if (o->getB("immovable") && !immovable){
                y = o->getF("y")-h;
                dY = o->getF("dY");
            }
            else if (!o->getB("immovable")){
                y = o->getF("y")-h;
                dY = 0;
                o->setF("dY",0);
            }
        }
        if (hasGravity) onGround = true;
        extraCollision(o, 270);
        o->extraCollision(this, 90);
    }
    if (y+dY*deltaTime < o->getF("y")+o->getF("h")+o->getF("dY")*deltaTime && y >= o->getF("y")+o->getF("h") && x+w+dX*deltaTime > o->getF("x")+o->getF("dX")*deltaTime && x+dX*deltaTime < o->getF("x")+o->getF("w")+o->getF("dX")*deltaTime){
        if (solid && o->getB("solid")){
            if (o->getB("immovable") && !immovable){
                y = o->getF("y")+o->getF("h");
                dY = o->getF("dY");
            }
            else if (!o->getB("immovable")){
                y = o->getF("y")+o->getF("h");
                dY = 0;
                o->setF("dY",0);
            }
        }
        extraCollision(o, 90);
        o->extraCollision(this, 270);
    }
    if (x+w+dX*deltaTime > o->getF("x")+o->getF("dX")*deltaTime && x+w <= o->getF("x") && y+h+dY*deltaTime > o->getF("y")+o->getF("dY")*deltaTime && y+dY*deltaTime < o->getF("y")+o->getF("h")+o->getF("dY")*deltaTime){
        if (solid && o->getB("solid")){
            if (o->getB("immovable") && !immovable){
                x = o->getF("x")-w;
                dX = o->getF("dX");
            }
            else if (!o->getB("immovable")){
                x = o->getF("x")-w;
                dX = 0;
                o->setF("dX",0);
            }
        }
        extraCollision(o, 0);
        o->extraCollision(this, 180);
    }
    if (x+dX*deltaTime < o->getF("x")+o->getF("w")+o->getF("dX")*deltaTime && x >= o->getF("x")+o->getF("w") && y+h+dY*deltaTime > o->getF("y")+o->getF("dY")*deltaTime && y+dY*deltaTime < o->getF("y")+o->getF("h")+o->getF("dY")*deltaTime){
        if (solid && o->getB("solid")){
            if (o->getB("immovable") && !immovable){
                x = o->getF("x")+o->getF("w");
                dX = o->getF("dX");
            }
            else if (!o->getB("immovable")){
                x = o->getF("x")+o->getF("w");
                dX = 0;
                o->setF("dX",0);
            }
        }
        extraCollision(o, 180);
        o->extraCollision(this, 0);
    }
}

float Instance::getF(std::string get){
    if (get == "x") return x;
    if (get == "y") return y;
    if (get == "dX") return dX;
    if (get == "dY") return dY;
    if (get == "w") return w;
    if (get == "h") return h;
    return 0;
}

void Instance::setF(std::string get, float set){
    if (get == "x") x = set;
    else if (get == "y") y = set;
    else if (get == "dX") dX = set;
    else if (get == "dY") dY = set;
    else if (get == "w" && set > 0) w = set;
    else if (get == "h" && set > 0) h = set;
}

bool Instance::getB(std::string get){
    if (get == "hasGravity") return hasGravity;
    if (get == "onGround") return onGround;
    if (get == "solid") return solid;
    if (get == "immovable") return immovable;
    return false;
}

void Instance::updateWithControls(bool *con, bool *conPressed, double deltaTime){
    updateWithPlayer(nullptr, deltaTime);
}
