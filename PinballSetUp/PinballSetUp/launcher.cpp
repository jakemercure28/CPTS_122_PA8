#include "launcher.h"

launcher::launcher(float initX, float initY) {
	position.x = initX;
	position.y = initY;
	launcherShape.setPointCount(8);
	launcherShape.setPoint(0, Vector2f(625.f, 830.f));
	launcherShape.setPoint(1, Vector2f(685.f, 830.f));
	launcherShape.setPoint(2, Vector2f(685.f, 845.f));
	launcherShape.setPoint(3, Vector2f(665.f, 845.f));
	launcherShape.setPoint(4, Vector2f(665.f, 900.f));
	launcherShape.setPoint(5, Vector2f(645.f, 900.f));
	launcherShape.setPoint(6, Vector2f(645.f, 845.f));
	launcherShape.setPoint(7, Vector2f(625.f, 845.f));
	launcherShape.setFillColor(Color::Red);
	yVelocity = 0;
}

void launcher::launch(int velocity) {
	if (velocity == 2) {
		launcherShape.move(0.f, 20.f);
		sleep(milliseconds(1000));
		//launcherShape.move(0.f, -20.f);
		//update();
	}
	else if (velocity == 5) {
		launcherShape.move(0.f, 40.f);
		//launcherShape.move(0.f, -40.f);
	}
	else if (velocity == 10) {
		launcherShape.move(0.f, 60.f);
		//launcherShape.move(0.f, -60.f);
	}

}