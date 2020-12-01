#ifndef LAUNCHER_H
#define LAUNCHER_H

#define MAXPULLBACK 50
#include <SFML/Graphics.hpp>

using namespace sf;
class launcher
{
private:
	Vector2f position;
	ConvexShape launcherShape;
	float pullback;

public:
	launcher(float initX, float initY);
	Vector2f getposition();
	ConvexShape getShape();

	void pullBack();
	void release();
	void update();
};
#endif