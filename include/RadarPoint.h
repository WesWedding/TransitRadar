#pragma once
#include "cinder/Cinder.h"
#include "cinder/Vector.h"
class RadarPoint
{
protected:
	RadarPoint(cinder::Vec2d pos, std::string label) : position(pos), label(label) {};
	virtual void updatePosition(cinder::Vec2d pos) = 0;
	virtual cinder::Vec2d getPosition(void) = 0;

	cinder::Vec2d position;
	std::string label;
};
