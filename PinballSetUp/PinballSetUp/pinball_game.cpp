#include "pinball_game.h"



int play_game(RenderWindow* window)
{
	int user_choice = 0;
	int count = 0;
	int flag = 0;

	sf::Font MyFont;
	if (!MyFont.loadFromFile("OCR-A BT.ttf"))
	{
		// error...
	}
	//create pinball
	ball* pinball = new ball(825, 770);
	//create colliable non moving objects
	std::vector<ConvexShape> collidableObjects = createCollidableObject();
	//create text Objects
	std::vector<Text> textObjects = createTextObjects(&MyFont);

	//create collidable moving objects
	int launches = 3;
	int score_count = 0;

	bumper* bumper1 = new bumper(600, 400);
	bumper* bumper2 = new bumper(400, 200);
	band_bumper* band_bumper1 = new band_bumper(370, 670, 45, false);
	band_bumper* band_bumper2 = new band_bumper(700, 660, 135, false);
	flipper* leftFlipper = new flipper(390, 815, 90, false);
	flipper* rightFlipper = new flipper(700, 815, 90, true);
	launcher* ballLauncher = new launcher(855, 830);

	sf::RectangleShape score_box1(sf::Vector2f(170.f, 60.f));
	score_box1.setPosition(55.f, 75.f);
	score_box1.setFillColor(sf::Color::Red);

	sf::RectangleShape score_box2(sf::Vector2f(170.f, 60.f));
	score_box2.setPosition(60.f, 80.f);
	score_box2.setFillColor(sf::Color::Blue);

	while (launches > 0)
	{
		launches = 3;
		while (launches > 0) {

			//determine number of launches left to display

			// Keyboard Actions
			leftFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::A));
			rightFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::D));
			int if_launch = 0;

			if (flag == 0)
				if_launch = ballLauncher->moveLauncher(Keyboard::isKeyPressed(Keyboard::Space));

			if ((if_launch) && (ballLauncher->getposition().y == 830)) {

				//if_launch is 0 if the ball doesn't launch, 1 if the ball launches slowly,
				//2 if the ball launches medium, and 3 if the ball launches fast
				setSetting(pinball, &textObjects[3], if_launch);

				pinball->update();
				flag = 1;
			}
			ballLauncher->update();
			if (flag == 1) {
				pinball->collision(leftFlipper->getShape());
				pinball->collision(rightFlipper->getShape());
				//pinball->hitboundary2(290, HEIGHT);
				//pinball->hitboundary2(810, HEIGHT);
				pinball->collision(bumper1->getShape());
				pinball->collision(bumper2->getShape());

				pinball->collision(band_bumper1->getShape());
				pinball->collision(band_bumper2->getShape());
				pinball->hitboundary(window->getSize().x, window->getSize().y);

				for (int i = 0; i < collidableObjects.size();i++)
				{
					pinball->collision(collidableObjects[i]);
				}
				pinball->update();

				if ((pinball->getposition().y) > 900) {
					launches--;
					setLaunches(&textObjects[2], launches);
					pinball = new ball(825, 770);
					flag = 0;
				}

			}

			window->clear();
			window->draw(pinball->getShape());
			window->draw(leftFlipper->getShape());
			window->draw(rightFlipper->getShape());
			window->draw(ballLauncher->getShape());
			for (int i = 0; i < collidableObjects.size();i++)
			{
				window->draw(collidableObjects[i]);
			}
			for (int j = 0; j < textObjects.size();j++)
			{
				window->draw(textObjects[j]);
			}

			//window->draw(score_box2);
			//window->draw(score_box1);
			window->draw(bumper1->getShape());
			window->draw(bumper2->getShape());
			window->draw(band_bumper1->getShape());
			window->draw(band_bumper2->getShape());
			window->display();
			//count = 1;
		}
		if (launches == 0) {
			window->clear();
			textObjects[2].setCharacterSize(20);
			textObjects[2].setString("You have run out of launches!\nClick anywhere to go back to main menu.");

			window->draw(textObjects[2]);
			window->display();
			if (Mouse::isButtonPressed(sf::Mouse::Left))
			{
				user_choice = 0;
				count = 0;
				window->clear();
			}
		}
	}
	return 0;
}

void setLaunches(Text* launch, int launches)
{
	switch (launches)
	{
	case 1: launch->setString("1");
		break;
	case 2: launch->setString("2");
		break;
	case 3: launch->setString("3");
		break;
	default: launch->setString("#");
	}
}

void setSetting(ball* pinball, Text* setting_display, int if_launch)
{
	switch (if_launch)
	{
	case 1:
		pinball->setVelocity(0.0, -2.0);
		setting_display->setString("Slow");
		break;
	case 2:
		pinball->setVelocity(0.0, -5.0);
		setting_display->setString("Medium");
		break;
	case 3:
		pinball->setVelocity(0.0, -10.0);
		setting_display->setString("Fast");
		break;
	}
}

std::vector<ConvexShape> createCollidableObject()
{
	std::vector<ConvexShape> Objects;

	ConvexRect* right_rectangle = new ConvexRect(800, 175, 10, 750);
	ConvexRect* left_rectangle = new ConvexRect(280, 0, 10, 715);
	ConvexRect* scorebox1 = new ConvexRect(55, 75, 170, 60,0,Color::Red);
	ConvexRect* scorebox2 = new ConvexRect(60, 80, 170, 60,0,Color::Blue);

	sf::ConvexShape right_corner;
	right_corner.setPointCount(3);
	right_corner.setPoint(0, sf::Vector2f(900.f, 0.f));
	right_corner.setPoint(1, sf::Vector2f(900.f, 60.f));
	right_corner.setPoint(2, sf::Vector2f(840.f, 0.f));

	sf::ConvexShape left_bot_corner;
	left_bot_corner.setPointCount(3);
	left_bot_corner.setPoint(0, sf::Vector2f(290.f, 700.f));
	left_bot_corner.setPoint(1, sf::Vector2f(403.14f, 813.14f));
	left_bot_corner.setPoint(2, sf::Vector2f(290.f, 813.14f));
	left_bot_corner.setFillColor(sf::Color::Red);

	sf::ConvexShape left_triangle;
	left_triangle.setPointCount(3);
	left_triangle.setPoint(0, sf::Vector2f(290.f, 400.f));
	left_triangle.setPoint(1, sf::Vector2f(370.f, 450.f));
	left_triangle.setPoint(2, sf::Vector2f(290.f, 500.f));
	left_triangle.setFillColor(sf::Color::White);

	sf::ConvexShape left_corner;
	left_corner.setPointCount(3);
	left_corner.setPoint(0, sf::Vector2f(290.f, 0.f));
	left_corner.setPoint(1, sf::Vector2f(290.f, 60.f));
	left_corner.setPoint(2, sf::Vector2f(350.f, 0.f));

	sf::ConvexShape right_triangle;
	right_triangle.setPointCount(3);
	right_triangle.setPoint(0, sf::Vector2f(810.f, 100.f));
	right_triangle.setPoint(1, sf::Vector2f(730.f, 150.f));
	right_triangle.setPoint(2, sf::Vector2f(810.f, 200.f));
	right_triangle.setFillColor(sf::Color::White);

	sf::ConvexShape right_bot_corner;
	right_bot_corner.setPointCount(3);
	right_bot_corner.setPoint(0, sf::Vector2f(810.f, 710.f));
	right_bot_corner.setPoint(1, sf::Vector2f(810.f, 813.f));
	right_bot_corner.setPoint(2, sf::Vector2f(696.8f, 813.14f));
	right_bot_corner.setFillColor(sf::Color::Red);

	Objects.push_back(right_rectangle->getShape());
	Objects.push_back(left_rectangle->getShape());
	Objects.push_back(left_bot_corner);
	Objects.push_back(left_triangle);
	Objects.push_back(left_corner);
	Objects.push_back(right_corner);
	Objects.push_back(right_triangle);
	Objects.push_back(right_bot_corner);
	Objects.push_back(scorebox1->getShape());
	Objects.push_back(scorebox2->getShape());

	return Objects;
}

std::vector<Text> createTextObjects(Font* MyFont)
{
	std::vector<Text> texts;

	Text launch_setting;
	launch_setting.setFont(*MyFont);
	launch_setting.setString("Launch Speed: ");
	launch_setting.setCharacterSize(25);
	launch_setting.setFillColor(sf::Color::Red);
	launch_setting.setPosition(20.f, 650.f);

	Text launches_left;
	launches_left.setFont(*MyFont);
	launches_left.setString("Launches Left: ");
	launches_left.setCharacterSize(25);
	launches_left.setFillColor(sf::Color::Red);
	launches_left.setPosition(20.f, 580.f);

	Text launches_display;
	launches_display.setFont(*MyFont);
	launches_display.setString("3");
	launches_display.setCharacterSize(45);
	launches_display.setFillColor(sf::Color::White);
	launches_display.setPosition(240.f, 550.f);

	Text setting_display;
	setting_display.setFont(*MyFont);
	setting_display.setCharacterSize(25);
	setting_display.setFillColor(sf::Color::White);
	setting_display.setPosition(50.f, 680.f);

	Text game_rules;
	game_rules.setFont(*MyFont);
	game_rules.setString("Game Rules\nPress the spacebar to \nrelease the ball. There \nare three release \nsettings: slow, medium, \nand fast. \nUse the A and D keys to\ncontrol the flippers and \nkeep the ball from \nfalling into the gap.\n\nThe game ends when\nthe ball falls into the \ngap three times! Your \nscore depends on the\n number of collisions\n between the ball and \nthe bumpers!");
	game_rules.setCharacterSize(18);
	game_rules.setFillColor(sf::Color::Red);
	game_rules.setPosition(20.f, 160.f);

	Text title;
	title.setFont(*MyFont);
	title.setString("PINBALL");
	title.setCharacterSize(70);
	title.setFillColor(sf::Color::Red);
	title.setPosition(25.f, 750.f);

	Text titleshadow;
	titleshadow.setFont(*MyFont);
	titleshadow.setString("PINBALL");
	titleshadow.setCharacterSize(70);
	titleshadow.setFillColor(sf::Color::Blue);
	titleshadow.setPosition(30.f, 755.f);
	//score
	Text score;
	score.setFont(*MyFont);
	score.setString("Score:");
	score.setCharacterSize(50);
	score.setFillColor(sf::Color::Red);
	score.setPosition(45.f, 10.f);
	//shadow of score
	Text scoreshadow;
	scoreshadow.setFont(*MyFont);
	scoreshadow.setString("Score:");
	scoreshadow.setCharacterSize(50);
	scoreshadow.setFillColor(sf::Color::Blue);
	scoreshadow.setPosition(50.f, 15.f);

	texts.push_back(launch_setting);
	texts.push_back(launches_left);
	texts.push_back(launches_display);
	texts.push_back(setting_display);
	texts.push_back(game_rules);
	texts.push_back(title);
	texts.push_back(titleshadow);
	texts.push_back(score);
	texts.push_back(scoreshadow);


	return texts;
}
