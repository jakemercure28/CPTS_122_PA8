#ifndef CONVEXRECT_H
#define CONVEXRECT_H
#include"convex_shape.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class ConvexRect:convex_shape
{
private:
	Vector2f position;

public:
	ConvexRect(float initX, float initY,float width, float height,float rotation=0,const Color=Color::White);
	Vector2f getposition();
	virtual ConvexShape getShape();
};


#endif