#ifndef BALL_H
#define BALL_H

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
	void hitbottom();
	void update();
};

#endif
