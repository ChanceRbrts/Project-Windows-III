//
//  ObjectController.cpp
//  Project_Music
//
//  Created by Chance Roberts on 12/3/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ObjectController.h"
#include <math.h>

ObjectController::ObjectController(Instances* place, float sW, float sH){
    placeOfControl = place;
    last = place;
    scrW = sW;
    scrH = sH;
    bpm = 174;
    beatPattern1 = 91.5;
    endBeatPattern1 = 187.5;
    switchOne = false;
}

void ObjectController::update(double beat, Instances *player){
    if (beat >= 27 && prevBeat < 27){
        addObject(new Homing(wind[0].x+wind[0].w/4,wind[0].y,bpm,beat,28));
        addObject(new Homing(wind[0].x+wind[0].w*3/4,wind[0].y,bpm,beat,28));
        addObject(new Homing(wind[0].x+wind[0].w*3/8,wind[0].y,bpm,beat,29));
        addObject(new Homing(wind[0].x+wind[0].w*5/8,wind[0].y,bpm,beat,29));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*3/8,bpm,beat,34.5));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*3/8,bpm,beat,34.5));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*5/8,bpm,beat,36));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*5/8,bpm,beat,36));
    }
    else if (beat >= 43 && prevBeat < 43){
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h/4,bpm,beat,28+16));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*3/4,bpm,beat,28+16));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*3/8,bpm,beat,29+16));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*5/8,bpm,beat,29+16));
        addObject(new Homing(wind[0].x+wind[0].w/8,wind[0].y,bpm,beat,33+16));
        addObject(new Homing(wind[0].x+wind[0].w/8,wind[0].y+wind[0].h-8,bpm,beat,33+16));
        addObject(new Homing(wind[0].x+wind[0].w*3/8,wind[0].y,bpm,beat,34.5+16));
        addObject(new Homing(wind[0].x+wind[0].w*3/8,wind[0].y+wind[0].h-8,bpm,beat,34.5+16));
        addObject(new Homing(wind[0].x+wind[0].w*5/8,wind[0].y,bpm,beat,36+16));
        addObject(new Homing(wind[0].x+wind[0].w*5/8,wind[0].y+wind[0].h-8,bpm,beat,36+16));
    }
    else if (beat >= 59 && prevBeat < 59){
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h/4,bpm,beat,28+32));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*3/4,bpm,beat,28+32));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*3/8,bpm,beat,29+32));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*5/8,bpm,beat,29+32));
        addObject(new Homing(wind[0].x+wind[0].w-8-wind[0].w*3/8,wind[0].y,bpm,beat,34.5+32));
        addObject(new Homing(wind[0].x+wind[0].w-8-wind[0].w*3/8,wind[0].y+wind[0].h-8,bpm,beat,34.5+32));
        addObject(new Homing(wind[0].x+wind[0].w-8-wind[0].w*5/8,wind[0].y,bpm,beat,36+32));
        addObject(new Homing(wind[0].x+wind[0].w-8-wind[0].w*5/8,wind[0].y+wind[0].h-8,bpm,beat,36+32));
    }
    else if (beat >= 75 && prevBeat < 75){
        addObject(new Homing(wind[0].x+wind[0].w/4,wind[0].y+wind[0].h-8,bpm,beat,28+48));
        addObject(new Homing(wind[0].x+wind[0].w*3/4,wind[0].y+wind[0].h-8,bpm,beat,28+48));
        addObject(new Homing(wind[0].x+wind[0].w*3/8,wind[0].y+wind[0].h-8,bpm,beat,29+48));
        addObject(new Homing(wind[0].x+wind[0].w*5/8,wind[0].y+wind[0].h-8,bpm,beat,29+48));
        addObject(new Homing(wind[0].x+wind[0].w*1/8,wind[0].y+wind[0].h-8,bpm,beat,31+48));
        addObject(new Homing(wind[0].x+wind[0].w*7/8,wind[0].y+wind[0].h-8,bpm,beat,31+48));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*7/8,bpm,beat,33+48));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*7/8,bpm,beat,33+48));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*5/8,bpm,beat,34+48));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*5/8,bpm,beat,34+48));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*3/8,bpm,beat,35+48));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*3/8,bpm,beat,35+48));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h*1/8,bpm,beat,36+48));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h*1/8,bpm,beat,36+48));
        addObject(new Homing(scrW/2+12,wind[0].y,bpm,beat,40+48));
        addObject(new Homing(scrW/2+12,wind[0].y+wind[0].h-8,bpm,beat,40+48));
    }
    else if (beat >= beatPattern1 && prevBeat < beatPattern1 && beat < endBeatPattern1){
        if (beat >= 123.5){
            addObject(new Homing(wind[0].x+wind[0].w/4,wind[0].y,bpm,beat,beatPattern1+0.5));
            addObject(new Homing(wind[0].x+wind[0].w*3/4,wind[0].y,bpm,beat,beatPattern1+0.5));
            addObject(new Homing(wind[0].x+wind[0].w/4,wind[0].y+wind[0].h-8,bpm,beat,beatPattern1+0.5));
            addObject(new Homing(wind[0].x+wind[0].w*3/4,wind[0].y+wind[0].h-8,bpm,beat,beatPattern1+0.5));
        }
        if (beat <= 155){
            for (int a = 0; a < 8; a++){
                addObject(new StraightLine(wind[0].x+wind[0].w*(2*a+switchOne)/16,wind[0].y-wind[0].w/16,wind[0].w/16,wind[0].w/16,0,480));
            }
        }
        else{
            for (int a = 0; a < 4; a++){
                addObject(new StraightLine(wind[0].x+wind[0].w*(a%2)+wind[0].w*(2*switchOne-1)/32,wind[0].y+wind[0].h*(2*a+switchOne)/8,wind[0].w/32,wind[0].w/32,480*(1-2*((a)%2)),0));
            }
        }
        switchOne = !switchOne;
        beatPattern1 += 4;
    }
    else if ((beat >= 187.5 && beat <= 203.5 && ((int)(beat+0.5)%2 == 0) && (int)(prevBeat+0.5)%2 == 1) || (beat >= 203.5 && beat <= 215.5 && (int)(beat+0.5) > (int)(prevBeat+0.5))){
        addObject(new Homing(wind[0].x,wind[0].y,bpm,beat,beat+0.5));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y,bpm,beat,beat+0.5));
        addObject(new Homing(wind[0].x,wind[0].y+wind[0].h-8,bpm,beat,beat+0.5));
        addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h-8,bpm,beat,beat+0.5));
    }
    else if (beat >= 252 && beat <= 340){
        double h = fmod(beat,4);
        double prevH = fmod(prevBeat,4);
        double direction = M_PI*(((int)(beat))/4)/2;
        if (h < 1 && prevH > 1){
            if (cos(direction) > 0.5 || cos(direction) < -0.5)
                addObject(new StraightLine(wind[0].x+wind[0].w/2+(wind[0].w/2-((scrW-scrW*cos(direction))/2)/16)*-cos(direction),scrH,scrW/8,scrH,0,-scrH*(bpm/(60*4)),255,0,0));
            else addObject(new StraightLine((scrW-1)*sin(direction)*3/4,wind[0].y+wind[0].h*2/4+wind[0].h/2*sin(direction)-4,scrW,scrH/8,-scrW*sin(direction)*(bpm/(60*4)),0,255,0,0));
        }
        if (beat >= 284){
            if ((h >= 0.75 && prevH < 0.75) || (h >= 2.25 && prevH < 2.25)){
                addObject(new Homing(wind[0].x,wind[0].y,bpm,beat,beat+0.25));
                addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y,bpm,beat,beat+0.25));
                addObject(new Homing(wind[0].x,wind[0].y+wind[0].h-8,bpm,beat,beat+0.25));
                addObject(new Homing(wind[0].x+wind[0].w-8,wind[0].y+wind[0].h-8,bpm,beat,beat+0.25));
            }
        }
        if (beat >= 316){
            if (h < 1 && prevH > 1){
                for (int a = 0; a < 4; a++){
                    addObject(new StraightLine(wind[0].x+wind[0].w*(a%2)+wind[0].w*(2*switchOne-1)/32,wind[0].y+wind[0].h*(2*a+switchOne)/8,wind[0].w/32,wind[0].w/32,480*(1-2*((a)%2)),0));
                }
                switchOne = !switchOne;
            }
        }
    }
    else if (beat >= 348 && beat <= 408){
        double direction = (beat-348)*M_PI/16+beat*M_PI*M_PI*1.1;
        if (beat >= 380)
            addObject(new StraightLine(scrW/2-4,scrH*3/4-4,8,8,600*cos(direction),600*sin(direction),rand()%125+130,255,rand()%125));
        else
            addObject(new StraightLine(scrW/2-4,scrH*3/4-4,8,8,-600*cos(direction),600*sin(direction),rand()%125+130,255,rand()%125));
    }
    else if (beat >= 476 && beat <= 508){
        int h = (int)(beat/2);
        int prevH = (int)(prevBeat/2);
        if (h > prevH){
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)*((beat-476)/(508-476))/4,0,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)*((beat-476)/(508-476))/4+wind[0].w-8,0,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)*((beat-476)/(508-476))/4,wind[0].h-8,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)*((beat-476)/(508-476))/4+wind[0].w-8,wind[0].h-8,bpm,beat,beat+0.25));
            for (int i = 0; i < 8; i++){
                addObject(new StraightLine(scrW/4+scrW*sin(beat*M_PI/4)*((beat-476)/(508-476))/4+wind[0].w*i/8,0,16,16,0,600));
            }
        }
    }
    else if (beat >= 508 && beat <= 540){
        int h = (int)(beat*2);
        int prevH = (int)(prevBeat*2);
        if (beat <= 524){
            h = (int)(beat);
            prevH = (int)(prevBeat);
        }
        if (h > prevH){
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)/4,0,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)/4+wind[0].w-8,0,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)/4,wind[0].h-8,bpm,beat,beat+0.25));
            addObject(new Homing(scrW/4+scrW*sin(beat*M_PI/4)/4+wind[0].w-8,wind[0].h-8,bpm,beat,beat+0.25));
            for (int i = 0; i < 8; i++){
                addObject(new StraightLine(scrW/4+scrW*sin(beat*M_PI/4)/4+wind[0].w*i/8,0,16,16,0,600));
            }
        }
    }
    else if (beat >= 604 && prevBeat < 604){
        //1 0
        solidObjects = last;
        addSolidObject(scrW/2,wind[0].y,scrW/2,4);
        addSolidObject(scrW/2,wind[0].y,4,wind[0].h);
        addSolidObject(scrW/2,wind[0].y+wind[0].h-4,scrW/2,4);
        addSolidObject(scrW-4,wind[0].y,4,wind[0].h);
        //0 1
        addSolidObject(0,wind[0].y+wind[0].h,scrW/2,4);
        addSolidObject(0,wind[0].y+wind[0].h,4,scrH-(wind[0].y+wind[0].h));
        addSolidObject(0,scrH-4,scrW/2,4);
        addSolidObject(scrW/2-4,wind[0].y+wind[0].h-4,4,scrH-(wind[0].y+wind[0].h));
        ///1 1
        addSolidObject(scrW/2,wind[0].y+wind[0].h,scrW/2,4);
        addSolidObject(scrW/2,wind[0].y+wind[0].h,4,scrH-(wind[0].y+wind[0].h));
        addSolidObject(scrW/2,scrH-4,scrW/2,4);
        addSolidObject(scrW-4,wind[0].y+wind[0].h-4,4,scrH-(wind[0].y+wind[0].h));
        //"Players" that are added onto the other screens.
        addObject(new NonPlayer(0,0,scrW/2,(scrH/2)-wind[0].y,wind[0].y));
        addObject(new NonPlayer(0,1,scrW/2,(scrH/2)-wind[0].y,wind[0].y));
        addObject(new NonPlayer(1,0,scrW/2,(scrH/2)-wind[0].y,wind[0].y));
        addObject(new NonPlayer(1,1,scrW/2,(scrH/2)-wind[0].y,wind[0].y));
        switchOne = 0;
    }
    else if (beat >= 604 && beat <= 669){
        if (beat-(int)beat >= 0 && (int)beat > (int)prevBeat){
            addObject(new Homing(wind[0].x,wind[0].y,bpm,beat,beat));
        }
        else if (beat-(int)beat >= 0.25 && (int)(beat-0.25) > (int)(prevBeat-0.25)){
            addObject(new Homing(scrW-4,wind[0].y,bpm,beat,beat));
        }
        else if (beat-(int)beat >= 0.5 && (int)(beat-0.5) > (int)(prevBeat-0.5)){
            addObject(new Homing(scrW-4,scrH-4,bpm,beat,beat));
        }
        else if (beat-(int)beat >= 0.75 && (int)(beat-0.75) > (int)(prevBeat-0.75)){
            addObject(new Homing(wind[0].x,scrH-4,bpm,beat,beat));
        }
        if (beat >= 636){
            if ((int)(beat/2) > (int)(prevBeat/2)){
                for (int i = 0; i < 4; i++){
                    addObject(new StraightLine(0,wind[0].y+(wind[0].h)*(i*2+switchOne)/8,wind[0].h/16,wind[0].h/16,400,0,255,0,0));
                    addObject(new StraightLine(scrW/2+wind[0].w*(i*2+switchOne)/8,0,wind[0].h/16,wind[0].h/16,0,400,0,255,0));
                    addObject(new StraightLine(scrW-4,wind[0].y+wind[0].h+(wind[0].h)*(i*2+switchOne)/8,wind[0].h/16,wind[0].h/16,-400,0,0,0,255));
                    addObject(new StraightLine(wind[0].w*(i*2+switchOne)/8,scrH-4,wind[0].h/16,wind[0].h/16,0,-400,0,255,150));
                }
                switchOne = !switchOne;
            }
        }
        if ((beat >= 612 && prevBeat < 612) || (beat >= 644 && prevBeat < 644)){
            player->i->setF("x",(player->i->getF("x"))+scrW/2);
        }
        else if ((beat >= 620 && prevBeat < 620) || (beat >= 652 && prevBeat < 652)){
            player->i->setF("y",(player->i->getF("y"))+(scrH/2)-wind[0].y);
        }
        else if ((beat >= 628 && prevBeat < 628) || (beat >= 660 && prevBeat < 660)){
            player->i->setF("x",(player->i->getF("x"))-scrW/2);
        }
        else if ((beat >= 636 && prevBeat < 636) || (beat >= 668 && prevBeat < 668)){
            player->i->setF("y",(player->i->getF("y"))-(scrH/2)+wind[0].y);
        }
        if (beat >= 668 && prevBeat < 668){
            Instances *i = solidObjects;
            while(i){
                if (i->i->index == "Solid" || i->i->index == "Non-Player") i->next->i->setF("x",-12010);
                i = i->next;
            }
        }
    }
    else if (beat >= 676 && beat < 700){
        if (prevBeat < 676){
            addObject(new MultipleHoming(wind[0].x+wind[0].w/4,wind[0].y,174,676,2,12,scrW,scrH));
            addObject(new MultipleHoming(wind[0].x+wind[0].w*3/4,wind[0].y,174,676,2,12,scrW,scrH));
            addObject(new MultipleHoming(wind[0].x,wind[0].y+wind[0].h/4,174,676,2,12,scrW,scrH));
            addObject(new MultipleHoming(wind[0].x+wind[0].w-4,wind[0].y+wind[0].h/4,174,676,2,12,scrW,scrH));
        }
        if (int(beat)%2 == 0 && int(prevBeat)%2 == 1){
            for (int a = 0; a < 8; a++){
                addObject(new StraightLine(wind[0].x+wind[0].w*(2*a+switchOne)/16,wind[0].y-wind[0].w/16,wind[0].w/16,wind[0].w/16,0,480));
            }
            switchOne = !switchOne;
        }
    }
    else if (beat >= 716 && beat < 732){
        //Final stretch! :D
        if (prevBeat < 716){
            addObject(new MultipleHoming(wind[0].x, wind[0].y,174,708,2,7,scrW,scrH));
            addObject(new MultipleHoming(wind[0].x, wind[0].y+wind[0].h-4,174,708,2,7,scrW,scrH));
        }
        else if (prevBeat < 717 && beat >= 717){
            addObject(new MultipleHoming(wind[0].x+wind[0].w-4,wind[0].y,174,709,2,7,scrW,scrH));
            addObject(new MultipleHoming(wind[0].x+wind[0].w-4,wind[0].y+wind[0].h-4,174,709,2,7,scrW,scrH));
        }
        if (beat >= 724 && (int)(prevBeat*4) < (int)(beat*4)){
            addObject(new StraightLine(wind[0].x+wind[0].w*3*(cos(beat*M_PI))/4,wind[0].y-wind[0].h/8,wind[0].w/8,wind[0].w/8,0,600,rand()%100+100,rand()%100+50,rand()%50+25));
        }
    }
    prevBeat = beat;
    for (Instances* i = placeOfControl; i->next; i = i->next){
        if (i->next->i->getF("x") > scrW || i->next->i->getF("x")+i->next->i->getF("w") < 0 || i->next->i->getF("y") > scrH || i->next->i->getF("y")+i->next->i->getF("h") < 0){
            deleteNextObject(i);
            if (!(i->next)) break;
        }
    }
}

void ObjectController::addSolidObject(float X, float Y, float W, float H){
    //This SHOULD be unneccesary... But I gave up... :(
    Solid *s = new Solid(X,Y,W,H);
    /*s->setF("x",X);
    s->setF("y",Y);
    s->setF("w",W);
    s->setF("h",H);
    s->setF("dX",0);
    s->setF("dY",0);*/
    addObject(s);
}

void ObjectController::addObject(Instance *i){
    last->next = new Instances();
    last->next->i = i;
    last = last->next;
}

void ObjectController::deleteNextObject(Instances *i){
    Instances *del = i->next;
    if (i->next == last) last = i;
    i->next = i->next->next;
    delete del;
}

void ObjectController::updateWindow(Window *w){
    wind = w;
}
