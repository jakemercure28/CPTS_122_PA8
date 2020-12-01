#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

using namespace sf;
class ball
{
private:
	Vector2f position;
	CircleShape ballShape;

	float xVelocity = 0;
	float yVelocity = 0;

public:

	ball(float initX, float initY);
	Vector2f getposition();
	CircleShape getShape();

	float getVelocity();
	void hitbottom();
	void update();
};

#endif
