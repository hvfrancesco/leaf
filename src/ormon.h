#pragma once

#include "ofMain.h"
#include "ofGraphics.h"


class Ormon
{

public:
    Ormon()
    {
    }
    void setup(ofPoint center, float radius);
    void update();
    void draw();
    int x;
    int y;

};
