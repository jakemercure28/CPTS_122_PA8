#include "ConvexRect.h"


ConvexRect::ConvexRect(float initX, float initY,float width,float height ,float rotation,const Color color)
{
	// initializes the position vector to the inputs
	position.x = initX;
	position.y = initY;

	// creates the basic shape based upon height and width
	convex_shape_object.setPointCount(4);
	convex_shape_object.setPoint(0, Vector2f(0, 0));
	convex_shape_object.setPoint(1, Vector2f(0, height));
	convex_shape_object.setPoint(2, Vector2f(width, height));
	convex_shape_object.setPoint(3, Vector2f(width, 0));
	// color input is set
	convex_shape_object.setFillColor(color);
	// moves shape to initail position
	convex_shape_object.move(position);
	// rotates shape to initial position
	convex_shape_object.rotate(rotation);
}

Vector2f ConvexRect::getposition()
{
	return position;
}

ConvexShape ConvexRect::getShape()
{
	return convex_shape_object;
}
