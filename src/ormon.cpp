# include "ormon.h"

void Ormon::setup(ofVec2f center, float radius)
{

dead = false;
float r = ofRandom(0, radius);
float angle = ofRandom(0, 2*PI);
position.x = center.x + (cos(angle)*r);
position.y = center.y + (sin(angle)*r);

}

void Ormon::update()
{

}

void Ormon::draw()
{
    ofSetHexColor(0xFFFFFF);
    ofCircle(position.x, position.y, 2);

}
