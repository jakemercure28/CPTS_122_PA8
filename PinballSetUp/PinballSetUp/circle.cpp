#include "circle.h"

//Description: This is the .cpp(source) file for the circle class, which contains the definitions for
//the functionalities used to create the circle objects in our game


// default constructor
circle::circle()
{}

//copy constructor, used to initialize a circle of the given size and with the given position
circle::circle(int size, float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	circle_shape.setRadius(size);
	circle_shape.setPosition(position);
}

//this virtual function returns the position of the circle
Vector2f circle::getposition()
{
	return position;
}

//this virtual function returns the CircleShape object
CircleShape circle::getShape()
{
	return circle_shape;
}
