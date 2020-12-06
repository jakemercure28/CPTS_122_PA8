#ifndef CONVEX_SHAPE_H
#define CONVEX_SHAPE_H


#include <SFML/Graphics.hpp>

using namespace sf;

class convex_shape
{
protected:

	ConvexShape convex_shape_object;

public:
	// default constuctor
	convex_shape();
	// constructor 2
	convex_shape(int point_count, Color init_color);

	// set points for convex shape
	virtual void set_point_convex(int size, Vector2f location);

	virtual ConvexShape getShape();
};

#endif 