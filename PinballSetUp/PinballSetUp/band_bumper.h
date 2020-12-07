#ifndef BAND_BUMPER_H
#define BAND_BUMPER_H

#include "convex_shape.h"

#include <SFML/graphics.hpp>
using namespace sf;

//Description: This is the header file for the band_bumper, which contains the functionalities
// used to create the band bumpers in our game


//INHERITANCE - band_bumper inherites from the convex_shape base class
class band_bumper :convex_shape
{
private:
	//private cariables to track the bumper's position, it's rotation angle,
	//and if it has been activated
	Vector2f position;
	float rotation;
	bool is_activated;

public:
	//constructor for the band_bumper object
	band_bumper(float initX, float initY, float initRotation, bool active);


	//this virtual function returns the band_bumper ConvexShape
	virtual ConvexShape getShape();

	
};


#endif