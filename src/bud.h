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

    void setup(float x, float y, list<Bud> * buds);
    void randomGenerate(ofVec2f center, float radius, list<Bud> * buds);
    void update();
    void draw();
    void drawLinks();
    void clearAssociatedOrmons();

    bool dead;
    float velocity;
    float splitChance;
    float minDelta;

    list<Bud> * listBuds;
    list<Ormon> associatedOrmons;
    list<ofVec2f> positions;

};
