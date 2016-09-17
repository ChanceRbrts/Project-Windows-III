//
//  ObjectManager.h
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef ObjectManager_h
#define ObjectManager_h
#include "Instance.h"
#include "Player.h"
#include "Solid.h"
#include "ObjectController.h"

class ObjectManager{
private:
    Instances* head;
    Instances* player;
    Player* p;
    Solid** boundaries;
    Window *window;
    int windows;
    float scrW, scrH;
    ObjectController* objec;
public:
    ObjectManager();
    ObjectManager(float X, float Y, float W, float H, float sW, float sH);
    ~ObjectManager();
    void updateBeat(double beat);
    void update(bool *con, bool *conPressed, double deltaTime);
    void updateFurther(double deltaTime);
    std::vector<std::vector<std::string>> draw();
    void updateWindow(int windo, float X, float Y, float W, float H);
    int getNumberOfHits();
};

#endif /* ObjectManager_h */
