#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		int deadIterations;

//var buds;
//var hormons;
        int hormonSize;
        int hormonDeadZoneRadius;
        int budSize;
        int growthStep;
        float splitChance;

        int margin;
        int numHormons;

        ofPoint center;
        float radius;


};
