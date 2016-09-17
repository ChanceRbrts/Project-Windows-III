//
//  MultipleHoming.cpp
//  Project_Music
//
//  Created by Chance Roberts on 3/16/16.
//  Copyright © 2016 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "MultipleHoming.h"
#include <stdlib.h>
MultipleHoming::MultipleHoming(float X, float Y, float bpm, float firstBeat, float duration, int times, float ScrW, float ScrH, float r, float g, float b) : Instance(X,Y,1){
    ho = new Homing(X,Y,bpm,firstBeat,firstBeat,r,g,b);
    w = ho->getF("w");
    h = ho->getF("h");
    time = times;
    maxSendOut = 60*duration/bpm;
    sendOut = maxSendOut;
    curBeat = firstBeat;
    nextBeat = duration;
    scrW = ScrW;
    scrH = ScrH;
    BPM = bpm;
    red = r;
    gre = g;
    blu = b;
    nextR = rand()%256;
    nextG = rand()%256;
    nextB = rand()%256;
    newOne = true;
}

void MultipleHoming::updateWithPlayer(Instance* i, double deltaTime){
    Instance::updateWithPlayer(i, deltaTime);
    ho->updateWithPlayer(i, deltaTime);
    if (newOne){
        ho->setF("dX",ho->getF("dX")*0.9);
        ho->setF("dY",ho->getF("dY")*0.9);
        newOne = false;
    }
    ho->setF("r",red+(nextR-red)*(maxSendOut-sendOut)/maxSendOut);
    ho->setF("g",gre+(nextG-gre)*(maxSendOut-sendOut)/maxSendOut);
    ho->setF("b",blu+(nextB-blu)*(maxSendOut-sendOut)/maxSendOut);
    if (time > 0){
        sendOut -= deltaTime;
        if (sendOut <= 0){
            Homing *delH = ho;
            ho = new Homing(ho->getF("x"),ho->getF("y"),BPM,curBeat+nextBeat,curBeat+nextBeat,nextR,nextG,nextB);
            delete delH;
            newOne = true;
            curBeat += nextBeat;
            sendOut = maxSendOut;
            time -= 1;
            nextR = rand()%256;
            nextG = rand()%256;
            nextB = rand()%256;
        }
    }
}

void MultipleHoming::finishUpdate(double deltaTime){
    ho->finishUpdate(deltaTime);
    x = ho->getF("x");
    y = ho->getF("y");
}

std::vector<std::string> MultipleHoming::draw(){
    return ho->draw();
}