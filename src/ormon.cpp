# include "ormon.h"

void Ormon::setup(ofVec2f center, float radius)
{

dead = false;
position.x = center.x + ofRandom(-radius, radius);
position.y = center.y + ofRandom(-radius, radius);

}

void Ormon::update()
{

}

void Ormon::draw()
{
    ofSetHexColor(0xFFFFFF);
    ofCircle(position.x, position.y, 2);

}
