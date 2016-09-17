//
//  Non-Player.h
//  Project_Music
//
//  Created by Chance Roberts on 2/5/16.
//  Copyright © 2016 Chance Roberts. All rights reserved.
//

#ifndef Non_Player_h
#define Non_Player_h
#include "Instance.h"
class NonPlayer : public Instance{
    int qX, qY;
    bool visible;
    float gapW, gapH, miniY;
public:
    NonPlayer(int X, int Y, float GapW, float GapH, float minY);
    void updateWithPlayer(Instance* i, double deltaTime);
    std::vector<std::string> draw();
};

#endif /* Non_Player_h */
