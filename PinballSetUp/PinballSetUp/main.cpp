#include <SFML/Graphics.hpp>
#include "ball.h"
#include "flipper.h"
#include "launcher.h"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	// Anti Aliasing Enabled
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(900, 900), "Pinball SetUp", sf::Style::Close | sf::Style::Titlebar,settings);

	// Pinball
	ball* pinball = new ball(825,770);

	//Flippers
	flipper* leftFlipper = new flipper(390, 815, 90, false);
	flipper* rightFlipper = new flipper(700, 815, 90, true);

	//launcher
	launcher* ballLauncher = new launcher(855, 830);

	sf::RectangleShape rectangle(sf::Vector2f(10.f, 750.f));
	rectangle.setFillColor(sf::Color::White);
	rectangle.move(800, 175);
	//rectangle.setPosition(600.f, 175.f);

	sf::RectangleShape left_rectangle(sf::Vector2f(10.f, 715.f));
	left_rectangle.move(280, 0);
	//left_rectangle.setPosition(80.f, 0.f);
	left_rectangle.setFillColor(sf::Color::White);

	//to launch the ball, we need to make this move vertically with options for launch strength
	//that correlate with ball speed


	sf::ConvexShape corner;
	corner.setPointCount(3);
	corner.setPoint(0, sf::Vector2f(900.f, 0.f));
	corner.setPoint(1, sf::Vector2f(900.f, 60.f));
	corner.setPoint(2, sf::Vector2f(840.f, 0.f));

	sf::ConvexShape left_corner;
	left_corner.setPointCount(3);
	left_corner.setPoint(0, sf::Vector2f(290.f, 0.f));
	left_corner.setPoint(1, sf::Vector2f(290.f, 60.f));
	left_corner.setPoint(2, sf::Vector2f(350.f, 0.f));

	sf::RectangleShape left_bound(sf::Vector2f(160.f, 15.f));
	left_bound.setPosition(290.f, 700.f);
	left_bound.rotate(45.f);

	sf::RectangleShape right_bound(sf::Vector2f(160.f, 15.f));
	right_bound.setPosition(810.f, 710.f);
	right_bound.rotate(135.f);

	//adding in the text
	sf::Font MyFont;
	if (!MyFont.loadFromFile("OCR-A BT.ttf"))
	{
		// error...
	}

	sf::Text title; Text titleshadow; Text score; Text scoreshadow;
	//title 
	title.setFont(MyFont);
	title.setString("PINBALL");
	title.setCharacterSize(70); 
	title.setFillColor(sf::Color::Red);
	title.setPosition(25.f, 750.f);
	//shadow of title
	titleshadow.setFont(MyFont);
	titleshadow.setString("PINBALL");
	titleshadow.setCharacterSize(70);
	titleshadow.setFillColor(sf::Color::Blue);
	titleshadow.setPosition(30.f, 755.f);
	//score
	score.setFont(MyFont);
	score.setString("Score:");
	score.setCharacterSize(50);
	score.setFillColor(sf::Color::Red);
	score.setPosition(45.f, 50.f);
	//shadow of score
	scoreshadow.setFont(MyFont);
	scoreshadow.setString("Score:");
	scoreshadow.setCharacterSize(50);
	scoreshadow.setFillColor(sf::Color::Blue);
	scoreshadow.setPosition(50.f, 55.f);

	sf::RectangleShape score_box1(sf::Vector2f(170.f, 60.f));
	score_box1.setPosition(55.f, 115.f);
	score_box1.setFillColor(sf::Color::Red);

	sf::RectangleShape score_box2(sf::Vector2f(170.f, 60.f));
	score_box2.setPosition(60.f, 120.f);
	score_box2.setFillColor(sf::Color::Blue);


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
		window.draw(titleshadow);
		window.draw(scoreshadow);
		window.draw(title);
		window.draw(score);
		window.draw(score_box2);
		window.draw(score_box1);
		window.display();
	}

	return 0;
}