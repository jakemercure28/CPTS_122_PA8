#ifndef PINBALL_GAME_H
#define PINBALL_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ball.h"
#include "bumper.h"
#include "band_bumper.h"
#include "ConvexRect.h"
#include "launcher.h"
#include "flipper.h"
#include "sound.h"


using namespace sf;

int play_game(RenderWindow*,int testCase=0);
void setLaunches(Text*, int);
void setSetting(ball*,Text*, int);
std::vector<ConvexShape> createCollidableObject();
std::vector<Text> createTextObjects(Font*);
void update_score(RenderWindow* window, Text* score_counter, int score_count);

#endif