//
//  Controls.h
//  Second Person Game Test
//
//  Created by Chance Roberts on 11/2/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef Controls_h
#define Controls_h
#include <GLUT/glut.h>
#include "ControlsEnum.h"
class Controls{
private:
    static const int CONTROL_LENGTH = 6;
    bool controls[CONTROL_LENGTH];
    bool controlsPressed[CONTROL_LENGTH];
public:
    Controls();
    ~Controls();
    void keyPressed(unsigned char key, int x, int y);
    void keyReleased(unsigned char key, int x, int y);
    void keySpecialPressed(int key, int x, int y);
    void keySpecialReleased(int key, int x, int y);
    bool *getControls();
    bool *getControlsPressed();
    void nextFrame();
};
#endif /* Controls_h */
