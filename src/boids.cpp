//
//  boids.cpp
//  Flocking
//
//  Created by sonir on 4/12/15.
//
//

#include "boids.h"

void Boids::setup(){
    
    for (int i = 0; i < FLOY_MAX; i++){
        floy myfloy;
        myfloy.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
        floys.push_back(myfloy);
    }
    
}

void Boids::update(int mouseX, int mouseY){
    for (int i = 0; i < floys.size(); i++){
        floys[i].cohesion.distance = cohesion;
        floys[i].alignment.distance = alignment;
        floys[i].seperation.distance = separation;
        
        floys[i].cohesion.strength = cohesion_strength;
        floys[i].alignment.strength = alignment_strength;
        floys[i].seperation.strength = separation_strength;        
        floys[i].damping = damping;
        
    }
    
    
    // on every frame
    // we reset the forces
    // add in any forces on the floy
    // perfom damping and
    // then update
    
    for (int i = 0; i < floys.size(); i++){
        floys[i].resetForce();
    }
    
    for (int i = 0; i < floys.size(); i++){
        for (int j = 0; j < floys.size(); j++){
            if (i != j){
                floys[i].addForFlocking(floys[j]);
            }
        }
        
        
        
        // this was something we tried in class (partitcle move away from mouse...)
        floys[i].addRepulsionForce(mouseX, mouseY, 40, 0.4);
    }
    
    for (int i = 0; i < floys.size(); i++){
        floys[i].addFlockingForce();
        floys[i].addDampingForce();
        floys[i].update();
    }
    
    
    // wrap torroidally.
    for (int i = 0; i < floys.size(); i++){
        ofVec2f pos = floys[i].pos;
        if (pos.x < 0) pos.x = ofGetWidth();
        if (pos.x > ofGetWidth()) pos.x = 0;
        if (pos.y < 0) pos.y = ofGetHeight();
        if (pos.y > ofGetHeight()) pos.y = 0;
        floys[i].pos = pos;
    }

    
}

void Boids::draw(){

    ofSetColor(brightness);
    
    for (int i = 0; i < floys.size(); i++){
        floys[i].draw();
    }
    
}

void Boids::reset(){
    
    // reposition everything:
    for (int i = 0; i < floys.size(); i++){
        floys[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
    }

    
}

void Boids::dragged(int x, int y){
    
    if (x < (FLOY_MAX*0.8)){
        floys.erase(floys.begin());
        floy myfloy;
        float randomAngle = ofRandom(0, TWO_PI);
        myfloy.setInitialCondition(x,y,cos(randomAngle),sin(randomAngle));
        floys.push_back(myfloy);
    }
    
}