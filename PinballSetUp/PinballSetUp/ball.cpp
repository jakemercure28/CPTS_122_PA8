#include "ball.h"
#include "sound.h"


//Description: This is the .cpp (source) file for the ball class, which contains the definitions for
//the functionalities used to create the pinball in our pinball game.

//the constructor for the ball object
ball::ball(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	Velocity = Vector2f(0, 0);
	ballShape.setRadius(30);
	ballShape.setPosition(position);
}

//returns the position vector
Vector2f ball::getposition()
{
	return position;
}

//returns the ball object
CircleShape ball::getShape()
{
	return ballShape;
}

//returns the origin/center point of the ball
Vector2f ball::getOrigin()
{
	return Vector2f(ballShape.getPosition().x + ballShape.getRadius(),
		ballShape.getPosition().y + ballShape.getRadius());
}

//applies gravity to the ball's movement
void ball::ApplyGravity(Vector2f gravity)
{
	Velocity.x += gravity.x;
	Velocity.y += gravity.y;
}

//returns the ball's velocity
Vector2f ball::getVelocity()
{
	return Velocity;
}

//this function simulates the ball's collision against a ConvexShape object
//returns true if collision happened, false if not
bool ball::collision(ConvexShape shape)
{
	Vector2f originA = getOrigin();

	// Circle to Vertex Collision
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		Vector2f rotatedPoint = rotatePoint(shape.getPoint(i), shape.getRotation());
		float xDiff = (originA.x - (rotatedPoint.x + shape.getPosition().x));
		float yDiff = (originA.y - (rotatedPoint.y + shape.getPosition().y));

		float distance = sqrt(xDiff * xDiff + yDiff * yDiff);
		//if the distance between the ball and the shape is less than or equal to the radius, 
		//the ball is deflected off of it
		if (distance <= ballShape.getRadius())
		{
			Vector2f normal = Vector2f(xDiff / distance, yDiff / distance);
			float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
			Vector2f int1 = (2 * ddotn) * normal;
			Velocity = REBOUND * (Velocity - int1);
			return true; //true means that the collision did occur, this is used to increment the score
		}
	}

	int j;
	// Circle to Line Collision
	for (int i = 0; i < shape.getPointCount(); i++)
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
		//find the point closest to the ball, to see if the collision should happen
		Vector2f closestPoint = Vector2f((linePt1.x + (dotp * (linePt2.x - linePt1.x))), (linePt1.y + (dotp * (linePt2.y - linePt1.y))));
		if (!linePoint(linePt1, linePt2, closestPoint))
		{
			continue;
		}
		float trueDistance = distance(originA, closestPoint);
		//if the distance between the ball and the shape is less than or equal to the radius, 
		//the ball is deflected off of it
		if (trueDistance <= ballShape.getRadius())
		{
			Vector2f normal = Vector2f((originA.x - closestPoint.x) / trueDistance, (originA.y - closestPoint.y) / trueDistance);
			float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
			Vector2f int1 = (2 * ddotn) * normal;
			Velocity = REBOUND * (Velocity - int1);
			return true;//true means that the collision did occur, this is then used to increment score
		}
	}
	return false;

}

//this function simulates the ball's collision against a circlular object
//returns true if collision happened, false if not
bool ball::collision(CircleShape shape)
{
	Vector2f originA = getOrigin();
	Vector2f originB = Vector2f(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());

	float xDiff = (originA.x - originB.x);
	float yDiff = (originA.y - originB.y);
	float xSqr = xDiff * xDiff;
	float ySqr = yDiff * yDiff;

	float distance = sqrt(xSqr + ySqr);

	//if the distance between the circle shape and the ball is less than/equal to the sum of their
	//radii, the collision ocurs
	if (distance <= shape.getRadius() + ballShape.getRadius())
	{
		// r = d - 2(d*n)n
		// d is the velocity vector of the pinball
		// n is the normalized contact vector between the two circleshapes

		Vector2f normal = Vector2f(xDiff / distance, yDiff / distance);

		float ddotn = normal.x * Velocity.x + normal.y * Velocity.y;
		Vector2f  int1 = (2 * ddotn) * normal;
		Velocity = REBOUND * (Velocity - int1);
		return true;//true means that the collision did occur, this is then used to increment score
	}
	return false;
}

//this function allows the ball to 'bounce' off of the boundaries
void ball::hitboundary(FloatRect bound)
{
	if (position.x <= bound.left || position.x >= (bound.left + bound.width))
		Velocity.x *= -REBOUND; //reverses the x direction of the ball
	if (position.y <= bound.left || position.y >= (bound.top + bound.height))
		Velocity.y *= -REBOUND;//reverses the y direction of the ball
}

//updates the ball's position from its velocity
void ball::update()
{
	ApplyGravity(Vector2f(0.f, 0.0025f));
	position = position + getVelocity();
	ballShape.setPosition(position);
}


//rotates a point based on the inputted angle, and returns rotated point
Vector2f ball::rotatePoint(Vector2f point, float angle)
{

	double s = sin(angle * PI / 180);
	double c = cos(angle * PI / 180);

	Vector2f rotatedPoint = Vector2f(point.x * c - point.y * s, point.x * s + point.y * c);
	return rotatedPoint;
}

//checks if a point if present on the given line
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

//calculates the distance between two inputted points, and returns the float result
float ball::distance(Vector2f point1, Vector2f point2)
{
	float xDiff = point1.x - point2.x;
	float yDiff = point1.y - point2.y;
	float distance = sqrt(xDiff * xDiff + yDiff * yDiff);

	return distance;
}

//mutator function, sets the velocity vector of the ball with the inputted x and y values
void ball::setVelocity(float xvel, float yvel)
{
	Velocity.x = xvel;
	Velocity.y = yvel;
}

