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
		position.y += 1;
		pullback++;
}

void launcher::release()
{
		position.y -= 1;
		pullback--;
}

int launcher::moveLauncher(bool upDown)
{
	int a;
	if (upDown)
	{
		if (pullback <= MAXPULLBACK)
			pullBack();
	}
	else
	{
		if (pullback > 0) {
			if (pullback <= 20)
				a = 1;
			else if (pullback <= 32)
				a = 2;
			else if (pullback > 32)
				a = 3;

			release();
			return a;
		}
		else
			return 0;
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