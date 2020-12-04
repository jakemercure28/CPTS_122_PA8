#ifndef BAND_BUMPER_H
#define BAND_BUMPER_H

#include <SFML/graphics.hpp>
using namespace sf;

class band_bumper
{
private:
	Vector2f position;
	ConvexShape band_bumper_shape;
	Color band_bumper_color;
	bool is_activated;

public:
	band_bumper(float initX, float initY, float initRotation, bool active);
	Vector2f getposition();
	ConvexShape getShape();

	void rotateUp();
	void rotateDown();
	void rotateFlipper(bool);
	void update();
	
};


#endif