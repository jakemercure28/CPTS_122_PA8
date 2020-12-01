#include "launcher.h"

launcher::launcher(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	pullback = 0;

	launcherShape.setPointCount(8);
	launcherShape.setPoint(0, sf::Vector2f(-30, 0));
	launcherShape.setPoint(1, sf::Vector2f(30, 0));
	launcherShape.setPoint(2, sf::Vector2f(30, 15));
	launcherShape.setPoint(3, sf::Vector2f(10, 35));
	launcherShape.setPoint(4, sf::Vector2f(10, 70));
	launcherShape.setPoint(5, sf::Vector2f(-10, 70));
	launcherShape.setPoint(6, sf::Vector2f(-10, 35));
	launcherShape.setPoint(7, sf::Vector2f(-30, 15));
	launcherShape.move(position);
	launcherShape.setFillColor(sf::Color::Red);
}

ConvexShape launcher::getShape()
{
	return launcherShape;
}

void launcher::pullBack()
{
	if (pullback <= MAXPULLBACK)
	{
		position.y += 1;
		pullback++;
	}
}

void launcher::release()
{
	if (pullback > 0)
	{
		position.y -= 1;
		pullback--;
	}
}

void launcher::update()
{
	launcherShape.setPosition(position);
}

Vector2f launcher::getposition()
{
	return position;
}