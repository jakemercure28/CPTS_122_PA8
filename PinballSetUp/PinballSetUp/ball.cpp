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
	Velocity = Velocity + gravity;
}

Vector2f ball::getVelocity()
{
	return Velocity;
}

void ball::hitbottom()
{

}

void ball::update()
{
	ApplyGravity(Vector2f(0.f,-.01f));
	position = position + getVelocity();
	ballShape.setPosition(position);
}

