#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	ofSerial serial;
	std::string data;
	
	float x;
	float y;
	bool button;
};
