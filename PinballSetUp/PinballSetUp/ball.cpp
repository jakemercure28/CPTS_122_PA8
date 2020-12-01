#include "ball.h"

ball::ball(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	ballShape.setRadius(30);
	ballShape.setPosition(position);
}

Vector2f ball::getposition()
{
	return position;
}

CircleShape ball::getShape()
{
	return ballShape;
}
