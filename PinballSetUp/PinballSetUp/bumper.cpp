#include "bumper.h"

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

Vector2f bumper::getposition()
{
	return position;
}

CircleShape bumper::getShape()
{
	return circle_shape;
}