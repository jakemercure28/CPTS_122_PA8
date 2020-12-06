#include "pinball_game.h"



int play_game(RenderWindow* window, int testcase)
{
	// Game state variables
	int user_choice = 0;
	int count = 0;
	int flag = 0;
	int score_count = 0;
	int launches;
	int max_pull_back;
	int if_launch = 0;
	int if_launch_prev;
	int restart = 0;


	// Load Font
	sf::Font MyFont;
	if (!MyFont.loadFromFile("OCR-A BT.ttf"))
	{
		// error...
	}

	// Game Objects

	// Create pinball
	ball* pinball = new ball(825, 770);
	//create colliable non moving objects
	std::vector<ConvexShape> collidableObjects = createCollidableObject();
	//create text Objects
	std::vector<Text> textObjects = createTextObjects(&MyFont);

	//create collidable moving objects
	FloatRect* boundary = new FloatRect(0, 0, window->getSize().x, window->getSize().y);

	bumper* bumper1 = new bumper(600, 400);
	bumper* bumper2 = new bumper(400, 200);
	band_bumper* band_bumper1 = new band_bumper(370, 600, 45, false);
	band_bumper* band_bumper2 = new band_bumper(700, 600, 135, false);
	flipper* leftFlipper = new flipper(390, 815, 90, false);
	flipper* rightFlipper = new flipper(700, 815, 90, true);
	launcher* ballLauncher = new launcher(855, 830);

	//launch count text object

	// Game Play

	switch (testcase)
	{
	case 1:
		launches = 1;
		textObjects[10].setString("Test Case 1:\nAutomatic launch at slow speed, manual flipper action. Only 1 launch for test cases.");
		break;
	case 2:
		launches = 1;
		textObjects[10].setString("Test Case 2:\nAutomatic launch at medium speed, manual flipper action. Only 1 launch for test cases.");
		break;
	case 3:
		launches = 1;
		textObjects[10].setString("Test Case 3:\nAutomatic launch at fast speed, manual flipper action. Only 1 launch for test cases.");
		break;
	default:
		launches = 3;
		break;
	}

	max_pull_back = 0;

	while (launches > 0) {
		//determine number of launches left to display
		

		// Keyboard Actions
		leftFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::A));
		rightFlipper->rotateFlipper(Keyboard::isKeyPressed(Keyboard::D));

		if (flag == 0)
			switch (testcase)
			{
			case 1:
				if_launch = ballLauncher->moveLauncher_slow();
				max_pull_back = 0;
				break;
			case 2:
				if_launch = ballLauncher->moveLauncher_medium();
				max_pull_back = 0;
				break;
			case 3:
				if_launch = ballLauncher->moveLauncher_fast();
				max_pull_back = 0;
				break;
			case 0:
			default:
				//if_launch_prev = if_launch;
				if_launch = ballLauncher->moveLauncher(Keyboard::isKeyPressed(Keyboard::Space), &max_pull_back);
				
			}
		if ((if_launch) && (ballLauncher->getposition().y == 830) && !flag) 
		{
			if (max_pull_back) {
				if (max_pull_back <= 30)
					if_launch = 1;
				else if (max_pull_back <= 55)
					if_launch = 2;
				else if (max_pull_back > 55)
					if_launch = 3;
			}
			max_pull_back = 0;
			//if_launch is 0 if the ball doesn't launch, 1 if the ball launches slowly,
			//2 if the ball launches medium, and 3 if the ball launches fast
			setSetting(pinball, &textObjects[3], if_launch);
			launches--;
			setLaunches(&textObjects[2], launches);
			pinball->update();
			flag = 1;
		}

		ballLauncher->update();

		if (flag == 1)
		{
			pinball->collision(leftFlipper->getShape());
			pinball->collision(rightFlipper->getShape());
			score_count += (pinball->collision(bumper1->getShape())) ? 10 : 0;
			score_count += (pinball->collision(bumper2->getShape())) ? 10 : 0;
			score_count += (pinball->collision(band_bumper1->getShape())) ? 10 : 0;
			score_count += (pinball->collision(band_bumper2->getShape())) ? 10 : 0;
			pinball->hitboundary(*boundary);

			update_score(window, &textObjects[9], score_count);

			for (int i = 0; i < collidableObjects.size();i++)
			{
				pinball->collision(collidableObjects[i]);
			}
			pinball->update();  

			if ((pinball->getposition().y) > 900) {
				
				pinball = new ball(825, 770);
				flag = 0;
			}

		}

		window->clear();
		for (int i = 0; i < collidableObjects.size();i++)
			window->draw(collidableObjects[i]);
		for (int j = 0; j < textObjects.size();j++)
			window->draw(textObjects[j]);

		window->draw(pinball->getShape());
		window->draw(leftFlipper->getShape());
		window->draw(rightFlipper->getShape());
		window->draw(ballLauncher->getShape());
		window->draw(bumper1->getShape());
		window->draw(bumper2->getShape());
		window->draw(band_bumper1->getShape());
		window->draw(band_bumper2->getShape());
		window->display();
	}

	// End of game
	if (launches == 0) {
		window->clear();
		textObjects[2].setCharacterSize(20);


		switch (testcase)
		{
		case 1:
		case 2:
		case 3:
			textObjects[2].setString("The test case is over!\nPress R to go back to main menu.\nPress Escape to quit the game.");
			break;
		default:
			textObjects[2].setString("You have run out of launches!\nPress R to go back to main menu\nPress Escape to quit the game.");
			break;
		}

		window->draw(textObjects[2]);
		window->display();
		do {
			if (Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				user_choice = 0;
				count = 0;
				launches = 3;
				restart = 1;
				if_launch = 0;
				max_pull_back = 0;
				//window.clear();
			}
			else if ((Keyboard::isKeyPressed(sf::Keyboard::Escape)))
				window->close();
		} while (restart == 0);
	}
	return 0;
}

void setLaunches(Text* launch, int launches)
{
	switch (launches)
	{
	case 1: launch->setString("0");
		break;
	case 2: launch->setString("1");
		break;
	case 3: launch->setString("2");
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
		pinball->setVelocity(0.0, -4.5); //4.5 speed fixes the collision issue
		setting_display->setString("Medium");
		break;
	case 3:
		pinball->setVelocity(0.0, -8.0);
		setting_display->setString("Fast");
		break;
	}
}

std::vector<ConvexShape> createCollidableObject()
{
	std::vector<ConvexShape> Objects;

	ConvexRect* right_rectangle = new ConvexRect(800, 175, 10, 750);
	ConvexRect* left_rectangle = new ConvexRect(280, 0, 10, 715);
	ConvexRect* scorebox1 = new ConvexRect(55, 75, 170, 60, 0, Color::Red);
	ConvexRect* scorebox2 = new ConvexRect(60, 80, 170, 60, 0, Color::Blue);
	ConvexRect* line_that_blocks_the_ball_from_the_launcher = new ConvexRect(800, 0, 10, 180);

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
	//Objects.push_back(line_that_blocks_the_ball_from_the_launcher->getShape());
	Objects.push_back(left_bot_corner);
	Objects.push_back(left_triangle);
	Objects.push_back(left_corner);
	Objects.push_back(right_corner);
	Objects.push_back(right_triangle);
	Objects.push_back(right_bot_corner);
	Objects.push_back(scorebox2->getShape());
	Objects.push_back(scorebox1->getShape());

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
	//launches_display.setString("3");
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

	Text score_counter;
	score_counter.setFont(*MyFont);
	score_counter.setCharacterSize(50);
	score_counter.setFillColor(sf::Color::White);
	score_counter.setPosition(80.f, 70.f);

	Text test_case_description;
	test_case_description.setFont(*MyFont);
	test_case_description.setCharacterSize(18);
	test_case_description.setFillColor(sf::Color::White);
	test_case_description.setPosition(20.f, 900.f);

	texts.push_back(launch_setting);
	texts.push_back(launches_left);
	texts.push_back(launches_display);
	texts.push_back(setting_display);
	texts.push_back(game_rules);
	texts.push_back(titleshadow);
	texts.push_back(title);
	texts.push_back(scoreshadow);
	texts.push_back(score);
	texts.push_back(score_counter);
	texts.push_back(test_case_description);


	return texts;
}

void update_score(RenderWindow* window, Text* score_counter, int score_count)
{
	score_counter->setString(std::to_string(score_count));
}
