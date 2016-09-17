//
//  Instance.h
//  Project_Music
//
//  Created by Chance Roberts on 11/27/15.
//  Copyright © 2015 Chance Roberts. All rights reserved.
//

#ifndef Instance_h
#define Instance_h
#include <string>
#include <vector>

class Instance{
protected:
    float x;
    float y;
    float dX;
    float dY;
    float w;
    float h;
    float hp;
    bool hasGravity;
    bool onGround;
    bool solid;
    bool immovable;
    bool harmful;
public:
    Instance();
    Instance(float X, float Y, float HP);
    ~Instance();
    virtual void updateWithPlayer(Instance* i, double deltaTime);
    virtual void gravity(double deltaTime);
    virtual void collision(Instance* o, double deltaTime);
    virtual void finishUpdate(double deltaTime);
    virtual void extraCollision(Instance* o, float colPoint);
    virtual void updateWithControls(bool *con, bool *conPressed, double deltaTime);
    virtual std::vector<std::string> draw();
    virtual float getF(std::string get);
    bool getB(std::string get);
    virtual void setF(std::string get, float set);
    void setB(std::string get, bool set);
    std::string index;
};

struct Instances{
    Instance *i;
    Instances *next;
};

#endif /* Instance_h */
