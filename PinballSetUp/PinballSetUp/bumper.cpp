#include "bumper.h"

bumper::bumper(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	bumper_shape.setRadius(45);
	bumper_shape.setPosition(position);
	
}

Vector2f bumper::getposition()
{
	return position;
}

CircleShape bumper::getShape()
{
	return bumper_shape;
}