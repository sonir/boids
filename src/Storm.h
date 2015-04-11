//
//  Storm.h
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#ifndef __Vector__Storm__
#define __Vector__Storm__

#define STORM_COLOR 255 //def:255
#define CONST_PARTICLE_MAX 10000 //Def 100000
#define ST_PARTICLE_NUM 600
#define ST_FRICTION 0.002 //def 0.002 , Range 0.-0.07
#define ST_FRICTION_MAX 0.01
#define ST_PARTICLE_SIZE .1 //def 1.0 , Range: .1 - 30.
#define PARTICLE_SIZE_MAX 50


#include <stdio.h>
#include "slAppManager.h"
#include "Particle.h"


class Storm : public slAppManager {
    
public:
    
    void setup();
    void update(int mouseX, int mouseY);
    void draw(int mouseX, int mouseY);
    void setAttraction(bool val);
    void setParticleNum(int inum);
    void updateParams();
    void reset();
    
    
    
    // パーティクルクラスをインスタンス化
    vector<Particle> particles;
    // メッシュ
    ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    // パーティクルの最大数
    static const int PARTICLE_MAX_NUM = CONST_PARTICLE_MAX;
    //Number of display particle
    int storm_particle_num;
    //particleの移動抵抗
    float storm_friction = ST_FRICTION;
    //Size of Particle
    GLfloat particle_size = ST_PARTICLE_SIZE;
    int storm_color = STORM_COLOR;
    
    
    
};
#endif /* defined(__Vector__Storm__) */
