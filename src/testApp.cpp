#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{

    ofSetBackgroundAuto(true);
    ofBackground(255,255,255);
    bBackground = false;
    bRecord = false;

    //deadIterations = 0;

    //hormonSize = 2;
    hormonDeadZoneRadius = 4;
    //budSize = 1;
    //growthStep = 5;
    //splitChance = 0.05;

    //margin = 50;
    numHormons = 10000;
    numBuds = 1;

    center.x = ofGetWindowWidth()/2;
    center.y = ofGetWindowHeight()/2;
    radius = ofGetWindowHeight()*0.4;
    ofSetCircleResolution(36);
    deadIterations = 0;

    ormons = list<Ormon>() ;
    buds = list<Bud>();

    for (int i = 0; i < numHormons; i++)
    {
        Ormon o;
        o.randomGenerate(center, radius);
        ormons.push_back(o);
    }

    for (int i = 0; i < numBuds; i++)
    {
        Bud b;
        b.randomGenerate(center, radius, &buds);
        buds.push_back(b);
    }


}

//--------------------------------------------------------------
void testApp::update()
{

    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud * b = &*bi;
        b->associatedOrmons.clear();
    }

    for (list<Ormon>::iterator oi = ormons.begin(); oi != ormons.end(); oi++)
    {
        Ormon * o = &*oi;
        if (!o->dead)
        {
            associateBud(o);
            o->update();
        }
    }

    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud * b = &*bi;
        b->update();
    }
}

//--------------------------------------------------------------
void testApp::draw()
{

    // draws background circle
    if (bBackground)
    {
        ofEnableAlphaBlending();
        ofSetColor(222,225,170,255);
        ofFill();
        ofCircle(center.x, center.y, radius);
        ofNoFill();
        ofDisableAlphaBlending();
    }

    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud * b = &*bi;
        b->drawLinks();
    }

    for (list<Ormon>::iterator oi = ormons.begin(); oi != ormons.end(); oi++)
    {
        Ormon * o = &*oi;
        o->draw();
    }

    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud * b = &*bi;
        b->draw();
    }

    if (bRecord) {
        ofSaveFrame();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}

void testApp::associateBud(Ormon * o)
{

    float minDist = 0;
    Bud * closestBud;
    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud * b = &*bi;
        ofVec2f distVector = o->position - b->position;
        float dist = distVector.length();
        if ((minDist == 0) || (dist < minDist))
        {
            closestBud = &*bi;
            minDist = dist;
        }
    }
    if (minDist < hormonDeadZoneRadius)
    {
        o->dead = true;
    }
    closestBud->associatedOrmons.push_back(*o);
}
