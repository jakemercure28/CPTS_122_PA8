#include "ball.h"
#include <cmath>
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

void ball::collision(ConvexShape shape)
{

}

void ball::collision(CircleShape shape)
{
	float originAx = ballShape.getPosition().x + ballShape.getRadius();
	float originAy = ballShape.getPosition().y + ballShape.getRadius();
	float originBx = shape.getPosition().x + shape.getRadius();
	float originBy = shape.getPosition().y + shape.getRadius();

	float xDiff = (originAx - originBx);
	float yDiff = (originAy - originBy);
	float xSqr = xDiff * xDiff;
	float ySqr = yDiff * yDiff;

	float distance = sqrt(xSqr + ySqr);

	if (distance <= shape.getRadius() + ballShape.getRadius())
	{
		// r = d - 2(d*n)n
		// d is the velocity vector of the pinball
		// n is the normalized contact vector between the two circleshapes

		Vector2f normal = Vector2f(xDiff / distance, yDiff / distance);

		float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
		Vector2f  int1 = (2* ddotn) * normal;
		Velocity = Velocity - int1;
	}
}

void ball::hitboundary(int width, int height)
{
	if ((position.x) >= (width - 2 * ballShape.getRadius()) || position.x <= 0)
		Velocity.x *= -1.;

	if (position.y >= (height - 2 * ballShape.getRadius()) || position.y <= 0)
		Velocity.y *= -1.;
}

void ball::update()
{
	ApplyGravity(Vector2f(0.f, -.01f));
	position = position + getVelocity();
	ballShape.setPosition(position);
}

