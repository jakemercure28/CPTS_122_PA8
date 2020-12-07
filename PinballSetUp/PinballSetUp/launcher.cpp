#include "launcher.h"

// launcher shape constructor creates the shape and then moves it to where the user sets with initXY
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

int launcher::moveLauncher(bool upDown, int* max_pull_back)
{
	// moves the launcher position up and down 
	int a;
	if (upDown)
	{
		if (pullback <= MAXPULLBACK)
			pullBack();
	}
	else
	{
		if (pullback > * max_pull_back) {
			*max_pull_back = pullback;
		}
		if (pullback > 0) {
			if (pullback <= 30)
				a = 1;
			else if (pullback <= 55)
				a = 2;
			else if (pullback > 55)
				a = 3;

			release();
			return a;
		}
		else
			return 0;
	}
}

int launcher::moveLauncher_slow() {
	int flag = 0;
	while (flag == 0) {
		if (pullback < 30) {
			pullBack();
		}
		if (pullback == 30) {
			flag = 1;
		}
	}
	while (flag == 1)
	{
		if (pullback >= 0) {
			release();
		}
		if (pullback == 0) {
			return 1;
		}
	}
	return 1;
}

int launcher::moveLauncher_medium() {
	int flag = 0;
	while (flag == 0) {
		if (pullback < 55) {
			pullBack();
		}
		if (pullback == 55) {
			flag = 1;
		}
	}
	while (flag == 1)
	{
		if (pullback >= 0) {
			release();
		}
		if (pullback == 0) {
			return 2;
		}
	}
	return 2;
}

int launcher::moveLauncher_fast()
{
	int flag = 0;
	while (flag == 0) {
		if (pullback <= MAXPULLBACK) {
			pullBack();
		}
		if (pullback == MAXPULLBACK) {
			flag = 1;
		}
	}
	while (flag == 1)
	{
		if (pullback >= 0) {
			release();
		}
		if (pullback == 0) {
			return 3;
		}
	}
	return 3;
}

void launcher::update()
{
	launcherShape.setPosition(position);
}

Vector2f launcher::getposition()
{
	return position;
}