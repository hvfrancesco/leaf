# include "bud.h"

void Bud::setup(ofVec2f center, float radius)
{
    dead = false;
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
    // draws links to associated ormons
    for (list<Ormon>::iterator oi = associatedOrmons.begin(); oi != associatedOrmons.end(); oi++)
    {
        Ormon o = *oi;
        ofSetHexColor(0xDDDDFF);
        ofLine(position.x,position.y,o.position.x,o.position.y);
    }

    // draws bud
    ofSetHexColor(0xAA3300);
    ofFill();
    ofCircle(position.x, position.y, 3);
    ofNoFill();

}
