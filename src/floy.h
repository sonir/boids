#ifndef floy_H
#define floy_H

#include "ofMain.h"

// C style 80s :)

typedef struct{
	int			count;
	ofVec2f	sum;
	float		distance;
	float		strength;
} flockingForce;
 

// C++ style 90s :)
/*
class flockingForce {
	public:
	
	int			count;
	ofVec2f	sum;
	float		distance;
	float		strength;
	
};
*/



class floy{

	public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        floy();
		virtual ~floy(){};

        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		
		void addRepulsionForce(floy &p, float radius, float scale);
		void addAttractionForce(floy &p, float radius, float scale);
		void addClockwiseForce(floy &p, float radius, float scale);
		void addCounterClockwiseForce(floy &p, float radius, float scale);
	
		void addDampingForce();
 
		void addForFlocking(floy &p);
		void addFlockingForce();
	
		flockingForce cohesion;
		flockingForce seperation;
		flockingForce alignment;
	
	
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw(float size);
	
		void bounceOffWalls();
	
		float damping;

    protected:
    private:
};

#endif // floy_H
