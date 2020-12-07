#ifndef BALL_H
#define BALL_H

#define PI 3.14159265
#define REBOUND 1.00f
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;

//Description: This is the header file for the ball class, which contains the functionalities
//used to create the pinball in our pinball game.

class ball
{
private:
	//variables to represent the ball's position, shape, and velocity
	Vector2f position;
	CircleShape ballShape;
	Vector2f Velocity;

public:
	//the constructor for the ball object
	ball(float initX, float initY);

	//returns the position of the ball
	Vector2f getposition();

	//returns the ball object shape
	CircleShape getShape();

	//applies gravity to the ball's movement
	void ApplyGravity(Vector2f gravity);

	//returns the velocity of the ball
	Vector2f getVelocity();

	//returns the center point of the ball object
	Vector2f getOrigin();

	//this function allows the ball to 'bounce' off of the boundaries
	void hitboundary(FloatRect bound);

	//this function updates the ball's position
	void update();

	//this function simulates the ball's collision against a circlular object
	//returns true if collision happened, false if not
	bool collision(CircleShape shape);

	//this function simulates the ball's collision against a ConvexShape object
	//returns true if collision happened, false if not
	bool collision(ConvexShape shape);

	//rotate function to simulate ball rotation
	Vector2f rotatePoint(Vector2f point, float angle);

	//this function returns the distance between 2 points
	float distance(Vector2f point1, Vector2f point2);

	//this function is used to calculate the collisions
	bool linePoint(Vector2f lineP1, Vector2f lineP2, Vector2f point);

	//this function accepts 2 float variables which it sets as the ball's velocity
	void setVelocity(float xvel, float yvel);

};

#endif
