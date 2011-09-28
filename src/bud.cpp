# include "bud.h"

void Bud::setup(ofVec2f center, float radius)
{
    dead = false;
    velocity = 40.0;

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

    int counter = 0;
    ofVec2f directionSum;
    // finds vector to associated ormons
    for (list<Ormon>::iterator oi = associatedOrmons.begin(); oi != associatedOrmons.end(); oi++)
    {
        Ormon o = *oi;
        if (!o.dead){
            counter += 1;
            directionSum = directionSum+(o.position);
        }
    }
    ofVec2f directionAverage = directionSum / counter;
    ofVec2f currentPosition = position;

    positions.push_back(currentPosition);
    directionAverage.normalize();
    ofVec2f displacement = directionAverage*velocity;
    //cout << counter << endl;
    ofVec2f newPosition = position + displacement;
    position += displacement;
    cout << position.x << endl;

}

void Bud::draw()
{
    // draws links to associated ormons
    for (list<Ormon>::iterator oi = associatedOrmons.begin(); oi != associatedOrmons.end(); oi++)
    {
        Ormon o = *oi;
        ofSetHexColor(0xDDDDFF);
        if (!o.dead){
            ofLine(position.x,position.y,o.position.x,o.position.y);
        }
    }

    // draws bud
    ofSetHexColor(0xAA3300);
    ofFill();
    ofCircle(position.x, position.y, 3);
    ofNoFill();

}

void Bud::clearAssociatedOrmons()
{
    associatedOrmons.clear();
}
