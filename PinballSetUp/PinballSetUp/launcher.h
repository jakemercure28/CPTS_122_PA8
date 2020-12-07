#ifndef LAUNCHER_H
#define LAUNCHER_H

#define MAXPULLBACK 70
#include <SFML/Graphics.hpp>

using namespace sf;
class launcher
{
private:
	Vector2f position;
	ConvexShape launcherShape;
	// holds how far back the launcher has been pulled for force calculations
	float pullback;

public:
	// Constructor
	launcher(float initX, float initY);
	// getters
	Vector2f getposition();
	ConvexShape getShape();
	// member functions
	int moveLauncher(bool upDown, int* max_pull_back);
	int moveLauncher_slow();
	int moveLauncher_medium();
	int moveLauncher_fast();
	void pullBack();
	void release();
	void update();
};
#endif