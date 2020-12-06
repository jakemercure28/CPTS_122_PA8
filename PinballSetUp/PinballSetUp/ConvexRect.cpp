#include "ConvexRect.h"

ConvexRect::ConvexRect(float initX, float initY,float width,float height ,float rotation,const Color color)
{
	position.x = initX;
	position.y = initY;

	convex_shape_object.setPointCount(4);
	convex_shape_object.setPoint(0, Vector2f(0, 0));
	convex_shape_object.setPoint(1, Vector2f(0, height));
	convex_shape_object.setPoint(2, Vector2f(width, height));
	convex_shape_object.setPoint(3, Vector2f(width, 0));
	convex_shape_object.setFillColor(color);
	convex_shape_object.move(position);
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
