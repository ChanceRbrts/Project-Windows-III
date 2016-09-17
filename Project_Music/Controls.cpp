//
//  Controls.cpp
//  Second Person Game Test
//
//  Created by Chance Roberts on 11/2/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include "Controls.h"
#include <iostream>
Controls::Controls(){
    for (int i = 0; i < CONTROL_LENGTH; i++){
        controls[i] = false;
        controlsPressed[i] = false;
    }
}

Controls::~Controls(){
    
}

void Controls::keyPressed(unsigned char key, int x, int y){
    if ((key == 'w' || key == 'W') && !controls[UP]){
        controls[UP] = true;
        controlsPressed[UP] = true;
    }
    else if ((key == 's' || key == 'S') && !controls[DOWN]){
        controls[DOWN] = true;
        controlsPressed[DOWN] = true;
    }
    else if ((key == 'a' || key == 'A') && !controls[LEFT]){
        controls[LEFT] = true;
        controlsPressed[LEFT] = true;
    }
    else if ((key == 'd' || key == 'D') && !controls[RIGHT]){
        controls[RIGHT] = true;
        controlsPressed[RIGHT] = true;
    }
    else if ((key == ' ' || key == 'x' || key == 'X') && !controls[JUMP]){
        controls[JUMP] = true;
        controlsPressed[JUMP] = true;
    }
    else if ((key == 'z' || key == 'Z') && !controls[RUN]){
        controls[RUN] = true;
        controlsPressed[RUN] = true;
    }
}

void Controls::keyReleased(unsigned char key, int x, int y){
    if (key == 'w' || key == 'W'){
        controls[UP] = false;
    }
    else if (key == 's' || key == 'S'){
        controls[DOWN] = false;
    }
    else if (key == 'a' || key == 'A'){
        controls[LEFT] = false;
    }
    else if (key == 'd' || key == 'D'){
        controls[RIGHT] = false;
    }
    else if (key == ' ' || key == 'x' || key == 'X'){
        controls[JUMP] = false;
    }
    else if (key == 'z' || key == 'Z'){
        controls[RUN] = false;
    }
}

void Controls::keySpecialPressed(int key, int x, int y){
    if (key == GLUT_KEY_UP && !controls[UP]){
        controls[UP] = true;
        controlsPressed[UP] = true;
    }
    else if (key == GLUT_KEY_DOWN && !controls[DOWN]){
        controls[DOWN] = true;
        controlsPressed[DOWN] = true;
    }
    else if (key == GLUT_KEY_LEFT && !controls[LEFT]){
        controls[LEFT] = true;
        controlsPressed[LEFT] = true;
    }
    else if (key == GLUT_KEY_RIGHT && !controls[RIGHT]){
        controls[RIGHT] = true;
        controlsPressed[RIGHT] = true;
    }
}

void Controls::keySpecialReleased(int key, int x, int y){
    if (key == GLUT_KEY_UP){
        controls[UP] = false;
    }
    else if (key == GLUT_KEY_DOWN){
        controls[DOWN] = false;
    }
    else if (key == GLUT_KEY_LEFT){
        controls[LEFT] = false;
    }
    else if (key == GLUT_KEY_RIGHT){
        controls[RIGHT] = false;
    }
}

void Controls::nextFrame(){
    for (int i = 0; i < CONTROL_LENGTH; i++){
        controlsPressed[i] = false;
    }
}

bool *Controls::getControls(){
    return controls;
}

bool *Controls::getControlsPressed(){
    return controlsPressed;
}