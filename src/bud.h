#pragma once

#include "ofMain.h"
#include "ofGraphics.h"
#include "ormon.h"


class Bud
{

public:
    Bud()
    {
    }

    ofVec2f position;

    void setup(ofVec2f center, float radius);
    void update();
    void draw();
    void clearAssociatedOrmons();

    bool dead;
    float velocity;

    list<Ormon> associatedOrmons;
    list<ofVec2f> positions;

};
