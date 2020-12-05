#include "ConvexRect.h"

ConvexRect::ConvexRect(float initX, float initY,float width,float height ,float rotation)
{
	position.x = initX;
	position.y = initY;

	rectShape.setPointCount(4);
	rectShape.setPoint(0, Vector2f(0, 0));
	rectShape.setPoint(1, Vector2f(0, height));
	rectShape.setPoint(2, Vector2f(width, height));
	rectShape.setPoint(3, Vector2f(width, 0));
	rectShape.setFillColor(Color::White);
	rectShape.move(position);
	rectShape.rotate(rotation);

}

Vector2f ConvexRect::getposition()
{
	return position;
}

ConvexShape ConvexRect::getShape()
{
	return rectShape;
}
