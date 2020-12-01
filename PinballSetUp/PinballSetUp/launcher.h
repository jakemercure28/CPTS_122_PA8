#ifndef LAUNCHER_H
#define LAUNCHER_H


#include <SFML/graphics.hpp>

using namespace sf;

class launcher
{
private:
	Vector2f position;
	ConvexShape launcherShape;

	float yVelocity = 0;

public:

	launcher(float initX, float initY);

	Vector2f getposition() {
		return position;
	}

	ConvexShape getShape() {
		return launcherShape;
	}

	float getVelocity() {
		return yVelocity;
	}

	void hitbottom();


	void update() {
		position.x = launcherShape.getPoint(0).x;
		position.y = launcherShape.getPoint(0).y;
	}

	void launch(int velocity);



};

#endif

