#include "ofApp.h"


//
// Implementation of FXAA for GLSL 1.5
// See: https://github.com/mrdoob/three.js/blob/master/examples/js/shaders/FXAAShader.js
//      https://github.com/neilmendoza/ofxPostProcessing/blob/master/src/FxaaPass.cpp
//      http://www.glge.org/demos/fxaa/
//
// Ivaylo Getov
// www.ivaylogetov.com
//


//--------------------------------------------------------------
void ofApp::setup(){
    
    if(ofIsGLProgrammableRenderer()){
		fxaa.load("shadersGL3/fxaa");
	}
    
    ofFbo::Settings settings;
    settings.numSamples = 0; // setting this to 0 turns of MSAA
    settings.useDepth = true;
    settings.width = ofGetWidth();
    settings.height = ofGetHeight();
    
    myFbo.allocate(settings);
    myAAFbo.allocate(settings);
    
    enableAA = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myFbo.begin();
    ofClear(0, 0, 0, 0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    
    ofRotateZ(-35);
    ofSetColor(0, 0, 255);
    ofRect(-120, -120, 240, 240);
    ofRotateZ(35);
    
    ofRotateZ(25);
    ofSetColor(255, 0, 0);
    ofRect(-40, -40, 80, 80);
    ofRotateZ(-25);

    ofSetColor(255);
    ofTranslate(0, -150);
    ofSpherePrimitive(100.f, 3).getMesh().drawWireframe();
    
    ofPopMatrix();
    myFbo.end();
    
    myAAFbo.begin();
    ofClear(0, 0, 0, 0);
    if (enableAA) {
        fxaa.begin();
    }
    myFbo.draw(ofVec2f(0,0));
    if (enableAA) {
        fxaa.end();
    }
    myAAFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    myFbo.draw(ofVec2f(0-ofGetWidth()/4,0));
    ofDrawBitmapStringHighlight("No Antialiasing", 0+ofGetWidth()/4-50, ofGetHeight()-100);
    
    myAAFbo.draw(ofVec2f(0+ofGetWidth()/4,0));
    if (enableAA) {
        ofDrawBitmapStringHighlight("FXAA", ofGetWidth()-ofGetWidth()/4, ofGetHeight()-100);
    } else {
        ofDrawBitmapStringHighlight("No Antialiasing", ofGetWidth()-ofGetWidth()/4-50, ofGetHeight()-100);
    }
    
    
    ofDrawBitmapStringHighlight("Press SPACEBAR to toggle", 50, 50);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        enableAA = !enableAA;
    }
}