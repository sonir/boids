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
    cout << "dumping: " << boids.damping << endl;
    
}

//--------------------------------------------------------------
void ofApp::setSize(float &val){
    
    float scaled_num = val*FLOY_SIZE_MAX;
    boids.floy_size = scaled_num;
    cout << "size: " << boids.floy_size << endl;
    
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

    ofSetFrameRate(30);
    
    
    //SetupVideoCapture
    sampleRate = 44100;
    channels = 2;
    ofSetLogLevel(OF_LOG_VERBOSE);
    fileName = "testMovie";
    fileExt = ".mov"; // ffmpeg uses the extension to determine the container type. run 'ffmpeg -formats' to see supported formats
    
    // override the default codecs if you like
    // run 'ffmpeg -codecs' to find out what your implementation supports (or -formats on some older versions)
    vidRecorder.setVideoCodec("mpeg4");
    vidRecorder.setVideoBitrate("3200k"); //def is 800k
    vidRecorder.setAudioCodec("mp3");
    vidRecorder.setAudioBitrate("192k");
    
//        soundStream.listDevices();
//        soundStream.setDeviceID(0);
    soundStream.setup(this, 0, channels, sampleRate, 256, 4);
    
    bRecording = false;
    ofEnableAlphaBlending();
    
    //Setup FBO
    cap.allocate(SC_WIDTH,SC_HEIGHT);
    cap.begin();
    ofClear(0, 0, 0);
    cap.end();
    //    img = new ofImage;
    //Set Image time for RGB (without RGBA)
    converted.setImageType(OF_IMAGE_COLOR);


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
    ofAddListener(osc.chgSize, this, &ofApp::setSize);
    
    //Setup boids
    boids.setup();

    
}

//--------------------------------------------------------------
void ofApp::update(){

    boids.update(pointX, pointY);
    osc.update();
    
    if(bRecording){
        cap.readToPixels(recordPixels);
        convertPixels();
        vidRecorder.addFrame(converted);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    cap.begin();
    
    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, blur); //半透明の黒（背景色）
    ofRect(0, 0, ofGetWidth(), ofGetHeight()); //画面と同じ大きさの四角形を描画
    
//    ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
    ofTranslate(cam_posi_x, cam_posi_y, cam_posi_z);
    boids.draw();

    cap.end();
    cap.draw(0,0);
    if(bRecording){
        ofSetColor(255, 0, 0);
        ofCircle(ofGetWidth() - 20, 20, 5);
    }
    
    // ログを表示
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    
    
    
}

void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if(bRecording){
        vidRecorder.addAudioSamples(input, bufferSize, nChannels);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {

        boids.reset();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key=='r'){
        bRecording = !bRecording;
        if(bRecording && !vidRecorder.isInitialized()) {
            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, SC_WIDTH, SC_HEIGHT, 30, sampleRate, channels);
        }
    }
    if(key=='c'){
        bRecording = false;
        vidRecorder.close();
    }

    
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

//--------------------------------------------------------------
void ofApp::convertPixels(){
    
    
    //Make Array for treating each pixcels
    unsigned char * pixels = recordPixels.getPixels();
    unsigned char pixs2[SC_WIDTH*SC_HEIGHT*3];
    
    for(int i = 0; i < SC_WIDTH*SC_HEIGHT; i++)
    {
        pixs2[i*3]   = pixels[i*4];
        pixs2[i*3+1] = pixels[i*4+1];
        pixs2[i*3+2] = pixels[i*4+2];
    }
    
    //Copy the pixels into converted buffer with 3channel
    converted.setFromExternalPixels(pixs2, SC_WIDTH, SC_HEIGHT, 3);
    
}

