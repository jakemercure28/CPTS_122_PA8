#include "ball.h"
#include <cmath>
#include <iostream>
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

Vector2f ball::getOrigin()
{
	return Vector2f(ballShape.getPosition().x + ballShape.getRadius(),
		ballShape.getPosition().y + ballShape.getRadius());
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
	Vector2f originA = getOrigin();

	// Circle to Vertex Collision
	for (int i = 0; i < shape.getPointCount();i++)
	{
		Vector2f rotatedPoint = rotatePoint(shape.getPoint(i), shape.getRotation());
		float xDiff = (originA.x - (rotatedPoint.x + shape.getPosition().x));
		float yDiff = (originA.y - (rotatedPoint.y + shape.getPosition().y));

		float distance = sqrt(xDiff * xDiff + yDiff * yDiff);
		if (distance < ballShape.getRadius())
		{
			Vector2f normal = Vector2f(xDiff / distance, yDiff / distance);
			float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
			Vector2f int1 = (2 * ddotn) * normal;
			Velocity = Velocity - int1;
			break;
		}
	}

	int j;
	// Circle to Line Collision
	for (int i = 0; i < shape.getPointCount();i++)
	{

		if (i == 0)
			j = shape.getPointCount() - 1;
		else
			j = i - 1;
		// Calculate actual location of point
		Vector2f linePt1 = rotatePoint(shape.getPoint(i), shape.getRotation()) + shape.getPosition();
		Vector2f linePt2 = rotatePoint(shape.getPoint(j), shape.getRotation()) + shape.getPosition();

		float length = distance(linePt1, linePt2);
		float dotp = (((originA.x - linePt1.x) * (linePt2.x - linePt1.x)) +
			((originA.y - linePt1.y) * (linePt2.y - linePt1.y))) / (length * length);

		Vector2f closestPoint = Vector2f((linePt1.x + (dotp * (linePt2.x - linePt1.x))), (linePt1.y + (dotp * (linePt2.y - linePt1.y))));
		if (!linePoint(linePt1, linePt2, closestPoint))
			continue;
		float trueDistance = distance(originA, closestPoint);
		if (trueDistance <= ballShape.getRadius())
		{
			Vector2f normal = Vector2f((originA.x - closestPoint.x) / trueDistance, (originA.y - closestPoint.y) / trueDistance);
			float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
			Vector2f int1 = (2 * ddotn) * normal;
			Velocity = Velocity - int1;
		}
	}

}

void ball::collision(CircleShape shape)
{

	Vector2f originA = getOrigin();
	Vector2f originB = Vector2f(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());

	float xDiff = (originA.x - originB.x);
	float yDiff = (originA.y - originB.y);
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
		Vector2f  int1 = (2 * ddotn) * normal;
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
	ApplyGravity(Vector2f(0.f, 0.001f));
	position = position + getVelocity();
	ballShape.setPosition(position);
}

void ball::launch(int setting)
{

	if (setting == 1) {
		ApplyGravity(Vector2f(0.f, -.01f));
		position = position + getVelocity();
		ballShape.setPosition(position);

	}
	else if (setting == 2) {
		ApplyGravity(Vector2f(0.f, -.02f));
		position = position + getVelocity();
		ballShape.setPosition(position);
	}
	else if (setting == 3) {
		ApplyGravity(Vector2f(0.f, -.04f));
		position = position + getVelocity();
		ballShape.setPosition(position);
	}
}

Vector2f ball::rotatePoint(Vector2f point, float angle)
{

	float s = sin(angle * PI / 180);
	float c = cos(angle * PI / 180);

	Vector2f rotatedPoint = Vector2f(point.x * c - point.y * s, point.x * s + point.y * c);
	return rotatedPoint;
}

bool ball::linePoint(Vector2f lineP1, Vector2f lineP2, Vector2f point)
{
	float dist1 = distance(point, lineP1);
	float dist2 = distance(point, lineP2);

	float lineLength = distance(lineP1, lineP2);

	if ((dist1 + dist2) >= lineLength - 0.1f && dist1 + dist2 <= lineLength + 0.1f)
		return true;
	else
		return false;
}

float ball::distance(Vector2f point1, Vector2f point2)
{
	float xDiff = point1.x - point2.x;
	float yDiff = point1.y - point2.y;
	float distance = sqrt(xDiff * xDiff + yDiff * yDiff);

	return distance;
}
