#pragma once

#include "ofMain.h"
#include "ofGraphics.h"


class Ormon
{

public:
    Ormon()
    {
    }

    bool dead;
    ofVec2f position;

    void setup(float x, float y);
    void randomGenerate(ofVec2f center, float radius);
    void update();
    void draw();

};
