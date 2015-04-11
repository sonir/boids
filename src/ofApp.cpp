#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setCoStr(float &val){

    boids.cohesion_strength = val;
    cout << "co_str: " << boids.cohesion_strength << endl;
    
}

//--------------------------------------------------------------
void ofApp::setCohesion(float &val){
    
    
    int scaled_num = (int)(val*(float)PARAM_MAX);
    boids.cohesion = scaled_num;
    cout << "cohesion: " << boids.cohesion << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setAlStr(float &val){

    boids.alignment_strength = val;
    cout << "al_str: " << boids.alignment_strength << endl;
    
}

//--------------------------------------------------------------
void ofApp::setAlign(float &val){
    
    int scaled_num = (int)(val*(float)PARAM_MAX);
    boids.alignment = scaled_num;
    cout << "alignment: " << boids.alignment << endl;
    
}

//--------------------------------------------------------------
void ofApp::setSpStr(float &val){

    boids.separation_strength = val;
    cout << "sp_str: " << boids.separation_strength << endl;
    
}

//--------------------------------------------------------------
void ofApp::setSeparation(float &val){
    
    int scaled_num = (int)(val*(float)PARAM_MAX);
    boids.separation = scaled_num;
    cout << "separation: " << boids.separation << endl;
    
}

//--------------------------------------------------------------
void ofApp::setDamping(float &val){
    
    float scaled_num = (val*DAMPING_MAX);
    boids.damping = scaled_num;
    cout << "separation: " << boids.damping << endl;
    
}


//--------------------------------------------------------------
void ofApp::setPointX(float &val){
    
//    int scaled_num = (int)(val*(float)ofGetWidth());
//    pointX = scaled_num;
//    cout << "PointX: " << pointX << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setPointY(float &val){
    
//    float h = (float)ofGetHeight();
//    int scaled_num = (int)( h-(h*val) );
//    pointY = scaled_num;
//    cout << "PointY: " << pointY << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setGenerate(float &val){
    
//    bool flg = (bool)val;
//    boids.atraction = flg;
//    if(flg){
//        cout << "attract_on" << endl;
//    }else {
//        cout << "attract_off" << endl;
//    }
    
    
}

//--------------------------------------------------------------
void ofApp::setCamZ(float &val){
    
    float scaled_num = val*CAM_POSI_Z_MAX;
    cam_posi_z = scaled_num;
    cout << "cam_posi_z: " << cam_posi_z << endl;
    
}

//--------------------------------------------------------------
void ofApp::setCamX(float &val){
    
//    float scaled_num = (val*(float)ofGetWidth()*-1);
    float scaled_num = ofMap(val, 0.0f, 1.0f, (float)ofGetWidth()/2, ((float)ofGetWidth()*-1)/2);
    cam_posi_x = scaled_num;
    cout << "cam_posi_z: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setCamY(float &val){
    
//    float scaled_num = (val*(float)ofGetHeight()*-1);
    float scaled_num = ofMap(val, 0.0f, 1.0f, (float)ofGetHeight()/2, ((float)ofGetHeight()*-1)/2);
    cam_posi_y = scaled_num;
    cout << "cam_posi_y: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setBrightness(float &val){
    
    //    float scaled_num = (val*(float)ofGetHeight()*-1);
    int scaled_num = (int)(val * 255.0f);
    boids.brightness = scaled_num;
    cout << "brightness: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setBlur(float &val){
    
    int scaled_num = 255-(int)(val * 255.0f);
    blur = scaled_num;
    cout << "blur: " << blur << endl;
    
}


 
//--------------------------------------------------------------
void ofApp::setup(){

    //Setup OSC Event Fire
    ofAddListener(osc.chgCoStr, this, &ofApp::setCoStr);
    ofAddListener(osc.chgCohesion, this, &ofApp::setCohesion);
    ofAddListener(osc.chgAlStr, this, &ofApp::setAlStr);
    ofAddListener(osc.chgAlign, this, &ofApp::setAlign);
    ofAddListener(osc.chgSpStr, this, &ofApp::setSpStr);
    ofAddListener(osc.chgSeparation, this, &::ofApp::setSeparation);
    ofAddListener(osc.chgDamping, this, &ofApp::setDamping);
    ofAddListener(osc.chgPointX, this, &ofApp::setPointX);
    ofAddListener(osc.chgPointY, this, &ofApp::setPointY);
    ofAddListener(osc.chgGenerate, this, &ofApp::setGenerate);
    ofAddListener(osc.chgCamZ, this, &ofApp::setCamZ);
    ofAddListener(osc.chgCamX, this, &ofApp::setCamX);
    ofAddListener(osc.chgCamY, this, &ofApp::setCamY);
    ofAddListener(osc.chgBrightness, this, &ofApp::setBrightness);
    ofAddListener(osc.chgBlur, this, &ofApp::setBlur);

    //Setup boids
    boids.setup();

    
}

//--------------------------------------------------------------
void ofApp::update(){

    boids.update(pointX, pointY);
    osc.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, blur); //半透明の黒（背景色）
    ofRect(0, 0, ofGetWidth(), ofGetHeight()); //画面と同じ大きさの四角形を描画
    
//    ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
    ofTranslate(cam_posi_x, cam_posi_y, cam_posi_z);
    boids.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {

        boids.reset();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    boids.dragged(x,y);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

//    boids.setAttraction(true);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
//    boids.setAttraction(false);
    
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
