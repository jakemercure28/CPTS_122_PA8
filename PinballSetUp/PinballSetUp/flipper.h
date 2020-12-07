#ifndef FLIPPER_H
#define FLIPPER_H
#define SPEED 10
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
class flipper
{
private:
	Vector2f position;
	ConvexShape flipperShape;
	float rotation;
	bool rotDir;
	Sound clack_sound;

public:
	// constructor
	flipper(float initX, float initY, float initRot,bool direction);
	// getters
	Vector2f getposition();
	ConvexShape getShape();
	float getRotation();
	// member functions
	void rotateUp();
	void rotateDown();
	void rotateFlipper(bool);


};

#endif