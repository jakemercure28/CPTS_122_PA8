#include <SFML/Graphics.hpp>
#include "ball.h"
#include "flipper.h"
#include "launcher.h"
#include "bumper.h"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	// Anti Aliasing Enabled
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(700, 900), "Pinball SetUp", sf::Style::Close | sf::Style::Titlebar,settings);

	// Pinball
	ball* pinball = new ball(625,770);

	bumper* bumper1 = new bumper(400, 400);
	bumper* bumper2 = new bumper(200, 200);

	//Flippers
	flipper* leftFlipper = new flipper(190, 815, 90, false);
	flipper* rightFlipper = new flipper(500, 815, 90, true);

	//launcher
	launcher* ballLauncher = new launcher(655, 830);

	sf::RectangleShape rectangle(sf::Vector2f(10.f, 750.f));
	rectangle.setFillColor(sf::Color::White);
	rectangle.move(600, 175);
	//rectangle.setPosition(600.f, 175.f);

	sf::RectangleShape left_rectangle(sf::Vector2f(10.f, 715.f));
	left_rectangle.move(80, 0);
	//left_rectangle.setPosition(80.f, 0.f);
	left_rectangle.setFillColor(sf::Color::White);

	//to launch the ball, we need to make this move vertically with options for launch strength
	//that correlate with ball speed


	sf::ConvexShape corner;
	corner.setPointCount(3);
	corner.setPoint(0, sf::Vector2f(700.f, 0.f));
	corner.setPoint(1, sf::Vector2f(700.f, 60.f));
	corner.setPoint(2, sf::Vector2f(640.f, 0.f));

	sf::ConvexShape left_corner;
	left_corner.setPointCount(3);
	left_corner.setPoint(0, sf::Vector2f(90.f, 0.f));
	left_corner.setPoint(1, sf::Vector2f(90.f, 60.f));
	left_corner.setPoint(2, sf::Vector2f(150.f, 0.f));

	sf::RectangleShape left_bound(sf::Vector2f(160.f, 15.f));
	left_bound.setPosition(90.f, 700.f);
	left_bound.rotate(45.f);

	sf::RectangleShape right_bound(sf::Vector2f(160.f, 15.f));
	right_bound.setPosition(610.f, 710.f);
	right_bound.rotate(135.f);

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
                case sf::Event::Closed:
					window.close();
					break;
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			//Rotate Left Flipper CCW until max rotation
			leftFlipper->rotateFlipper(true);
		}
		else
		{
			//Rotate Left Flipper CW until static position
			leftFlipper->rotateFlipper(false);
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			//Rotate Right Flipper CW until max rotation
			rightFlipper->rotateFlipper(true);
		}
		else
		{
			//Rotate Right Flipper CCW until static position
			rightFlipper->rotateFlipper(false);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
			ballLauncher->pullBack();
		else
			ballLauncher->release();

		ballLauncher->update();
		window.clear();
		window.draw(pinball->getShape());
		window.draw(leftFlipper->getShape());
		window.draw(rightFlipper->getShape());
		window.draw(ballLauncher->getShape());

		window.draw(rectangle);
		window.draw(left_rectangle);
		window.draw(corner);
		window.draw(left_corner);
		window.draw(left_bound);
		window.draw(right_bound);

		window.draw(bumper1->getShape());
		window.draw(bumper2->getShape());

		window.display();
	}

	return 0;
}