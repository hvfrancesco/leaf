# include "bud.h"

void Bud::setup(float x, float y, list<Bud> * buds)
{
    dead = false;
    velocity = 2.0;
    splitChance = 0.1;
    listBuds = buds;
    minDelta = 0.5;

    position.x = x;
    position.y = y;

    associatedOrmons = list<Ormon>();
    positions = list<ofVec2f>();

    ofVec2f currentPosition;
    currentPosition.x = position.x;
    currentPosition.y = position.y;
    positions.push_back(currentPosition);
}

void Bud::randomGenerate(ofVec2f center, float radius, list<Bud> * buds)
{
    dead = false;
    velocity = 2.0;
    splitChance = 0.1;
    listBuds = buds;
    minDelta = 0.5;

    float r = ofRandom(0, radius);
    float angle = ofRandom(0, 2*PI);
    //position.x = center.x + (cos(angle)*r); // for a bud internal to the circle
    //position.y = center.y + (sin(angle)*r); // for a bud internal to the circle
    position.x = center.x + (cos(angle)*radius); // for a bud internal on the circle
    position.y = center.y + (sin(angle)*radius); // for a bud internal on the circle

    associatedOrmons = list<Ormon>();
    positions = list<ofVec2f>();

    ofVec2f currentPosition;
    currentPosition.x = position.x;
    currentPosition.y = position.y;
    positions.push_back(currentPosition);
}

void Bud::update()
{
    if (!dead) {
    if (associatedOrmons.size()>0) {
    // check if we must split a new bud
    float splitCheck;
    splitCheck = ofRandom(0,1);
    if (splitCheck < splitChance) {
        Bud newBud;
        newBud.setup(position.x, position.y, listBuds);
        //newBud.associatedOrmons = associatedOrmons;
        listBuds->push_back(newBud);
    }
}

    ofVec2f directionSum;
    // finds vector to associated ormons

    for (list<Ormon>::iterator oi = associatedOrmons.begin(); oi != associatedOrmons.end(); oi++)
    {
        Ormon * o = &*oi;
        if (!o->dead){
            directionSum = directionSum + (o->position - position);
        }
    }
    directionSum.normalize();
    ofVec2f displacement = directionSum*velocity;
    if (displacement.length() > minDelta)
    {
        positions.push_back(position);
    }
    position += displacement;
    }
}

void Bud::draw()
{
    // draws bud trails
    /*
    for (list<ofVec2f>::iterator pi = positions.begin(); pi != positions.end(); pi++)
    {
        ofVec2f prevPos = *pi;
        ofSetHexColor(0x000000);
        ofFill();
        ofCircle(prevPos.x, prevPos.y, 2);
        ofNoFill();
    }
    */
    //ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    //ofSetColor(51,119,0,255);
    ofSetLineWidth(2.5);
    ofSetColor(0,0,0,100);
    ofEnableAlphaBlending();
    ofBeginShape();
    for (list<ofVec2f>::iterator pi = positions.begin(); pi != positions.end(); pi++)
    {
        ofVec2f prevPos = *pi;
        ofCurveVertex(prevPos.x, prevPos.y);
    }
    ofEndShape(false);
    ofSetLineWidth(1);
    ofDisableAlphaBlending();

    // draws bud
    ofEnableAlphaBlending();
    ofSetColor(152,25,0,100);
    ofFill();
    ofCircle(position.x, position.y, 2);
    ofNoFill();
    ofDisableAlphaBlending();

}

void Bud::drawLinks()
{
    // draws links to associated ormons
    ofEnableAlphaBlending();
    ofSetColor(200,50,0,20);
    for (list<Ormon>::iterator oi = associatedOrmons.begin(); oi != associatedOrmons.end(); oi++)
    {
        Ormon * o = &*oi;
        if (!o->dead){
            ofLine(position.x,position.y,o->position.x,o->position.y);
        }
    }
    ofDisableAlphaBlending();
}

void Bud::clearAssociatedOrmons()
{
    associatedOrmons.clear();
}
