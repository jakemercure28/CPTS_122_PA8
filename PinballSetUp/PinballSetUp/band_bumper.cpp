#include "band_bumper.h"

//Description: This is the .cpp (source) for the band_bumper class, which contains the
//definition of the functionalities used to create the band bumpers in our game

//constructor that creates a band_bumper object
//inputs are for the position, rotation, and activity of the bumper
band_bumper::band_bumper(float initX, float initY, float initRotation, bool active)
{
	position.x = initX;
	position.y = initY;
	is_activated = active;
	//first the object's shape is created around (0,0)
	convex_shape_object.setPointCount(6);
	convex_shape_object.setPoint(0, sf::Vector2f(0, 0));
	convex_shape_object.setPoint(1, sf::Vector2f(-10, -10));
	convex_shape_object.setPoint(2, sf::Vector2f(0, -20));
	convex_shape_object.setPoint(3, sf::Vector2f(100, -20));
	convex_shape_object.setPoint(4, sf::Vector2f(110, -10));
	convex_shape_object.setPoint(5, sf::Vector2f(100, 0));

	//then, it is moved to the inputted position
	convex_shape_object.move(position);

	convex_shape_object.rotate(initRotation);

	convex_shape_object.setFillColor(sf::Color::Black);
	convex_shape_object.setOutlineThickness(7);
	convex_shape_object.setOutlineColor(sf::Color::Yellow);

}
//this virtual function returns the band_bumper ConvexShape
ConvexShape band_bumper::getShape()
{
	return convex_shape_object;
}