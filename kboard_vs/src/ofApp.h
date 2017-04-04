#pragma once

#include "ofMain.h"
#include "ofxKinectCommonBridge.h"
#include "button.h"

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



		ofxKinectCommonBridge kinect;
		map<string, ofPoint> joints;


		Button one = Button(200, 100, "harder.wav");
		Button better = Button(300, 100, "better.wav");
		Button faster = Button(400, 100, "faster.wav");
		Button stronger = Button(500, 100, "stronger.wav");

};
