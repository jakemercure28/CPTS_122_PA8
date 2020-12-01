#include "flipper.h"

flipper::flipper(float initX, float initY, float initRot, bool direction)
{
	position.x = initX;
	position.y = initY;
	rotation = 0;
	rotDir = direction;

	flipperShape.setPointCount(6);
	flipperShape.setPoint(0, sf::Vector2f(-15, 0));
	flipperShape.setPoint(1, sf::Vector2f(0, -15));
	flipperShape.setPoint(2, sf::Vector2f(15, 0));
	flipperShape.setPoint(3, sf::Vector2f(10, 115));
	flipperShape.setPoint(4, sf::Vector2f(0, 125));
	flipperShape.setPoint(5, sf::Vector2f(-10, 115));
	flipperShape.move(position);
	flipperShape.rotate(rotDir ? initRot : -initRot);
}

Vector2f flipper::getposition()
{
	return position;
}

ConvexShape flipper::getShape()
{
	return flipperShape;
}

float flipper::getRotation()
{
	return flipperShape.getRotation();
}

void flipper::rotateFlipper(bool upDown)
{
	flipperShape.rotate(upDown ^ rotDir ? -1 : 1);
}
