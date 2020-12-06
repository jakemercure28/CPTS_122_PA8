#ifndef BAND_BUMPER_H
#define BAND_BUMPER_H

#include "convex_shape.h"

#include <SFML/graphics.hpp>
using namespace sf;

class band_bumper :convex_shape
{
private:
	Vector2f position;
	float rotation;
	bool is_activated;

public:
	band_bumper(float initX, float initY, float initRotation, bool active);
	Vector2f getposition();
	virtual ConvexShape getShape();
	void update();
	
};


#endif