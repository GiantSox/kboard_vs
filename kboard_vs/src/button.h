#pragma once


#include "ofMain.h"

class Button
{
public:
	int x = 0;
	int y = 0;

	int width = 100;
	int height = 100;

	int lbX = x;
	int rbX = x + width;
	int tbY = y;
	int bbY = y + width;



	Button(int topleftX, int topleftY)
	{
		x = topleftX;
		y = topleftY;
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
		ofSetColor(0, 255, 0);
		ofDrawRectangle(x, y, height, width);
	}

};
