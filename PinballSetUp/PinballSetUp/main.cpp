#include <SFML/Graphics.hpp>
#include "ball.h"
#include "flipper.h"
#include "launcher.h"
#include <iostream>
#include "pa8.h"

int main()
{
	sf::ContextSettings settings;
	// Anti Aliasing Enabled
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(900, 900), "Pinball SetUp", sf::Style::Close | sf::Style::Titlebar, settings);

	// Pinball
	ball* pinball = new ball(825, 770);

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

	//menu boxes
	sf::RectangleShape outerbox(sf::Vector2f(450.f, 750.f));
	sf::RectangleShape start_playable(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape test1(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape test2(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape test3(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape test4(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape test5(sf::Vector2f(350.f, 50.f));
	sf::RectangleShape exit(sf::Vector2f(350.f, 50.f));

	//text boxes for menu
	sf::Text manu_title; Text created_by; Text startplayable; Text testcase1; Text testcase2; Text testcase3; Text testcase4; Text testcase5; Text exitText;
	//text setting
	manu_title.setFont(MyFont); startplayable.setFont(MyFont); testcase1.setFont(MyFont);  testcase2.setFont(MyFont); testcase3.setFont(MyFont);
	testcase4.setFont(MyFont); testcase5.setFont(MyFont); exitText.setFont(MyFont);
	manu_title.setString("PINBALL");
	manu_title.setCharacterSize(70);
	manu_title.setFillColor(sf::Color::Red);
	manu_title.setPosition(330.f, 100.f);


	startplayable.setString("Start Playable Game");
	startplayable.setCharacterSize(25);
	startplayable.setFillColor(sf::Color::Red);
	startplayable.setPosition(325.f, 260.f);

	testcase1.setString("Test Case 1");
	testcase1.setCharacterSize(25);
	testcase1.setFillColor(sf::Color::Red);
	testcase1.setPosition(395.f, 340.f);

	testcase2.setString("Test Case 2");
	testcase2.setCharacterSize(25);
	testcase2.setFillColor(sf::Color::Red);
	testcase2.setPosition(395.f, 420.f);

	testcase3.setString("Test Case 3");
	testcase3.setCharacterSize(25);
	testcase3.setFillColor(sf::Color::Red);
	testcase3.setPosition(395.f, 500.f);

	testcase4.setString("Test Case 4");
	testcase4.setCharacterSize(25);
	testcase4.setFillColor(sf::Color::Red);
	testcase4.setPosition(395.f, 580.f);

	testcase5.setString("Test Case 5");
	testcase5.setCharacterSize(25);
	testcase5.setFillColor(sf::Color::Red);
	testcase5.setPosition(395.f, 660.f);

	exitText.setString("Exit Game");
	exitText.setCharacterSize(25);
	exitText.setFillColor(sf::Color::Red);
	exitText.setPosition(410.f, 740.f);

	sf::RectangleShape mouse_check(sf::Vector2f(10.f, 10.f));

	//menu initializations
	create_menu(&outerbox, &start_playable, &test1, &test2, &test3, &test4, &test5, &exit);


	int user_choice = 0;
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

		//first, display the menu before nay option is chosen
		if (user_choice == 0) {
			window.clear();
			window.draw(outerbox);
			window.draw(test1);
			window.draw(start_playable);
			window.draw(test2);
			window.draw(test3);
			window.draw(test4);
			window.draw(test5);
			window.draw(exit);
			window.draw(manu_title);
			window.draw(startplayable);
			window.draw(testcase1);
			window.draw(testcase2);
			window.draw(testcase3);
			window.draw(testcase4);
			window.draw(testcase5);
			window.draw(exitText);
			window.display();
		}

		if (Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Vector2i mouse_pos = Mouse::getPosition(window);


			//1, start game option
			if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 250) && (mouse_pos.y < 300)))) {
				user_choice = 1;
			}
			//2, test case 1 option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 330) && (mouse_pos.y < 380)))) {
				user_choice = 2;

			}
			//3, test case 2 option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 410) && (mouse_pos.y < 460)))) {
				user_choice = 3;
			}
			//4, test case 3 option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 490) && (mouse_pos.y < 540)))) {
				user_choice = 4;
			}
			//5, test case 4 option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 570) && (mouse_pos.y < 620)))) {
				user_choice = 5;
			}

			//6, test case 5 option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 650) && (mouse_pos.y < 700)))) {
				user_choice = 6;
			}

			//7, exit option
			else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 730) && (mouse_pos.y < 780)))) {
				user_choice = 7;
			}
		}
		if ((user_choice == 1) || (user_choice == 2) || (user_choice == 3) || (user_choice == 4) || (user_choice == 5) || (user_choice == 6)) {
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
			window.draw(mouse_check);
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
		if (user_choice == 7) {
			window.close();
		}


	}

	return 0;
}
