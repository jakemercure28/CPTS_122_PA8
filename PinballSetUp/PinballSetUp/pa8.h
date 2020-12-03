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






#endif
