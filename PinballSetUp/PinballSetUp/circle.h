#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
using namespace sf;

//Description: This is the header file for the circle class, which contains the functionalities
// used to create the circle objects in our game

class circle
{
protected:
	//these variables are also utilized by the bumper class, which inherits from circle
	Vector2f position;
	int radius_size;
	CircleShape circle_shape;

public:
	//default constructor
	circle();

	//copy constructor, used to initialize a circle of the given size and with the given position
	circle(int size, float initX, float initY);

	//this virtual function returns the position of the circle
	virtual Vector2f getposition();

	//this virtual function returns the CircleShape object
	virtual CircleShape getShape();

};
#endif