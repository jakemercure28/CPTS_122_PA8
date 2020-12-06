#ifndef PINBALL_MENU_H
#define PINBALL_MENU_H

#include <SFML/Graphics.hpp>

using namespace sf;

int menu(RenderWindow*);
void drawMenu(RenderWindow*);
int check_mouse_pos(Vector2i mouse_pos);

#endif