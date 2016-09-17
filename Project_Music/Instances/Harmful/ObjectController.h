//
//  ObjectController.h
//  Project_Music
//
//  Created by Chance Roberts on 12/3/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef ObjectController_h
#define ObjectController_h
#include "Instance.h"
#include "Homing.h"
#include "StraightLine.h"
#include "Solid.h"
#include "Non-Player.h"
#include "MultipleHoming.h"
struct Window{
    float x,y,w,h;
};

class ObjectController{
    Instances* placeOfControl;
    Instances* last;
    Instances* solidObjects;
    float prevBeat;
    void addObject(Instance* i);
    void deleteNextObject(Instances* i);
    void addSolidObject(float X, float Y, float W, float H);
    float scrW, scrH;
    float bpm;
    Window *wind;
    float beatPattern1, endBeatPattern1;
    bool switchOne;
public:
    ObjectController(Instances* place, float sW, float sH);
    void update(double beat, Instances *player);
    void updateWindow(Window *w);
};

#endif /* ObjectController_h */
