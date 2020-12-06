#include "band_bumper.h"

band_bumper::band_bumper(float initX, float initY, float initRotation, bool active)
{
	position.x = initX;
	position.y = initY;
	is_activated = active;

	convex_shape_object.setPointCount(6);
	convex_shape_object.setPoint(0, sf::Vector2f(0, 0));
	convex_shape_object.setPoint(1, sf::Vector2f(-10, -10));
	convex_shape_object.setPoint(2, sf::Vector2f(0, -20));
	convex_shape_object.setPoint(3, sf::Vector2f(100, -20));
	convex_shape_object.setPoint(4, sf::Vector2f(110, -10));
	convex_shape_object.setPoint(5, sf::Vector2f(100, 0));


	convex_shape_object.move(position);

	convex_shape_object.rotate(initRotation);

	convex_shape_object.setFillColor(sf::Color::Black);
	convex_shape_object.setOutlineThickness(7);
	convex_shape_object.setOutlineColor(sf::Color::Yellow);

}

ConvexShape band_bumper::getShape()
{
	return convex_shape_object;
}