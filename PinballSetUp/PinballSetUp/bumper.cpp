#include "bumper.h"

//Description: This is the .cpp (source) file for the bumper class, which contains the definitions of
//the functionalities used to create the circular bumpers in our game

//this is the constructor for our class
bumper::bumper(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	circle_shape.setRadius(45);
	circle_shape.setPosition(position);

	circle_shape.setFillColor(sf::Color::Black);
	circle_shape.setOutlineThickness(7);
	circle_shape.setOutlineColor(sf::Color::Red);
	
}

//this function returns the position vector of the bumper
Vector2f bumper::getposition()
{
	return position;
}

//this function returns the CircleShape bumper object
CircleShape bumper::getShape()
{
	return circle_shape;
}