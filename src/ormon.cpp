# include "ormon.h"

void Ormon::setup(ofPoint center, float radius)
{

x = center.x + ofRandom(-radius, radius);
y = center.y + ofRandom(-radius, radius);

}

void Ormon::update()
{

}

void Ormon::draw()
{

    ofCircle(x, y, 4);

}
