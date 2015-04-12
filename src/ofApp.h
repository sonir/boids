#pragma once

#define SC_WIDTH 1280
#define SC_HEIGHT 720
#define CAM_POSI_X 0.0
#define CAM_POSI_Y 0.0
#define CAM_POSI_Z 0.0
#define CAM_POSI_Z_MAX 1000.0

#define BLUR 255

#include "ofMain.h"
#include "slAppManager.h"
#include "Boids.h"
#include "OscManager.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    //Camera Control
    float cam_posi_x = CAM_POSI_X;
    float cam_posi_y = CAM_POSI_Y;
    float cam_posi_z = CAM_POSI_Z;
    //Color Control
    float blur = BLUR;
    
    //OSC Event
    OscManager osc;
    void setCoStr(float &val);
    void setCohesion(float &val);
    void setAlStr(float &val);
    void setAlign(float &val);
    void setSpStr(float &val);
    void setSeparation(float &val);
    void setDamping(float &val);
    
    void setPointX(float &val);
    void setPointY(float &val);
    void setGenerate(float &val);
    void setCamZ(float &val);
    void setCamX(float &val);
    void setCamY(float &val);
    void setBrightness(float &val);
    void setBlur(float &val);
    void setSize(float &val);
    int pointX = 0;
    int pointY = 0;
    
    Boids boids;
    
    
    //VideoCapture
    void audioIn(float *input, int bufferSize, int nChannels);
    ofFbo cap;
    ofPixels p;
    ofImage *img;
    ofxVideoRecorder    vidRecorder;
    ofSoundStream       soundStream;
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    
    ofFbo recordFbo;
    ofPixels recordPixels;
    ofPixels converted;
    void convertPixels();

    
    
};
