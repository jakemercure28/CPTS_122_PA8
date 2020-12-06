#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class circle
{
protected:
	Vector2f position;
	int radius_size;
	CircleShape circle_shape;

public:
	circle();

	circle(int size, float initX, float initY);

	virtual Vector2f getposition();
	virtual CircleShape getShape();

};
#endif