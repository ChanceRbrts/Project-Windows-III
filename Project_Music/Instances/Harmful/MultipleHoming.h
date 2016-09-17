//
//  MultipleHoming.h
//  Project_Music
//
//  Created by Chance Roberts on 3/16/16.
//  Copyright © 2016 Chance Roberts. All rights reserved.
//

#ifndef MultipleHoming_h
#define MultipleHoming_h
#include "Instance.h"
#include "Homing.h"
class MultipleHoming : public Instance{
    Homing *ho;
    float sendOut, maxSendOut, curBeat, nextBeat, BPM;
    float scrW, scrH;
    float red, gre, blu;
    float nextR, nextG, nextB;
    int time;
    bool newOne;
public:
    MultipleHoming(float X, float Y, float bpm, float firstBeat, float duration, int times, float ScrW, float ScrH, float r = 255, float g = 0, float b = 255);
    void updateWithPlayer(Instance* i, double deltaTime);
    void finishUpdate(double deltaTime);
    std::vector<std::string> draw();
};
#endif /* MultipleHoming_h */
