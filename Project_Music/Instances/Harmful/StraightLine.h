//
//  StraightLine.h
//  Project_Music
//
//  Created by Chance Roberts on 12/7/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef StraightLine_h
#define StraightLine_h
#include "Instance.h"
class StraightLine : public Instance{
    float R, G, B;
public:
    StraightLine(float X, float Y, float W, float H, float DX, float DY, float r = 255, float g = 150, float b = 0);
     std::vector<std::string> draw();
    
};

#endif /* StraightLine_h */
