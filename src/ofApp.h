#pragma once

#include <vector>
#include "ofMain.h"
#include "ofxGui.h"

#include "tile.h"
#include "tileMaster.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofLight light;
		ofEasyCam cam;

		TileMaster tileMaster;

		tileDecor decor;

		unsigned short level[6*6] = {
			0, 0, 0, 0, 0, 0,
			0, 1, 1, 1, 1, 0,
			0, 1, 0, 0, 1, 0,
			0, 1, 1, 0, 1, 0,
			0, 0, 1, 1, 1, 1,
			0, 1, 1, 1, 1, 1
		};

		// gui
		ofxPanel gui;

		ofxButton checkerboardButton;
		ofxButton gradientButton;
		ofxButton noiseButton;
		ofxButton harshNoiseButton;

		ofParameter<float> islandMargin;
		ofParameter<float> yLevel;
		ofParameter<int> tileCount;
};
