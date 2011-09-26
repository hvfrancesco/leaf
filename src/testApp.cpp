#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

        deadIterations = 0;

        //var buds;
        //var hormons;
        hormonSize = 2;
        hormonDeadZoneRadius = 10;
        budSize = 1;
        growthStep = 5;
        splitChance = 0.4;

        margin = 50;
        numHormons = 1000;
        center.x = ofGetWindowWidth()/2;
        center.y = ofGetWindowHeight()/2;
        radius = ofGetWindowHeight()*0.4;
        ofSetCircleResolution(36);
        deadIterations = 0;

        ormons = list<Ormon>() ;

        for (int i; i < numHormons; i++)
        {
            Ormon o;
            o.setup(center, radius);
            ormons.push_back(o);
        }


}

//--------------------------------------------------------------
void testApp::update(){


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

    ofSetHexColor(0xFFFFFF);

    for (list<Ormon>::iterator oi = ormons.begin(); oi != ormons.end(); oi++)
    {
        Ormon o = *oi;
        ofCircle(o.x, o.y, 1);
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
