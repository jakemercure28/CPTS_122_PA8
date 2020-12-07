#ifndef CONVEX_SHAPE_H
#define CONVEX_SHAPE_H


#include <SFML/Graphics.hpp>

using namespace sf;

//Description: This is the header file for the convex_shape class, which contains the functionalities
// used to create the convex_shape objects in our game

//this class is also the base class from which the band_bumper class inherits
class convex_shape
{
protected:
	//the ConvexShape object is also utilized by the band_bumper class
	ConvexShape convex_shape_object;

public:
	// default constuctor
	convex_shape();
	// copy constructor, allows you to set the number of points and color of the convex_shape object
	convex_shape(int point_count, Color init_color);

	//this function allows you to modify specific points of the convex_shape
	virtual void set_point_convex(int size, Vector2f location);

	//returns the convex_shape object
	virtual ConvexShape getShape();
};

#endif 