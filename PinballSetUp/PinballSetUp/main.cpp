#include <SFML/Graphics.hpp>
#include "ball.h"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	// Anti Aliasing Enabled
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(700, 900), "Pinball SetUp", sf::Style::Close | sf::Style::Titlebar,settings);

	// Pinball
	ball* pinball = new ball(625,770);


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

	sf::ConvexShape launcher;
	launcher.setPointCount(8);
	launcher.setPoint(0, sf::Vector2f(625.f, 830.f));
	launcher.setPoint(1, sf::Vector2f(685.f, 830.f));
	launcher.setPoint(2, sf::Vector2f(685.f, 845.f));
	launcher.setPoint(3, sf::Vector2f(665.f, 845.f));
	launcher.setPoint(4, sf::Vector2f(665.f, 900.f));
	launcher.setPoint(5, sf::Vector2f(645.f, 900.f));
	launcher.setPoint(6, sf::Vector2f(645.f, 845.f));
	launcher.setPoint(7, sf::Vector2f(625.f, 845.f));
	launcher.setFillColor(sf::Color::Red);

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

	// new left flipper
	sf::CircleShape leftflipperBase;
	leftflipperBase.setRadius(15);
	leftflipperBase.setPosition(175.f, 800.f);

	sf::ConvexShape leftflipperArm;
	leftflipperArm.setPointCount(4);
	leftflipperArm.setPoint(0, sf::Vector2f(190.f, 800.f));
	leftflipperArm.setPoint(1, sf::Vector2f(305.f, 805.f));
	leftflipperArm.setPoint(2, sf::Vector2f(305.f, 825.f));
	leftflipperArm.setPoint(3, sf::Vector2f(190.f, 830.f));
	sf::CircleShape leftflipperTip;
	leftflipperTip.setRadius(10);
	leftflipperTip.setPosition(295, 805);

	// old left flipper
	sf::ConvexShape left_flipper;
	left_flipper.setPointCount(3);
	left_flipper.setPoint(0, sf::Vector2f(190.f, 800.f));
	left_flipper.setPoint(1, sf::Vector2f(305.f, 830.f));
	left_flipper.setPoint(2, sf::Vector2f(190.f, 830.f));

	sf::ConvexShape right_flipper;
	right_flipper.setPointCount(3);
	right_flipper.setPoint(0, sf::Vector2f(500.f, 800.f));
	right_flipper.setPoint(1, sf::Vector2f(500.f, 830.f));
	right_flipper.setPoint(2, sf::Vector2f(385.f, 830.f));

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

		window.clear();
		window.draw(pinball->getShape());
		window.draw(rectangle);
		window.draw(left_rectangle);
		window.draw(launcher);
		window.draw(corner);
		window.draw(left_corner);
		window.draw(left_flipper);
		//window.draw(leftflipperBase);
		//window.draw(leftflipperArm);
		//window.draw(leftflipperTip);
		window.draw(left_bound);
		window.draw(right_flipper);
		window.draw(right_bound);
		window.display();
	}

	return 0;
}