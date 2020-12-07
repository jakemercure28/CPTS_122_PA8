#include "convex_shape.h"

// default constructor
convex_shape::convex_shape()
{}

// copy constructor, allows you to set the number of points and color of the convex_shape object
convex_shape::convex_shape(int point_count, Color init_color)
{
	convex_shape_object.setFillColor(init_color);
	convex_shape_object.setPointCount(point_count);
}

//returns the convex_shape object
ConvexShape convex_shape::getShape()
{
	return convex_shape_object;
}

//this function allows you to modify specific points of the convex_shape
void convex_shape::set_point_convex(int size, Vector2f location)
{
	convex_shape_object.setPoint(size, location);
}
