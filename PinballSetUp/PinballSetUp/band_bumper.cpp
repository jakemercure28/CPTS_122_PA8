#include "band_bumper.h"

band_bumper::band_bumper(float initX, float initY, float initRotation, bool active)
{
	position.x = initX;
	position.y = initY;
	is_activated = active;
	rotation = 0;

	band_bumper_shape.setPointCount(6);
	band_bumper_shape.setPoint(0, sf::Vector2f(0, 0));
	band_bumper_shape.setPoint(1, sf::Vector2f(-10, -10));
	band_bumper_shape.setPoint(2, sf::Vector2f(0, -20));
	band_bumper_shape.setPoint(3, sf::Vector2f(100, -20));
	band_bumper_shape.setPoint(4, sf::Vector2f(110, -10));
	band_bumper_shape.setPoint(5, sf::Vector2f(100, 0));

	band_bumper_shape.move(position);


	band_bumper_shape.rotate(initRotation);

}

ConvexShape band_bumper::getShape()
{
	return band_bumper_shape;
}