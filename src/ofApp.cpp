#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(224);
    ofEnableNormalizedTexCoords();

    light.setPointLight();
    light.setDiffuseColor(ofColor(255)); //ofFloatColor(1.0, 1.0, 1.0));
    light.setAmbientColor(ofColor(75)); //ofFloatColor(0.3, 0.3, 0.3));
    light.setPosition(ofGetWidth() / 2,ofGetHeight() / 2, 500);

    tileMaster.setup(16384);

    gui.setup();

    gui.add(checkerboardButton.setup("Checkerboard", 16, 16));
    gui.add(gradientButton.setup("Gradient", 16, 16));
    gui.add(noiseButton.setup("Noise", 16, 16));
    gui.add(tileCount.set("tileCount", 1, 0, 1024));
    gui.add(islandMargin.set("islandMargin", 0, 0, 25));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();

    ofEnableLighting();
    light.enable();

    //ofDrawGrid(1, 10, true, false, true, false);

    ofSetColor(33);
    tileMaster.draw(vec3(0, 0, 0), islandMargin);
    tileMaster.setTileCount(tileCount);

    light.disable();
    ofDisableLighting();

    cam.end();
    ofDisableDepthTest();

    ofSetColor(0, 255, 0);
    ofDrawBitmapString(to_string(ofGetFrameRate()), ofGetWidth()/2, 20);

    gui.draw();
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
