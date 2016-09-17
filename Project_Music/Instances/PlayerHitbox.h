//
//  PlayerHitbox.h
//  Project_Music
//
//  Created by Chance Roberts on 11/28/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef PlayerHitbox_h
#define PlayerHitbox_h
#include "Instance.h"
class PlayerHitbox : public Instance{
private:
    int position;
    float pX, pY, pW, pH, time, maxTime;
public:
    PlayerHitbox(Instance *player);
    ~PlayerHitbox();
    void finishUpdate(double deltaTime);
    void finishUpdate(Instance *player);
    void setPosition(int set);
    int getPosition();
    std::vector<std::string> draw();
};
#endif /* PlayerHitbox_h */
