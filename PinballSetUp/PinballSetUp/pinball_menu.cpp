#include "pinball_menu.h"

int menu(RenderWindow* window)
{
	int user_choice = 0;

	while (user_choice == 0)
	{
		drawMenu(window);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			user_choice = check_mouse_pos(sf::Mouse::getPosition(*window));
		}
	}

	return user_choice;
}

void drawMenu(RenderWindow* window)
{

	RectangleShape outerbox(Vector2f(450, 750));
	outerbox.setPosition(250, 75);
	outerbox.setFillColor(Color::Blue);

	RectangleShape Start_playable(Vector2f(350.f, 50.f));
	Start_playable.setPosition(300.f, 250.f);
	Start_playable.setFillColor(Color::White);

	RectangleShape test1(Vector2f(350.f, 50.f));
	test1.setPosition(300.f, 330.f);
	test1.setFillColor(Color::White);

	RectangleShape test2(Vector2f(350.f, 50.f));
	test2.setPosition(300.f, 410.f);
	test2.setFillColor(Color::White);

	RectangleShape test3(Vector2f(350.f, 50.f));
	test3.setPosition(300.f, 490.f);
	test3.setFillColor(Color::White);

	RectangleShape test4(Vector2f(350.f, 50.f));
	test4.setPosition(300.f, 570.f);
	test4.setFillColor(Color::White);

	RectangleShape test5(Vector2f(350.f, 50.f));
	test5.setPosition(300.f, 650.f);
	test5.setFillColor(Color::White);

	RectangleShape exit(Vector2f(350.f, 50.f));
	exit.setPosition(300.f, 730.f);
	exit.setFillColor(Color::White);

	Font MyFont;
	if (!MyFont.loadFromFile("OCR-A BT.ttf")) {/*Error*/ }

	Text menu_title, created_by, startplayable, testcase1, testcase2, testcase3, testcase4, testcase5, exittext;

	menu_title.setFont(MyFont);
	menu_title.setString("PINBALL");
	menu_title.setCharacterSize(70);
	menu_title.setFillColor(Color::Red);
	menu_title.setPosition(330, 100);

	startplayable.setFont(MyFont);
	startplayable.setString("Start Playable Game");
	startplayable.setCharacterSize(25);
	startplayable.setFillColor(Color::Red);
	startplayable.setPosition(325, 260);

	testcase1.setFont(MyFont);
	testcase1.setString("Test Case 1");
	testcase1.setCharacterSize(25);
	testcase1.setFillColor(Color::Red);
	testcase1.setPosition(395, 340);

	testcase2.setFont(MyFont);
	testcase2.setString("Test Case 2");
	testcase2.setCharacterSize(25);
	testcase2.setFillColor(Color::Red);
	testcase2.setPosition(395, 420);

	testcase3.setFont(MyFont);
	testcase3.setString("Test Case 3");
	testcase3.setCharacterSize(25);
	testcase3.setFillColor(Color::Red);
	testcase3.setPosition(395, 500);

	testcase4.setFont(MyFont);
	testcase4.setString("Test Case 4");
	testcase4.setCharacterSize(25);
	testcase4.setFillColor(Color::Red);
	testcase4.setPosition(395, 580);

	testcase5.setFont(MyFont);
	testcase5.setString("Test Case 5");
	testcase5.setCharacterSize(25);
	testcase5.setFillColor(Color::Red);
	testcase5.setPosition(395, 660);

	exittext.setFont(MyFont);
	exittext.setString("Exit Game");
	exittext.setCharacterSize(25);
	exittext.setFillColor(Color::Red);
	exittext.setPosition(410, 740);

	window->clear();
	window->draw(outerbox);
	window->draw(test1);
	window->draw(Start_playable);
	window->draw(test2);
	window->draw(test3);
	window->draw(test4);
	window->draw(test5);
	window->draw(exit);
	window->draw(menu_title);
	window->draw(startplayable);
	window->draw(testcase1);
	window->draw(testcase2);
	window->draw(testcase3);
	window->draw(testcase4);
	window->draw(testcase5);
	window->draw(exittext);
	window->display();
}

int check_mouse_pos(Vector2i mouse_pos)
{
	//1, start game option
	if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 250) && (mouse_pos.y < 300)))) {
		return 1;
	}
	//2, test case 1 option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 330) && (mouse_pos.y < 380)))) {
		return 2;

	}
	//3, test case 2 option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 410) && (mouse_pos.y < 460)))) {
		return 3;
	}
	//4, test case 3 option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 490) && (mouse_pos.y < 540)))) {
		return 4;
	}
	//5, test case 4 option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 570) && (mouse_pos.y < 620)))) {
		return 5;
	}

	//6, test case 5 option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 650) && (mouse_pos.y < 700)))) {
		return 6;
	}

	//7, exit option
	else if ((((mouse_pos.x > 300) && (mouse_pos.x < 650)) && ((mouse_pos.y > 730) && (mouse_pos.y < 780)))) {
		return 7;
	}
	else
		return 0;
}