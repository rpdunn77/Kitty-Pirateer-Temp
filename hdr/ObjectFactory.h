// **********************************************
// Filename: MapHandler.h
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//
// 
//    
// ************************************************



#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_


#include "GameObject.h"
#include "Obstacle.h"



class ObjectFactory: public GameObject {

private:
	
	
    
public:
	static Obstacle createObstacle(int x, int y, int w, int h, int obsType);

	
	ObjectFactory(){};
	void update (){};
	void display (){};
	bool collide (Player *C){};
	~ObjectFactory(){};
	
};

#endif 
