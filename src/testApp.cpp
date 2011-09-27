#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

        deadIterations = 0;

        hormonSize = 2;
        hormonDeadZoneRadius = 10;
        budSize = 1;
        growthStep = 5;
        splitChance = 0.4;

        margin = 50;
        numHormons = 1000;
        numBuds = 8;

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
            o.setup(center, radius);
            ormons.push_back(o);
        }

        for (int i = 0; i < numBuds; i++)
        {
            Bud b;
            b.setup(center, radius);
            buds.push_back(b);
        }


}

//--------------------------------------------------------------
void testApp::update(){



    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud b = *bi;
        b.update();
    }

    for (list<Ormon>::iterator oi = ormons.begin(); oi != ormons.end(); oi++)
    {
        Ormon o = *oi;
        if (!o.dead) {
            associateBud(o);
            o.update();
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    ofEnableAlphaBlending();

    ofSetHexColor(0xeeddaa);
    ofFill();
    ofCircle(center.x, center.y, radius);

    ofSetHexColor(0x000000);
    ofNoFill();
    ofCircle(center.x, center.y, radius);


    for (list<Ormon>::iterator oi = ormons.begin(); oi != ormons.end(); oi++)
    {
        Ormon o = *oi;
        o.draw();
    }

    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud b = *bi;
        b.draw();
    }

    ofDisableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::associateBud(Ormon o){

    float minDist = 0;
    Bud * closestBud;
    for (list<Bud>::iterator bi = buds.begin(); bi != buds.end(); bi++)
    {
        Bud b = *bi;
        ofVec2f distVector = o.position - b.position;
        float dist = distVector.length();
        if ((minDist == 0) || (dist < minDist)) {
            closestBud = &*bi;
            minDist = dist;
        }
    }
    closestBud->associatedOrmons.push_back(o);
}
