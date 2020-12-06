#include "circle.h"

// default constructor
circle::circle()
{}

circle::circle(int size, float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	circle_shape.setRadius(size);
	circle_shape.setPosition(position);
}

Vector2f circle::getposition()
{
	return position;
}

CircleShape circle::getShape()
{
	return circle_shape;
}
