#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    hp.setup( "/dev/tty.usbserial-A10172HG" );
    
    // notice in the main.cpp file that the window dimensions are the same ratio as 11x17
    // if you want to change the input width or height ( defaults to window dimensions) //
    // be sure to call setInputWidth and setInputHeight to the width and height
    // of the input area that you will be using. The defaults are ofGetWidth() and ofGetHeight()
    
    hp.load("hpgl.ofxhpgl");
}

//--------------------------------------------------------------
void ofApp::update() {
    
    hp.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    hp.draw();
    polyline.draw();
    
    ofSetColor( hp.isConnected() ? ofColor( 20, 230, 10 ) : ofColor( 220, 10, 50 ) );
    ofDrawCircle( 20, 20, 4 );
    
    stringstream ss;
    ss << "isConnected: " << (hp.isConnected() ? "yes" : "no") << endl;
    ss << "save(s)" << endl;
    ss << "print(p) " << endl;
    ss << "clear(DEL)" << endl;
    ofSetColor( 30 );
    ofDrawBitmapString( ss.str(), 30, 22 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'p' ) {
        hp.clear();
        hp.print();
    }
    if( key == 127 ) {
        polyline.clear();
        hp.clear();
    }
    if( key == 's' ) {
        hp.save( "hpgl.ofxhpgl" );
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    polyline.addVertex( x, y );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    polyline.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if( polyline.getPerimeter() > 10 ) {
        polyline = polyline.getResampledBySpacing( 8 );
        
        hp.polyline( polyline );
        polyline.clear();
    }
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