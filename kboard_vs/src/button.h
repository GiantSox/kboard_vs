#pragma once
#include "ofMain.h"

class Button
{
public:
	int x = 0;
	int y = 0;

	int width = 50;
	int height = 50;

	int lbX = x;
	int rbX = x + width;
	int tbY = y;
	int bbY = y + width;


	string fp = "";
	ofSoundPlayer sp;



	Button(int topleftX, int topleftY, string filepath)
	{
		x = topleftX;
		y = topleftY;
		fp = filepath;
		sp.loadSound("hbfs/" + fp);
	}

	void update()
	{
		lbX = x;
		rbX = x + width;
		tbY = y;
		bbY = y + width;
	}
	void draw()
	{
		ofPushStyle();
		ofSetColor(0, 255, 0);
		ofDrawRectangle(x, y, height, width);
		ofSetColor(255, 0, 0);
		ofDrawBitmapString(fp, x, y);
		ofPopStyle();
	}
	void setActive()
	{
		sp.play();
	}


};
