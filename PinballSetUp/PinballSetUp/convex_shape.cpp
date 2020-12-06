#include "convex_shape.h"

// default constructor
convex_shape::convex_shape()
{}

convex_shape::convex_shape(int point_count, Color init_color)
{
	convex_shape_object.setFillColor(init_color);
	convex_shape_object.setPointCount(point_count);
}

ConvexShape convex_shape::getShape()
{
	return convex_shape_object;
}

void convex_shape::set_point_convex(int size, Vector2f location)
{
	convex_shape_object.setPoint(size, location);
}
