//
//  Player.h
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Instance.h"
#include "ControlsEnum.h"
#include "PlayerHitbox.h"
class Player : public Instance{
    int hits;
    float hitTime, maxHitTime;
public:
    Player(float X, float Y, float HP);
    void updateWithControls(bool *con, bool *conPressed, double deltaTime);
    void createHitbox(Instances *i);
    void finishUpdate(double deltaTime);
    void collision(Instance* o, double deltaTime);
    float getF(std::string get);
    PlayerHitbox *hitB;
    std::vector<std::string> draw();
};

#endif /* Player_h */
