#include <SFML/Graphics.hpp>
#include <iostream>
#include "pinball_menu.h"
#include "pinball_game.h"

#define WIDTH 900
#define HEIGHT 1050
#define GAMEWIDTH 900

int main()
{
	sf::ContextSettings settings;
	// Anti Aliasing Enabled
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pinball SetUp", sf::Style::Close | sf::Style::Titlebar, settings);

	//Game State 
	int game_state = 0;
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


		while (game_state != -1)
		{
			switch (game_state)
			{
			case 0:
			{
				game_state = menu(&window);
			break;
			}
			case 1:
				// play game
				game_state = play_game(&window);
				break;
			case 2:
				// test case 1
				break;
			case 3:
				// test case 2
				break;
			case 4:
				// test case 3
				break;
			case 5:
				// test case 4
				break;
			case 6:
				// test case 5
				break;
			break;
			case 7:
			{
				//exit game
				window.close();
				game_state = -1;
			}
			break;
			default:
				game_state = 0; // show menu again
				break;
			}
		}
	}




	// Pinball
	//ball* pinball = new ball(825, 770);

	//bumper* bumper1 = new bumper(600, 400);
	//bumper* bumper2 = new bumper(400, 200);

	//band_bumper* band_bumper1 = new band_bumper(370, 670, 45, false);
	//band_bumper* band_bumper2 = new band_bumper(700, 660, 135, false);



	//////Flippers
	//flipper* leftFlipper = new flipper(390, 815, 90, false);
	//flipper* rightFlipper = new flipper(700, 815, 90, true);

	////launcher
	//launcher* ballLauncher = new launcher(855, 830);

	//ConvexRect* right_rectangle = new ConvexRect(800, 175, 10, 750);
	//ConvexRect* left_rectangle = new ConvexRect(280, 0, 10, 715);
	//ConvexRect* left_bound = new ConvexRect(290, 700, 160, 15, 45);
	//ConvexRect* right_bound = new ConvexRect(810, 710, 160, 15, 135);
	//to launch the ball, we need to make this move vertically with options for launch strength
	//that correlate with ball speed


	//sf::ConvexShape corner;
	//corner.setPointCount(3);
	//corner.setPoint(0, sf::Vector2f(900.f, 0.f));
	//corner.setPoint(1, sf::Vector2f(900.f, 60.f));
	//corner.setPoint(2, sf::Vector2f(840.f, 0.f));

	//sf::ConvexShape left_bot_corner;
	//left_bot_corner.setPointCount(3);
	//left_bot_corner.setPoint(0, sf::Vector2f(290.f, 700.f));
	//left_bot_corner.setPoint(1, sf::Vector2f(403.14f, 813.14f));
	//left_bot_corner.setPoint(2, sf::Vector2f(290.f, 813.14f));
	//left_bot_corner.setFillColor(sf::Color::Red);

	//sf::ConvexShape left_triangle;
	//left_triangle.setPointCount(3);
	//left_triangle.setPoint(0, sf::Vector2f(290.f, 400.f));
	//left_triangle.setPoint(1, sf::Vector2f(370.f, 450.f));
	//left_triangle.setPoint(2, sf::Vector2f(290.f, 500.f));
	//left_triangle.setFillColor(sf::Color::White);

	//sf::ConvexShape left_corner;
	//left_corner.setPointCount(3);
	//left_corner.setPoint(0, sf::Vector2f(290.f, 0.f));
	//left_corner.setPoint(1, sf::Vector2f(290.f, 60.f));
	//left_corner.setPoint(2, sf::Vector2f(350.f, 0.f));

	//adding in the text
	//sf::Font MyFont;
	//if (!MyFont.loadFromFile("OCR-A BT.ttf"))
	//{
	//	// error...
	//}

	//sf::Text title; Text titleshadow; Text score; Text scoreshadow;
	////title_score_game_setup(&MyFont, &title, &titleshadow, &score, &scoreshadow);


	//sf::RectangleShape score_box1(sf::Vector2f(170.f, 60.f));
	//score_box1.setPosition(55.f, 75.f);
	//score_box1.setFillColor(sf::Color::Red);

	//sf::RectangleShape score_box2(sf::Vector2f(170.f, 60.f));
	//score_box2.setPosition(60.f, 80.f);
	//score_box2.setFillColor(sf::Color::Blue);

	//sf::ConvexShape right_triangle;
	//right_triangle.setPointCount(3);
	//right_triangle.setPoint(0, sf::Vector2f(810.f, 100.f));
	//right_triangle.setPoint(1, sf::Vector2f(730.f, 150.f));
	//right_triangle.setPoint(2, sf::Vector2f(810.f, 200.f));
	//right_triangle.setFillColor(sf::Color::White);

	//sf::ConvexShape right_bot_corner;
	//left_bot_corner.setPointCount(3);
	//left_bot_corner.setPoint(0, sf::Vector2f(810.f, 710.f));
	//left_bot_corner.setPoint(1, sf::Vector2f(810.f, 813.f));
	//left_bot_corner.setPoint(2, sf::Vector2f(696.8f, 813.14f));
	//left_bot_corner.setFillColor(sf::Color::Red);

	//menu boxes
	//sf::RectangleShape outerbox(sf::Vector2f(450.f, 750.f));
	//sf::RectangleShape start_playable(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape test1(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape test2(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape test3(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape test4(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape test5(sf::Vector2f(350.f, 50.f));
	//sf::RectangleShape exit(sf::Vector2f(350.f, 50.f));

	////text boxes for menu
	//sf::Text manu_title; Text created_by; Text startplayable; Text testcase1; Text testcase2; Text testcase3; Text testcase4; Text testcase5; Text exitText;
	////text setting

	
	//sf::RectangleShape mouse_check(sf::Vector2f(10.f, 10.f));


	//int user_choice = 0;
	//int count = 0;
	//int flag = 0;

	//sf::Text launch_setting;						Text setting_display;
	//launch_setting.setFont(MyFont);					setting_display.setFont(MyFont);
	//launch_setting.setString("Launch Speed: ");
	//launch_setting.setCharacterSize(25);			setting_display.setCharacterSize(25);
	//launch_setting.setFillColor(sf::Color::Red);	 setting_display.setFillColor(sf::Color::White);
	//launch_setting.setPosition(20.f, 650.f);		setting_display.setPosition(50.f, 680.f);

	//sf::Text launches_left;						Text launches_display;
	//launches_left.setFont(MyFont);				launches_display.setFont(MyFont);
	//launches_left.setString("Launches Left: ");
	//launches_left.setCharacterSize(25);			launches_display.setCharacterSize(45);
	//launches_left.setFillColor(sf::Color::Red); launches_display.setFillColor(sf::Color::White);
	//launches_left.setPosition(20.f, 580.f);		launches_display.setPosition(240.f, 550.f);

	//sf::Text game_rules;
	//game_rules.setFont(MyFont);
	//game_rules.setString("Game Rules\nPress the spacebar to \nrelease the ball. There \nare three release \nsettings: slow, medium, \nand fast. \nUse the A and D keys to\ncontrol the flippers and \nkeep the ball from \nfalling into the gap.\n\nThe game ends when\nthe ball falls into the \ngap three times! Your \nscore depends on the\n number of collisions\n between the ball and \nthe bumpers!");
	//game_rules.setCharacterSize(18);
	//game_rules.setFillColor(sf::Color::Red);
	//game_rules.setPosition(20.f, 160.f);
	//int launches = 3;
	//int score_count = 0;

	//while (window.isOpen())
	//{
	//	//sf::Event event;
	//	//while (window.pollEvent(event))
	//	//{
	//	//	switch (event.type)
	//	//		case sf::Event::Closed:
	//	//			window.close();
	//	//			break;
	//	//}
	//	//if (user_choice == 0) {
	//	//	window.clear();

	//	//	//draw_menu(&window, outerbox, test1, start_playable, test2, test3, test4, test5, exit);
	//	//	//draw_menu2(&window, manu_title, startplayable, testcase1, testcase2, testcase3, testcase4, testcase5, exitText);

	//	//	window.display();
	//	//}

	//	//if (count == 0) {
	//	//	if (Mouse::isButtonPressed(sf::Mouse::Left))
	//	//	{
	//	//		Vector2i mouse_pos = Mouse::getPosition(window);
	//	//		user_choice = check_mouse_pos(mouse_pos);
	//	//		count++;
	//	//	}
	//	//}

	//	//if ((user_choice == 1) || (user_choice == 2) || (user_choice == 3) || (user_choice == 4) || (user_choice == 5) || (user_choice == 6))
	//	//{
	//	//	launches = 3;
	//	//	while (launches > 0) {

	//	//		//determine number of launches left to display
	//	//		setLaunches(&launches_display, launches);

	//	//		// Keyboard Actions
	//	//		leftFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::A));
	//	//		rightFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::D));
	//	//		int if_launch = 0;

	//	//		if (flag == 0)
	//	//			if_launch = ballLauncher->moveLauncher(Keyboard::isKeyPressed(Keyboard::Space));

	//	//		if ((if_launch) && (ballLauncher->getposition().y == 830)) {

	//	//			//if_launch is 0 if the ball doesn't launch, 1 if the ball launches slowly,
	//	//			//2 if the ball launches medium, and 3 if the ball launches fast
	//	//			if (if_launch == 1) {
	//	//				pinball->setVelocity(0.0, -2.0);
	//	//				setting_display.setString("Slow");
	//	//			}
	//	//			else if (if_launch == 2) {
	//	//				pinball->setVelocity(0.0, -5.0);
	//	//				setting_display.setString("Medium");
	//	//			}
	//	//			else if (if_launch == 3) {
	//	//				pinball->setVelocity(0.0, -10.0);
	//	//				setting_display.setString("Fast");
	//	//			}

	//	//			pinball->update();
	//	//			flag = 1;
	//	//		}
	//	//		ballLauncher->update();
	//	//		//pinball->update();
	//	//		if (flag == 1) {
	//	//			pinball->hitboundary(WIDTH, HEIGHT);
	//	//			//pinball->hitboundary2(290, HEIGHT);
	//	//			//pinball->hitboundary2(810, HEIGHT);
	//	//			pinball->collision(bumper1->getShape());
	//	//			pinball->collision(bumper2->getShape());
	//	//			pinball->collision(corner);
	//	//			pinball->collision(left_corner);
	//	//			pinball->collision(left_triangle);
	//	//			pinball->collision(left_bot_corner);
	//	//			//pinball->collision(right_triangle);
	//	//			pinball->collision(right_bot_corner);
	//	//			pinball->collision(band_bumper1->getShape());
	//	//			pinball->collision(band_bumper2->getShape());
	//	//			pinball->collision(leftFlipper->getShape());
	//	//			pinball->collision(rightFlipper->getShape());
	//	//			pinball->collision(ballLauncher->getShape());
	//	//			pinball->update();

	//	//			if ((pinball->getposition().y) > 900) {
	//	//				launches--;
	//	//				pinball = new ball(825, 770);
	//	//				flag = 0;
	//	//			}

	//	//		}

	//	//		window.clear();
	//	//		window.draw(pinball->getShape());
	//	//		window.draw(leftFlipper->getShape());
	//	//		window.draw(rightFlipper->getShape());
	//	//		window.draw(ballLauncher->getShape());

	//	//		window.draw(right_rectangle->getShape());
	//	//		window.draw(left_rectangle->getShape());
	//	//		window.draw(corner);
	//	//		window.draw(left_corner);
	//	//		window.draw(left_bot_corner);
	//	//		window.draw(left_bound->getShape());
	//	//		window.draw(left_triangle);
	//	//		window.draw(right_triangle);
	//	//		window.draw(right_bot_corner);
	//	//		window.draw(right_bound->getShape());
	//	//		window.draw(titleshadow);
	//	//		window.draw(scoreshadow);
	//	//		window.draw(title);
	//	//		window.draw(score);
	//	//		window.draw(score_box2);
	//	//		window.draw(score_box1);
	//	//		window.draw(bumper1->getShape());
	//	//		window.draw(bumper2->getShape());
	//	//		window.draw(band_bumper1->getShape());
	//	//		window.draw(band_bumper2->getShape());
	//	//		window.draw(game_rules);
	//	//		window.draw(launches_left);
	//	//		window.draw(launch_setting);
	//	//		window.draw(launches_display);
	//	//		window.draw(setting_display);
	//	//		window.display();
	//	//		//count = 1;
	//	//	}
	//	//	if (launches == 0) {
	//	//		window.clear();
	//	//		launches_display.setCharacterSize(20);
	//	//		launches_display.setString("You have run out of launches!\nClick anywhere to go back to main menu.");

	//	//		window.draw(launches_display);
	//	//		window.display();
	//	//		if (Mouse::isButtonPressed(sf::Mouse::Left))
	//	//		{
	//	//			user_choice = 0;
	//	//			count = 0;
	//	//			window.clear();
	//	//		}
	//	//	}
	//	//}
	//	//if (user_choice == 7) {
	//	//	window.close();
	//	//}

	//}

	return 0;
}
