//
//  main.cpp
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "Controls.h"
#include "ObjectManager.h"
#include <math.h>
#include <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
Controls *c;
ObjectManager *obj;
double startFrameTime;
std::vector<std::string> textChanges;
std::vector<double> startChange;
std::vector<double> endChange;
double beat, bpm;
int prevBeat;
bool hasPopped3;
bool *drawing;
double currentPos;
std::vector<std::vector<std::string>> instr;
std::string end;

void kP(unsigned char a, int x, int y){
    if (a == 27){
        exit(0);
    }
    c->keyPressed(a, x, y);
}

void kU(unsigned char a, int x, int y){c->keyReleased(a, x, y);}

void sP(int a, int x, int y){c->keySpecialPressed(a, x, y);}

void sU(int a, int x, int y){c->keySpecialReleased(a, x, y);}

void draw(std::vector<std::vector<std::string>> draw){
    for (int w = 0; w < 4; w++){
        if (drawing[w]){
            glutSetWindow(w+1);
            glClearColor(0.75, 0.75, 0.75, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            for (int i = 0; i < draw.size(); i++){
                if (draw[i].size() > 4 && std::stof(draw[i][0]) < glutGet(GLUT_WINDOW_X)+glutGet(GLUT_WINDOW_WIDTH) && std::stof(draw[i][1]) < glutGet(GLUT_WINDOW_Y)+glutGet(GLUT_WINDOW_HEIGHT) && std::stof(draw[i][2])+std::stof(draw[i][0]) > glutGet(GLUT_WINDOW_X) && std::stof(draw[i][1])+std::stof(draw[i][3]) > glutGet  (GLUT_WINDOW_Y)){
                    if (draw[i].size() == 8){
                        glColor4f(std::stof(draw[i][4])/255.0, std::stof(draw[i][5])/255.0, std::stof(draw[i][6])/255.0,std::stof(draw[i][7])/255.0);
                        glRectf((std::stof(draw[i][0])-glutGet(GLUT_WINDOW_X)-glutGet(GLUT_WINDOW_WIDTH)/2)/(glutGet(GLUT_WINDOW_WIDTH)*1.0/2),(glutGet(GLUT_WINDOW_Y)+glutGet(GLUT_WINDOW_HEIGHT)/2-std::stof(draw[i][1]))/(glutGet(GLUT_WINDOW_HEIGHT)*1.0/2),(std::stof(draw[i][0])+std::stof(draw[i][2])-glutGet(GLUT_WINDOW_X)-glutGet(GLUT_WINDOW_WIDTH)/2)/(glutGet(GLUT_WINDOW_WIDTH)*1.0/2),(glutGet(GLUT_WINDOW_Y)+glutGet(GLUT_WINDOW_HEIGHT)/2-std::stof(draw[i][1])-std::stof(draw[i][3]))/(glutGet(GLUT_WINDOW_HEIGHT)*1.0/2));
                    }
                }
            }
            glutSwapBuffers();
        }
    }
    glutSetWindow(1);
}

void changeWindow(double deltaTime){
    glutSetWindow(1);
    if ((beat >= 700 && beat <= 732) || (beat >= 796 && beat <= 810)) glutSetWindow(4);
    else if (beat >= 812 && beat <= 826) glutSetWindow(2);
    else if (beat >= 828 && beat <= 840) glutSetWindow(3);
    if (currentPos < textChanges.size()){
        if (beat >= startChange[currentPos] && beat <= endChange[currentPos]){
            std::string repeat = (textChanges[currentPos]).substr(0,1+(int)((beat-startChange[currentPos])*textChanges[currentPos].size()/(endChange[currentPos]-startChange[currentPos])));
            glutSetWindowTitle(repeat.c_str());
        }
       
        if (beat > endChange[currentPos]) currentPos++;
    }
    if (beat >= 860){
        for (int i = 2; i < 5; i++){
            glutSetWindow(i);
            if (currentPos < textChanges.size()){
                if (beat >= startChange[currentPos] && beat <= endChange[currentPos]){
                    std::string repeat = (textChanges[currentPos]).substr(0,1+(int)((beat-startChange[currentPos])*textChanges[currentPos].size()/(endChange[currentPos]-startChange[currentPos])));
                    glutSetWindowTitle(repeat.c_str());
                }
            }
        }
    }
    if (beat >= 764 && prevBeat < 764){
        textChanges[textChanges.size()-2] = "You got hit "+std::to_string(obj->getNumberOfHits())+" times!";
    }
    glutSetWindow(1);
    if (beat >= 92 && beat <= 156){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*(beat-92)/(4*(156-92)),glutGet(GLUT_SCREEN_HEIGHT)/4);
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2+glutGet(GLUT_SCREEN_WIDTH)*(beat-92)/(2*(156-92)), glutGet(GLUT_SCREEN_HEIGHT)/2);
    }
    if (beat >= 156 && beat <= 188){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*(188-beat)/(4*(188-156))-cos((beat-156)*M_PI/4)*(glutGet(GLUT_SCREEN_WIDTH)/2-glutGet(GLUT_WINDOW_WIDTH)/2), glutGet(GLUT_SCREEN_HEIGHT)/4);
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2+glutGet(GLUT_SCREEN_WIDTH)*(188-beat)/(2*(188-156)), glutGet(GLUT_SCREEN_HEIGHT)/2);
    }
    if (beat >= 188 && beat <= 204){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-cos((beat-156)*M_PI/4)*glutGet(GLUT_SCREEN_WIDTH)/4, glutGet(GLUT_SCREEN_HEIGHT)/4-sin((beat-188)*M_PI/2)*glutGet(GLUT_SCREEN_HEIGHT)/12);
    }
    if (beat >= 204 && beat <= 212){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-cos((beat-156)*M_PI/2)*glutGet(GLUT_SCREEN_WIDTH)*((8-(beat-204))*6/(64.0*4)+1/32.0), glutGet(GLUT_SCREEN_HEIGHT)/4-sin((beat-188)*M_PI)*glutGet(GLUT_SCREEN_HEIGHT)/21);
    }
    if (beat >= 212 && beat <= 216){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-cos((beat-156)*M_PI*2)*glutGet(GLUT_SCREEN_WIDTH)/32, glutGet(GLUT_SCREEN_HEIGHT)/4);
    }
    if (beat >= 216 && beat <= 220){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*(beat-220)/128, glutGet(GLUT_SCREEN_HEIGHT)/4);
    }
    if (beat >= 220 && beat <= 340){
        double h = fmod(beat,4);
        double direction = M_PI*(((int)(beat))/4)/2;
        double addOn = 0;
        if (h >= 2) addOn = 1.5;
        if ((h > 0.5 && h <= 1) || (h > 2 && h <= 2.5)){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*(2*(addOn+0.5-h))*cos(direction)/8,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*(2*(addOn+0.5-h))*sin(direction)/16);
        }
        else if ((h > 1 && h <= 1.5) || (h > 2.5 && h <= 3)){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*(2*(h-addOn-1.5))*cos(direction)/8,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*(2*(h-addOn-1.5))*sin(direction)/16);
        }
        else{
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
        }
    }
    if (beat > 340 && beat <= 348){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*(beat-340)/32);
    }
    if (beat > 348 && beat <= 412){
        double direction = (beat-348)*M_PI/16;
        if (beat <= 380)
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*sin(direction)/4,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*cos(direction)/4);
        else
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*sin(direction)/4,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*cos(direction)/4);
    }
    if (beat > 412 && beat <= 476){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)*((beat-412)/(476-412))/2);
    }
    if (beat > 476 && beat <= 508){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*sin(beat*M_PI/4)*((beat-476)/(508-476))/4,glutGet(GLUT_SCREEN_HEIGHT)/2);
    }
    if (beat > 508 && beat <= 540){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*sin(beat*M_PI/4)/4,glutGet(GLUT_SCREEN_HEIGHT)/2);
    }
    if (beat >= 540 && beat < 572){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*(beat-540)/((572-540)*4),glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*(beat-540)/(2*(572-540)));
    }
    if (beat >= 668 && beat < 676){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4*(beat-668)/8,glutGet(GLUT_SCREEN_HEIGHT)/4*(beat-668)/8);
    }
    if (beat >= 676 && beat < 700){
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2+glutGet(GLUT_SCREEN_WIDTH)*((1-cos(beat*M_PI/2))/2)/4,glutGet(GLUT_SCREEN_HEIGHT)/2+glutGet(GLUT_SCREEN_HEIGHT)*((1-cos(beat*M_PI/2))/2)/4);
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*((1-cos(beat*M_PI/2))/2)/8,glutGet(GLUT_SCREEN_HEIGHT)/4-glutGet(GLUT_SCREEN_HEIGHT)*((1-cos(beat*M_PI/2))/2)/8);
    }
    if (beat >= 700 && beat <= 708){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*(3+3*((708-beat)/8))/8,glutGet(GLUT_SCREEN_HEIGHT)*3/4);
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
    }
    if ((beat > 712 && beat < 716) || (beat > 720 && beat <= 724) || (beat > 728 && beat <= 732)){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3/8+glutGet(GLUT_SCREEN_WIDTH)*(sin((beat-712)*M_PI/2))/4,glutGet(GLUT_SCREEN_HEIGHT)*(3*(cos((beat-712)*M_PI/2))/8)+glutGet(GLUT_SCREEN_HEIGHT)*3/8);
    }
    if (beat >= 732 && prevBeat < 732){
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2,glutGet(GLUT_SCREEN_HEIGHT)/2);
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
    }
    if (beat > 732 && beat <= 796){
        glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4+36*(beat-732)/64);
    }
    if (beat >= 732 && prevBeat <= 732){
        glutSetWindowTitle("(more) I keep on running back to you.");
    }
    if (beat > 444 && prevBeat >= 444){
        //Window 2
        glutSetWindow(2);
        if (beat <= 476){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)*((476-beat)/(476-412))/2);
        }
        if (beat > 476 && beat <= 508){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*sin(beat*M_PI/4)*((beat-476)/(508-476))/4,0);
        }
        if (beat > 508 && beat <= 540){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4+glutGet(GLUT_SCREEN_WIDTH)*sin(beat*M_PI/4)/4,0);
        }
        if (beat > 540 && beat <= 572){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4-glutGet(GLUT_SCREEN_WIDTH)*(beat-540)/((572-540)*4),glutGet(GLUT_SCREEN_HEIGHT)*(beat-540)/(2*(572-540)));
        }
        if (beat >= 668 && prevBeat < 668){
            glutSetWindowTitle("3");
        }
        if (beat > 668 && beat <= 676){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2-glutGet(GLUT_SCREEN_WIDTH)*((beat-668)/8)/4,glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*((beat-668)/8)/4);
            glutPositionWindow(0,glutGet(GLUT_SCREEN_HEIGHT)/2+glutGet(GLUT_SCREEN_HEIGHT)*((beat-668)/8)/4);
        }
        if (beat >= 700 && prevBeat < 700){
            drawing[0] = false;
            drawing[1] = false;
            drawing[2] = false;
            glutSetWindow(1);
            glutSetWindowTitle("4");
            glutSetWindow(2);
        }
        if (beat >= 732 && prevBeat < 732){
            drawing[0] = true;
            drawing[1] = true;
            drawing[2] = true;
            drawing[3] = true;
        }
        if (beat > 700 && beat <= 708){
            glutPositionWindow(0,glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*((beat-700)/8)/4);
        }
        if ((beat > 708 && beat <= 712) || (beat > 724 && beat <= 728)){
            int cur = 724;
            if (beat <= 712) cur = 708;
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3*((beat-cur)/4)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
        }
        else if ((beat > 716 && beat <= 720) || (beat > 728 && beat < 732)){
            int cur = 732;
            if (beat <= 720) cur = 720;
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3*((cur-beat)/4)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
        }
        else if (beat >= 732 && beat <= 796){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)*(1+(beat-732)/64)/4,glutGet(GLUT_SCREEN_HEIGHT)*(1+(beat-732)/64)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*((beat-732)/64)/4,glutGet(GLUT_SCREEN_HEIGHT)/4-12*(beat-732)/64);
        }
    }
    if (beat > 572 && prevBeat >= 572){
        //Window 3
        glutSetWindow(3);
        if (!hasPopped3){
            glutPopWindow();
            hasPopped3 = true;
        }
        if (beat <= 588){
            glutPositionWindow(0,0);
        }
        if (beat <= 604 && beat > 588){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*(beat-588)/(2*(604-588)),0);
        }
        if (beat >= 668 && prevBeat < 668){
            glutSetWindowTitle("2");
        }
        if (beat > 668 && beat <= 676){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2-glutGet(GLUT_SCREEN_WIDTH)*((beat-668)/8)/4,glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*((beat-668)/8)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/2+glutGet(GLUT_SCREEN_WIDTH)*((beat-668)/8)/4,0);
        }
        if (beat > 700 && beat <= 708){
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3/4,glutGet(GLUT_SCREEN_HEIGHT)*((beat-700)/8)/2);
        }
        if ((beat > 708 && beat <= 712) || (beat > 724 && beat <= 728)){
            int cur = 728;
            if (beat <= 712) cur = 712;
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3*((cur-beat)/4)/4,glutGet(GLUT_SCREEN_HEIGHT)/2);
        }
        else if ((beat > 716 && beat <= 720) || (beat > 728 && beat <= 732)){
            int cur = 728;
            if (beat <= 720) cur = 716;
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3*((beat-cur)/4)/4,glutGet(GLUT_SCREEN_HEIGHT)/2);
        }
        else if (beat > 732 && beat <= 796){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2-glutGet(GLUT_SCREEN_WIDTH)*((796-beat)/64)/4,glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*((796-beat)/64)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*(1+(2*(796-beat)/64))/4,glutGet(GLUT_SCREEN_HEIGHT)/2-(glutGet(GLUT_SCREEN_HEIGHT)/4-12)*(beat-732)/64);
        }
        //Window 4
        glutSetWindow(4);
        if (beat <= 588){
            glutSetWindow(4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*(beat-572)/(2*(588-572)),glutGet(GLUT_SCREEN_HEIGHT)/2);
        }
        if (beat >= 668 && prevBeat < 668){
            glutSetWindowTitle("4");
        }
        if (beat > 668 && beat <= 676){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2-glutGet(GLUT_SCREEN_WIDTH)*((beat-668)/8)/4,glutGet(GLUT_SCREEN_HEIGHT)/2-glutGet(GLUT_SCREEN_HEIGHT)*((beat-668)/8)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/2+glutGet(GLUT_SCREEN_WIDTH)*((beat-668)/8)/4,glutGet(GLUT_SCREEN_HEIGHT)/2+glutGet(GLUT_SCREEN_HEIGHT)*((beat-668)/8)/4);
        }
        if (beat >= 700 && prevBeat < 700){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/2,glutGet(GLUT_SCREEN_HEIGHT)/2);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
        }
        if (beat >= 732 && prevBeat < 732){
            glutSetWindowTitle("4");
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*3/8+glutGet(GLUT_SCREEN_WIDTH)*(sin((beat-712)*M_PI/2))/4,glutGet(GLUT_SCREEN_HEIGHT)*(3*(cos((beat-712)*M_PI/2))/8)+glutGet(GLUT_SCREEN_HEIGHT)*3/8);
        }
        if (beat > 732 && prevBeat < 796){
            glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)*(1+(beat-732)/64)/4,glutGet(GLUT_SCREEN_HEIGHT)*(1+(beat-732)/64)/4);
            glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)*(3-1*(beat-732)/64)/8,glutGet(GLUT_SCREEN_HEIGHT)*6/8-((glutGet(GLUT_SCREEN_HEIGHT)*4/8)+36)*(beat-732)/64);
        }
    }
    glutSetWindow(1);
}

void setupAudio(){
    //NSSound *player = [[NSSound alloc] initWithContentsOfFile: @"/Users/chanceroberts/Documents/Project_Music/Project_Music/Music/WithYou.wav" byReference: NO];
    //NSSound *player = [[NSSound alloc] initWithContentsOfFile: [[NSBundle mainBundle] pathForResource: @"WithYou" ofType: @".wav"] byReference: NO];
    //NSString stringWithFormat: @"%@",[NSSound soundNamed: ]]);
    //NSLog([NSString stringWithFormat: @"%@/usr/share/man/man1/WithYou.wav",[[NSBundle mainBundle] resourcePath]]);
    NSSound *player = [[NSSound alloc] initWithContentsOfFile: [NSString stringWithFormat: @"%@/usr/share/man/man1/WithYou.wav",[[NSBundle mainBundle] resourcePath]] byReference: NO];
    [player play];
}

void update(){
    glClearColor(0.75, 0.75, 0.75, 1.0);
    double currentTime = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    beat = 174.0/60.0*(currentTime-0.460);
    if ((int)beat > prevBeat) std::cout << "Beat " << (int)beat << std::endl;
    if (startFrameTime > 0){
        double deltaTime = currentTime-startFrameTime;
        glutSetWindow(1);
        glutShowWindow();
        changeWindow(deltaTime);
        if (beat >= 700 && prevBeat >= 700 && beat < 732){ glutSetWindow(4);};
        obj->updateWindow(0, glutGet(GLUT_WINDOW_X), glutGet(GLUT_WINDOW_Y), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        glutSetWindow(1);
        glutShowWindow();
        obj->updateBeat(beat);
        obj->update(c->getControls(),c->getControlsPressed(),deltaTime);
        instr = obj->draw();
        draw(instr);
    }
    if (beat >= 444 && prevBeat < 444){
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
        glutCreateWindow("Hey, look! Another window!");
        drawing[1] = true;
        glutDisplayFunc(update);
        glutKeyboardFunc(kP);
        glutKeyboardUpFunc(kU);
        glutSpecialFunc(sP);
        glutSpecialUpFunc(sU);
        glutIdleFunc(update);
        glutSetWindow(1);
        glutPopWindow();
    }
    if (beat >= 572 && prevBeat < 572){
        glutCreateWindow("Song: \"With You\" by Rameses B");
        glutDisplayFunc(update);
        glutKeyboardFunc(kP);
        glutKeyboardUpFunc(kU);
        glutSpecialFunc(sP);
        glutSpecialUpFunc(sU);
        glutIdleFunc(update);
        glutCreateWindow("Chance has no idea what a \"difficulty curve\" is, apparently.");
        glutDisplayFunc(update);
        glutKeyboardFunc(kP);
        glutKeyboardUpFunc(kU);
        glutSpecialFunc(sP);
        glutSpecialUpFunc(sU);
        glutIdleFunc(update);
        glutSetWindow(1);
        glutPopWindow();
        glutPopWindow();
        glutSetWindow(2);
        glutPopWindow();
        glutPopWindow();
        glutSetWindow(3);
        glutPopWindow();
        drawing[2] = true;
        drawing[3] = true;
    }
    if (beat >= 880){
        exit(0);
    }
    startFrameTime = currentTime;
    c->nextFrame();
    prevBeat = (int)beat;
    glutSetWindow(1);
}

void setup(){
    currentPos = 0;
    textChanges = {"See my days are cold without you...","But I'm hurting while I'm with you...",
    "See my days are cold without you...","And though my heart can take no more,","I keep on running back to you.",
    "Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","See my days are cold without you...","And though my heart can take no more,","I keep on running back to you.","See my days are cold without you...","I'm hurting while I'm with you...","See my days are cold without you...","And my heart can take no more,","I keep on running back to you.","(RANDOM VOCALIZING THAT I WILL NOT TAKE TIME TO CODE)","And though my heart can take no more...","(No more)","(No more)","See my days are cold without you...","But I'm hurting while I'm with you...","And though my heart can take no more,","I keep on running back to you.","See my days are cold without you...","But I'm hurting while I'm with you...","And though my heart can take no more,","I keep on running back to you.","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","(more) I keep on running back to you","Running back","Running back","(Running back)","(Running back)","(Running back to you)","(Running back to you)","(Running back to you)","(Running back to you)","(Running back to you)","(Running back to you)","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","Running back to you","(more) I keep on running back to you","See my days are cold without you...","But I'm hurting while I'm with you...","And though my heart can take no more,","I keep on running back to you.","See my days are cold without you...","But I'm hurting while I'm with you...","And though my heart can take no more,","I keep on running back to you.","And my heart can take no more","I'm hurting while I'm with you...","See my days are cold without you...","MORE RANDOM VOCALIZING THAT I WILL NOT CODE.","See my days are cold without you... (Running back to you)","(Running back to you)","(Running back) And though my heart can take no more,","I keep on","(oh I keep on)","Running back to you","(Running back)","(Running back) YOU","(Running back to you)","(Running back to you)","(Running back to you)","(Running back to you)","(more) I keep on running back to you.","Project WINDOWS III","Song: With You by Rameses B","Programmed by: Chance Roberts","","Thank you for putting up with this! :|"};
    startChange = {27,43,59,74.5,81,88,88+4,88+4*2,88+4*3,88+4*4,88+4*5,88+4*6,88+4*7,88+4*8,88+4*9,88+4*10,88+4*11,88+4*12,88+4*13,88+4*14,88+4*15,88+4*16,88+4*17,88+4*18,88+4*19,88+4*20,88+4*21,88+4*22,88+4*23,88+4*24,187,202.5,208.5,219,235,251,267,272.5,284,338.5,344.5,346.5,351,359,366.5,372.5,351+32,359+32,366.5+32,372.5+32,412,412+4,412+4*2,412+4*3,412+4*4,412+4*5,412+4*6,444,444+4,444+4*2,444+4*3,476+4*2,476+4*3,476+4*4,476+4*5,476+4*6,476+4*7,508,508+4,508+4*2,508+4*3,508+4*4,508+4*5,508+4*6,543,543+8,543+15.5,543+21.5,543+32,543+8+32,543+15.5+32,543+21.5+32,607,615.5,627,636,667,676,680,689,692,696,700,704,708,712,716,720,724,796,812,828,844,860};
    endChange = {33,49,65,80,87.5,91.5,91.5+4,91.5+4*2,91.5+4*3,91.5+4*4,91.5+4*5,91.5+4*6,91.5+4*7,91.5+4*8,91.5+4*9,91.5+4*10,91.5+4*11,91.5+4*12,91.5+4*13,91.5+4*14,91.5+4*15,91.5+4*16,91.5+4*17,91.5+4*18,91.5+4*19,91.5+4*20,91.5+4*21,91.5+4*22,91.5+4*23,90.5+4*24,193,208,216,225,241,257,272,279,338,344.5,346.5,348.5,357,365,372.25,380,357+32,365+32,372.25+32,380+32,416,416+4,416+4*2,416+4*3,416+4*4,416+4*5,416+4*7,446,446+4,446+4*2,446+4*3,479+4*2,479+4*3,479+4*4,479+4*5,479+4*6,479+4*7,511,511+4,511+4*2,511+4*3,511+4*4,511+4*5,512+4*7,549,557,543+21,570,549+32,557+32,543+21+32,570+32,613,621,633,660,675.5,679.5,688.25,691.5,695,699.5,703.5,707.5,711.5,715.5,719.5,723.5,731.5,806,820,836,852,868};
}

int main(int argc, char **argv) {
    bpm = 174;
    hasPopped3 = false;
    glutInit(&argc, argv);
    drawing = new bool[4];
    drawing[0] = true;
    drawing[1] = false;
    drawing[2] = false;
    drawing[3] = false;
    glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/4, glutGet(GLUT_SCREEN_HEIGHT)/4);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/2, glutGet(GLUT_SCREEN_HEIGHT)/2);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Goal - SURVIVE");
    setupAudio();
    setup();
    glutDisplayFunc(update);
    glutIdleFunc(update);
    glutKeyboardFunc(kP);
    glutKeyboardUpFunc(kU);
    glutSpecialFunc(sP);
    glutSpecialUpFunc(sU);
    c = new Controls();
    obj = new ObjectManager(glutGet(GLUT_WINDOW_X), glutGet(GLUT_WINDOW_Y), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutMainLoop();
    return 0;
}

