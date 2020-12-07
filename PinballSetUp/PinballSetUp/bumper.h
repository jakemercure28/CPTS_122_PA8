#ifndef BUMPER_H
#define BUMPER_H

#include "circle.h"

#include <SFML/Graphics.hpp>

//Description: This is the header file for the bumper class, which contains the functionalities
// used to create the circular bumpers in our game


//INHERITANCE - bumper inherites from the circle base class, because these are circular bumpers

using namespace sf;
class bumper :circle
{

public:
	// constructor for the pumber object, taking inputs for the x and y coordinates of
	//the position of the bumper
	bumper(float initX, float initY);

	//virtual function returns the position of the circular bumper
	virtual Vector2f getposition();

	//virtual function returns the CircleShape bumper object
	virtual CircleShape getShape();

};

#endif 