#include "ball.h"

ball::ball(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	Velocity = Vector2f(0, 0);
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

void ball::ApplyGravity(Vector2f gravity)
{
	Velocity.x += gravity.x;
	Velocity.y += gravity.y;
}

Vector2f ball::getVelocity()
{
	return Velocity;
}

void ball::hitboundary(int width,int height)
{
	if ((position.x) >= (width- 2*ballShape.getRadius()) || position.x <= 0)
		Velocity.x *= -1.;

	if (position.y >= (height-2 * ballShape.getRadius()) || position.y <= 0)
		Velocity.y *= -1.;
}

void ball::update()
{
	ApplyGravity(Vector2f(0.f,-.01f));
	position = position + getVelocity();
	ballShape.setPosition(position);
}

