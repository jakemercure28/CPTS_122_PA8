#ifndef PA8_H
#define PA8_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

void create_menu(RectangleShape *outerbox, RectangleShape *Start_playable, RectangleShape *test1, RectangleShape *test2, RectangleShape *test3, RectangleShape *test4, RectangleShape *test5, RectangleShape *exit){
	outerbox->setPosition(250.f, 75.f);
	outerbox->setFillColor(Color::Blue);
	Start_playable->setPosition(300.f, 250.f);
	Start_playable->setFillColor(Color::White);
	test1->setPosition(300.f, 330.f);
	test1->setFillColor(Color::White);
	test2->setPosition(300.f, 410.f);
	test2->setFillColor(Color::White);
	test3->setPosition(300.f, 490.f);
	test3->setFillColor(Color::White);
	test4->setPosition(300.f, 570.f);
	test4->setFillColor(Color::White);
	test5->setPosition(300.f, 650.f);
	test5->setFillColor(Color::White);
	exit->setPosition(300.f, 730.f);
	exit->setFillColor(Color::White);

}

void create_menu2(Font *MyFont, sf::Text *manu_title, Text *created_by, Text *startplayable, Text *testcase1, Text *testcase2, Text *testcase3,Text *testcase4, Text *testcase5, Text *exitText) {
	manu_title->setFont(*MyFont); startplayable->setFont(*MyFont); testcase1->setFont(*MyFont);  testcase2->setFont(*MyFont); testcase3->setFont(*MyFont);
	testcase4->setFont(*MyFont); testcase5->setFont(*MyFont); exitText->setFont(*MyFont);

	manu_title->setString("PINBALL");
	manu_title->setCharacterSize(70);
	manu_title->setFillColor(sf::Color::Red);
	manu_title->setPosition(330.f, 100.f);

	startplayable->setString("Start Playable Game");
	startplayable->setCharacterSize(25);
	startplayable->setFillColor(sf::Color::Red);
	startplayable->setPosition(325.f, 260.f);

	testcase1->setString("Test Case 1");
	testcase1->setCharacterSize(25);
	testcase1->setFillColor(sf::Color::Red);
	testcase1->setPosition(395.f, 340.f);

	testcase2->setString("Test Case 2");
	testcase2->setCharacterSize(25);
	testcase2->setFillColor(sf::Color::Red);
	testcase2->setPosition(395.f, 420.f);

	testcase3->setString("Test Case 3");
	testcase3->setCharacterSize(25);
	testcase3->setFillColor(sf::Color::Red);
	testcase3->setPosition(395.f, 500.f);

	testcase4->setString("Test Case 4");
	testcase4->setCharacterSize(25);
	testcase4->setFillColor(sf::Color::Red);
	testcase4->setPosition(395.f, 580.f);

	testcase5->setString("Test Case 5");
	testcase5->setCharacterSize(25);
	testcase5->setFillColor(sf::Color::Red);
	testcase5->setPosition(395.f, 660.f);

	exitText->setString("Exit Game");
	exitText->setCharacterSize(25);
	exitText->setFillColor(sf::Color::Red);
	exitText->setPosition(410.f, 740.f);


}

int check_mouse_pos(Vector2i mouse_pos) {

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

void draw_menu(RenderWindow *window, RectangleShape outerbox, RectangleShape test1, RectangleShape start_playable, RectangleShape test2, RectangleShape test3, RectangleShape test4, RectangleShape test5, RectangleShape exit){
	window->draw(outerbox);
	window->draw(test1);
	window->draw(start_playable);
	window->draw(test2);
	window->draw(test3);
	window->draw(test4);
	window->draw(test5);
	window->draw(exit);

	}

void draw_menu2(RenderWindow *window, Text manu_title, Text startplayable, Text testcase1, Text testcase2, Text testcase3, Text testcase4, Text testcase5, Text exitText){
	window->draw(manu_title);
	window->draw(startplayable);
	window->draw(testcase1);
	window->draw(testcase2);
	window->draw(testcase3);
	window->draw(testcase4);
	window->draw(testcase5);
	window->draw(exitText);
}

void title_score_game_setup(Font* MyFont, sf::Text* title, Text* titleshadow, Text* score, Text* scoreshadow) {
	//title 
	title->setFont(*MyFont);
	title->setString("PINBALL");
	title->setCharacterSize(70);
	title->setFillColor(sf::Color::Red);
	title->setPosition(25.f, 750.f);
	//shadow of title
	titleshadow->setFont(*MyFont);
	titleshadow->setString("PINBALL");
	titleshadow->setCharacterSize(70);
	titleshadow->setFillColor(sf::Color::Blue);
	titleshadow->setPosition(30.f, 755.f);
	//score
	score->setFont(*MyFont);
	score->setString("Score:");
	score->setCharacterSize(50);
	score->setFillColor(sf::Color::Red);
	score->setPosition(45.f, 50.f);
	//shadow of score
	scoreshadow->setFont(*MyFont);
	scoreshadow->setString("Score:");
	scoreshadow->setCharacterSize(50);
	scoreshadow->setFillColor(sf::Color::Blue);
	scoreshadow->setPosition(50.f, 55.f);
}



#endif
