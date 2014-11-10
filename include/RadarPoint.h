#pragma once
#include "cinder/Cinder.h"
#include "cinder/Vector.h"

class RadarPoint
{
protected:
	RadarPoint(ci::Vec2d pos, std::string label) : position(pos), label(label) {};
	virtual void updatePosition(ci::Vec2d pos) = 0;
	virtual ci::Vec2d getPosition(void) = 0;

	ci::Vec2d position;
	std::string label;
};
