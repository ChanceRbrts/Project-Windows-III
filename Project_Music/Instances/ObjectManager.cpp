//
//  ObjectManager.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ObjectManager.h"

ObjectManager::ObjectManager(){}

ObjectManager::ObjectManager(float X, float Y, float W, float H, float sW, float sH){
    scrW = sW;
    scrH = sH;
    windows = 1;
    window = new Window[1];
    window[0] = Window();
    window[0].x = X;
    window[0].y = Y;
    window[0].w = W;
    window[0].h = H;
    p = new Player(scrW/2, scrH/2, 1);
    head = new Instances();
    head->i = p;
    player = head;
    p->createHitbox(head);
    boundaries = new Solid*[4];
    boundaries[0] = new Solid(window[0].x,window[0].y,window[0].w,4);
    boundaries[1] = new Solid(window[0].x,window[0].y,4,window[0].h);
    boundaries[2] = new Solid(window[0].x,window[0].y+window[0].h-4,window[0].w,4);
    boundaries[3] = new Solid(window[0].x+window[0].w-4,window[0].y,4,window[0].h);
    Instances *cur = head->next; //Should exist... :|
    for (int i = 0; i < 4; i++){
        Instances *next = new Instances();
        next->i = boundaries[i];
        cur->next = next;
        cur = next;
    }
    objec = new ObjectController(cur, sW, sH);
}

ObjectManager::~ObjectManager(){
    while (head){
        Instances *del = head;
        head = head->next;
        delete del;
    }
}

void ObjectManager::updateBeat(double beat){
    objec->update(beat,player);
}

void ObjectManager::update(bool* con, bool* conPressed, double deltaTime){
    for (Instances* i = head; i; i = i->next){
        if (i->i->index == "Player") i->i->updateWithControls(con, conPressed, deltaTime);
        else i->i->updateWithPlayer(player->i, deltaTime);
    }
    updateFurther(deltaTime);
    for (Instances* i = head; i; i = i->next){
        if (i->i->index != "Player" && i->i->index != "Hitbox") player->i->collision(i->i, deltaTime);
    }
    for (Instances* i = head; i; i = i->next){
        i->i->finishUpdate(deltaTime);
    }
}

void ObjectManager::updateFurther(double deltaTime){
    for (int i = 0; i < 4; i++){
        if (i%2 == 0) boundaries[i]->setF("w",window[0].w);
        else boundaries[i]->setF("h",window[0].h);
        
        if (i != 3) boundaries[i]->setF("dX",(window[0].x-boundaries[i]->getF("x"))/deltaTime);
        else boundaries[i]->setF("dX",(window[0].x+window[0].w-4-boundaries[i]->getF("x"))/deltaTime);
        
        if (i != 2) boundaries[i]->setF("dY",(window[0].y-boundaries[i]->getF("y"))/deltaTime);
        else boundaries[i]->setF("dY",(window[0].y+window[0].h-4-boundaries[i]->getF("y"))/deltaTime);
    }
}

std::vector<std::vector<std::string>> ObjectManager::draw(){
    std::vector<std::vector<std::string>> ret;
    for (Instances* i = head; i; i = i->next){
        ret.push_back(i->i->draw());
    }
    return ret;
}

void ObjectManager::updateWindow(int windo, float X, float Y, float W, float H){
    if (windo > windows){
        Window* test = new Window[windo];
        for (int i = 0; i < windows; i++){
            test[i] = window[i];
        }
        Window *toDelete = window;
        window = test;
        delete[] toDelete;
    }
    window[windo].x = X;
    window[windo].y = Y;
    window[windo].w = W;
    window[windo].h = H;
    objec->updateWindow(window);
}

int ObjectManager::getNumberOfHits(){
    return p->getF("hits");
}