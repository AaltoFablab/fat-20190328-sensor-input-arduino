#include "ofApp.h"

void ofApp::setup(){
	serial.listDevices();
	serial.setup("/dev/cu.usbmodem142401", 9600);
}

void ofApp::update(){
	unsigned char inBytes[3];
	unsigned char inString[4];
	
	while(serial.available()){
		memset(inBytes, 0, 3);
		memset(inString, 0, 4);
		serial.readBytes(inBytes, 3);
		memcpy(inString, inBytes, 3);
		data += ofToString(inString);
	}
	
	// 513,511,1\n513,511,1\n513,511,1\n513,511,1\n...
	// 513,511,1
	// ...
	while(data.find("\n") != std::string::npos){
		std::size_t found = data.find("\n");
		std::string line = data.substr(0, found);
		
		vector<std::string> fields = ofSplitString(line, ",");
		if(fields.size() >= 3){
			std::cout
				<< "x: " << fields[0] << ", "
				<< "y: " << fields[1] << ", "
				<< "button: " << fields[2]
				<< std::endl;
			
			x = ofToFloat(fields[0]) / 1024.0f * (float)ofGetWidth();
			y = ofToFloat(fields[1]) / 1024.0f * (float)ofGetHeight();
			button = ofToBool(fields[2]);
		}
		data.erase(0, found + 1);
	}
}

void ofApp::draw(){
	ofDrawBitmapString(data, 10, 20);
	
	ofPushStyle();
	if(button == true){
		ofSetColor(ofColor::white);
	}else{
		ofSetColor(ofColor::black);
	}
	ofDrawCircle(x, y, 20);
	ofPopStyle();
}
