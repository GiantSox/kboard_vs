#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	kinect.initSensor();
	kinect.initColorStream(640, 480, true);
	kinect.initDepthStream(640, 480, true);
	kinect.initSkeletonStream(false);
	kinect.start();
	ofDisableAlphaBlending();


	ofSetWindowShape(1280, 480);
}

//--------------------------------------------------------------
void ofApp::update() {
	kinect.update();


	one.update();
	better.update();
	faster.update();
	stronger.update();

	auto skeletons = kinect.getSkeletons();
	for (auto & skeleton : skeletons) {
		for (auto & bone : skeleton) {
			joints["head"] = skeleton.find(NUI_SKELETON_POSITION_HEAD)->second.getScreenPosition();

			joints["shoulder"] = skeleton.find(NUI_SKELETON_POSITION_SHOULDER_CENTER)->second.getScreenPosition();
			joints["leftShoulder"] = skeleton.find(NUI_SKELETON_POSITION_SHOULDER_LEFT)->second.getScreenPosition();
			joints["rightShoulder"] = skeleton.find(NUI_SKELETON_POSITION_SHOULDER_RIGHT)->second.getScreenPosition();

			joints["leftWrist"] = skeleton.find(NUI_SKELETON_POSITION_WRIST_LEFT)->second.getScreenPosition();
			joints["rightWrist"] = skeleton.find(NUI_SKELETON_POSITION_WRIST_RIGHT)->second.getScreenPosition();

			joints["spine"] = skeleton.find(NUI_SKELETON_POSITION_SPINE)->second.getScreenPosition();

			joints["hip"] = skeleton.find(NUI_SKELETON_POSITION_HIP_CENTER)->second.getScreenPosition();
			joints["leftHip"] = skeleton.find(NUI_SKELETON_POSITION_HIP_LEFT)->second.getScreenPosition();
			joints["rightHip"] = skeleton.find(NUI_SKELETON_POSITION_HIP_RIGHT)->second.getScreenPosition();

			joints["leftAnkle"] = skeleton.find(NUI_SKELETON_POSITION_ANKLE_LEFT)->second.getScreenPosition();
			joints["rightAnkle"] = skeleton.find(NUI_SKELETON_POSITION_ANKLE_RIGHT)->second.getScreenPosition();
		}
	}

	/*for (auto it = joints.begin(); it != joints.end(); it++)
	{
		it->second.x = it->second.x * 1.25;
		it->second.y = it->second.y * 1.25;
	}*/


	if ((joints["rightWrist"].x> one.lbX) && (joints["rightWrist"].x< one.rbX) && (joints["rightWrist"].y > one.tbY) && (joints["rightWrist"].y < one.bbY) && one.sp.isPlaying() == false)
	{
		one.setActive();
	}
	if ((joints["rightWrist"].x> better.lbX) && (joints["rightWrist"].x< better.rbX) && (joints["rightWrist"].y > better.tbY) && (joints["rightWrist"].y < better.bbY) && better.sp.isPlaying() == false)
	{
		better.setActive();
	}
	if ((joints["rightWrist"].x> faster.lbX) && (joints["rightWrist"].x< faster.rbX) && (joints["rightWrist"].y > faster.tbY) && (joints["rightWrist"].y < faster.bbY) && faster.sp.isPlaying() == false)
	{
		faster.setActive();
	}
	if ((joints["rightWrist"].x> stronger.lbX) && (joints["rightWrist"].x< stronger.rbX) && (joints["rightWrist"].y > stronger.tbY) && (joints["rightWrist"].y < stronger.bbY) && stronger.sp.isPlaying() == false)
	{
		stronger.setActive();
	}


}

//--------------------------------------------------------------
void ofApp::draw()
{
	kinect.draw(0,0);

	one.draw();
	better.draw();
	faster.draw();
	stronger.draw();

	ofPushStyle();
	ofSetColor(255, 0, 0);
	for (auto i = joints.begin(); i != joints.end(); i++)
	{
		if (i->first == "spine")
		{

		}
		else
		{
			ofDrawCircle(i->second, 5);
		}
	}
	ofDrawLine(joints["head"], joints["shoulder"]);
	ofDrawLine(joints["shoulder"], joints["hip"]);

	ofDrawLine(joints["shoulder"], joints["leftShoulder"]);
	ofDrawLine(joints["shoulder"], joints["rightShoulder"]);
	ofDrawLine(joints["leftShoulder"], joints["leftWrist"]);
	ofDrawLine(joints["rightShoulder"], joints["rightWrist"]);

	ofDrawLine(joints["hip"], joints["leftHip"]);
	ofDrawLine(joints["hip"], joints["rightHip"]);

	ofDrawLine(joints["leftHip"], joints["leftAnkle"]);
	ofDrawLine(joints["rightHip"], joints["rightAnkle"]);


	ofPopStyle();
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
