#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    if(ofIsGLProgrammableRenderer()){
		fxaa.load("shadersGL3/fxaa");
	}
    
    ofFbo::Settings settings;
    settings.numSamples = 0; // also try 8, if your GPU supports it
    settings.useDepth = true;
    settings.width = ofGetWidth();
    settings.height = ofGetHeight();
    
    myFbo.allocate(settings);
    myAAFbo.allocate(settings);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myFbo.begin();
    ofClear(0, 0, 0,255);
    ofSetColor(ofColor::white);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofSpherePrimitive(100.f, 3).getMesh().drawWireframe();
    ofRotateZ(25);
    ofPopMatrix();
    myFbo.end();
    
    myAAFbo.begin();
    ofClear(0, 0, 0,255);
    fxaa.begin();
    myFbo.draw(ofVec2f(0,0));
    fxaa.end();
    myAAFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    myFbo.draw(ofVec2f(0-ofGetWidth()/3,0));
    myAAFbo.draw(ofVec2f(0+ofGetWidth()/3,0));
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
