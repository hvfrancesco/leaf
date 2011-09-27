# include "bud.h"

void Bud::setup(ofVec2f center, float radius)
{
    position.x = center.x + ofRandom(-radius, radius);
    position.y = center.y + ofRandom(-radius, radius);

    associatedOrmons = list<Ormon>() ;

}

void Bud::update()
{

    associatedOrmons.clear();

}

void Bud::draw()
{
    ofSetHexColor(0xAA3300);
    ofFill();
    ofCircle(position.x, position.y, 3);
    ofNoFill();
}
