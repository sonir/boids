//
//  OscManager.cpp
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#include "OscManager.h"

void OscManager::fireMessage(ofxOscMessage *m){
    
    
    if(m->getAddress() == "/co_str"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCoStr, fnum);
    }else if(m->getAddress() == "/cohesion"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCohesion, fnum);
        
    }else if(m->getAddress() == "/al_str"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgAlStr, fnum);
    }else if(m->getAddress() == "/align"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgAlign, fnum);
    }else if(m->getAddress() == "/sp_str"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgSpStr, fnum);
    }else if(m->getAddress() == "/separation"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgSeparation, fnum);
    }else if(m->getAddress() == "/damping"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgDamping, fnum);
    }else if(m->getAddress() == "/generate"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgGenerate, fnum);
    }else if(m->getAddress() == "/cam_z"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamZ, fnum);
    }else if(m->getAddress() == "/cam_x"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamX, fnum);
    }else if(m->getAddress() == "/cam_y"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamY, fnum);
    }else if(m->getAddress() == "/brightness"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgBrightness, fnum);
    }else if(m->getAddress() == "/blur"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgBlur, fnum);
    }
    

    
}