#pragma once

#include "ofMain.h"
#include "ofGraphics.h"


class Ormon
{

public:
    Ormon()
    {
    }

    ofVec2f position;

    void setup(ofVec2f center, float radius);
    void update();
    void draw();

};
