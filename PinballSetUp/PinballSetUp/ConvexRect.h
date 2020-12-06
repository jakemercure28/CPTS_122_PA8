#ifndef CONVEXRECT_H
#define CONVEXRECT_H

#include <SFML/Graphics.hpp>
using namespace sf;
class ConvexRect
{
private:
	Vector2f position;
	ConvexShape rectShape;

public:
	ConvexRect(float initX, float initY,float width, float height,float rotation=0,const Color=Color::White);
	Vector2f getposition();
	ConvexShape getShape();
};


#endif