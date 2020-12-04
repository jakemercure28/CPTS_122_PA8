#ifndef BALL_H
#define BALL_H
#define PI 3.14159265
#include <SFML/Graphics.hpp>

using namespace sf;
class ball
{
private:
	Vector2f position;
	CircleShape ballShape;
	Vector2f Velocity;

public:

	ball(float initX, float initY);
	Vector2f getposition();
	CircleShape getShape();
	void ApplyGravity(Vector2f gravity);
	Vector2f getVelocity();
	Vector2f getOrigin();
	void hitboundary(int width, int height);
	void update();
	void collision(CircleShape shape);
	void collision(ConvexShape shape);
	Vector2f rotatePoint(Vector2f point, float angle);
	float distance(Vector2f point1, Vector2f point2);
	bool linePoint(Vector2f lineP1, Vector2f lineP2, Vector2f point);
};

#endif
