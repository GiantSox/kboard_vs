#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	kinect.initSensor();
	//kinect.initIRStream(640, 480);
	kinect.initColorStream(640, 480, true);
	kinect.initDepthStream(640, 480, true);
	kinect.initSkeletonStream(false);

	//simple start
	kinect.start();
	ofDisableAlphaBlending(); //Kinect alpha channel is default 0;
	ofSetWindowShape(1280, 480);
}

//--------------------------------------------------------------
void ofApp::update() {
	kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//kinect.draw(640, 0);
	//kinect.draw(0, 0);
	kinect.drawDepth(0, 0);

	ofPushStyle();
	ofSetColor(255, 0, 0);
	ofSetLineWidth(3.0f);
	auto skeletons = kinect.getSkeletons();
	for (auto & skeleton : skeletons) {
		for (auto & bone : skeleton) {
			/*switch (bone.second.getTrackingState()) {
			case SkeletonBone::Inferred:
				ofSetColor(0, 0, 255);
				break;
			case SkeletonBone::Tracked:
				ofSetColor(0, 255, 0);
				break;
			case SkeletonBone::NotTracked:
				ofSetColor(255, 0, 0);
				break;
			}*/

			/*auto index = bone.second.getStartJoint();
			auto connectedTo = skeleton.find((_NUI_SKELETON_POSITION_INDEX)index);*/

			auto blabla = skeleton.find(NUI_SKELETON_POSITION_HEAD);
			cout << blabla->second.getScreenPosition().x << ", " << blabla->second.getScreenPosition().y << endl;
			/*if (connectedTo != skeleton.end()) {
				ofLine(connectedTo->second.getScreenPosition(), bone.second.getScreenPosition());
			}*/

			ofCircle(bone.second.getScreenPosition(), 10.0f);
		}
	}
	ofPopStyle();



	/*//auto skels = kinect.getSkeletons();
	for (auto & cSkel : kinect.getSkeletons())
	{
	auto idex = cSkel[]
	auto myHead = cSkel.find();
	ofPoint point;
	point.set(0, 0);
	ofLine(myHead->second.getScreenPosition(), point);
	//ofPoint headScreenPos = myHeadSecond.getScreenPosition();
	}*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
