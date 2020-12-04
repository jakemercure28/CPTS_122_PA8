#ifndef BUMPER_H
#define BUMPER_H

#include <SFML/Graphics.hpp>

using namespace sf;
class bumper
{
private:
	Vector2f position;
	CircleShape bumper_shape;

public:
	// constructor
	bumper(float initX, float initY);

	
	Vector2f getposition();
	CircleShape getShape();

	void ball_contact();
	void update();
};

#endif