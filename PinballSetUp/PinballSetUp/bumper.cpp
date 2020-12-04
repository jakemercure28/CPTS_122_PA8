#include "bumper.h"

bumper::bumper(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	bumper_shape.setRadius(45);
	bumper_shape.setPosition(position);

	bumper_shape.setFillColor(sf::Color::Black);
	bumper_shape.setOutlineThickness(7);
	bumper_shape.setOutlineColor(sf::Color::Red);
	
}

Vector2f bumper::getposition()
{
	return position;
}

CircleShape bumper::getShape()
{
	return bumper_shape;
}