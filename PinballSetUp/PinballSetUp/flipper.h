#ifndef FLIPPER_H
#define FLIPPER_H

#include <SFML/graphics.hpp>

using namespace sf;
class flipper
{
private:
	Vector2f position;
	ConvexShape flipperShape;
	float rotation;
	bool rotDir;

public:

	flipper(float initX, float initY, float initRot,bool direction);
	Vector2f getposition();
	ConvexShape getShape();
	float getRotation();
	void rotateFlipper(bool);
	void update();


};

#endif