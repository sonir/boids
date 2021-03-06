//
//  boids.h
//  Flocking
//
//  Created by sonir on 4/12/15.
//
//

#ifndef __Flocking__boids__
#define __Flocking__boids__

#define PARAM_MAX 200.0f
#define DAMPING_MAX 0.5
#define COHESION_STRENGTH 0.47
#define COHESION 190.0
#define ALIGMENT_STRENGTH 0.5
#define ALIGMENT 72.0
#define SEPARATION_STRENGTH 0.5
#define SEPARATION 100.0
#define DAMPING 0.05
#define FLOY_SIZE 3
#define FLOY_SIZE_MAX 20.0f


#define FLOY_MAX 150
#define FLOY_NUM 50

#define BRIGHTNESS 255



#include <stdio.h>
#include "slAppManager.h"
#include "floy.h"


class Boids:public slAppManager {
    
    public:
    void setup();
    void update(int mouseX, int mouseY);
    void draw();
    void reset();
    void dragged(int x, int y);

    // let's make a vector of them
    vector <floy> floys;
    float floy_size = FLOY_SIZE;
    float cohesion = COHESION;
    float alignment = ALIGMENT;
    float separation = SEPARATION;
    float cohesion_strength = COHESION_STRENGTH;
    float alignment_strength = ALIGMENT_STRENGTH;
    float separation_strength = SEPARATION_STRENGTH;
    float damping = DAMPING;
    
    float brightness = BRIGHTNESS;
    
};

#endif /* defined(__Flocking__boids__) */
