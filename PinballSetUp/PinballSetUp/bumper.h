#ifndef BUMPER_H
#define BUMPER_H

#include "circle.h"

#include <SFML/Graphics.hpp>

using namespace sf;
class bumper :circle
{

public:
	// constructor
	bumper(float initX, float initY);

	
	virtual Vector2f getposition();
	virtual CircleShape getShape();

	void ball_contact();
	void update();
};

#endif 