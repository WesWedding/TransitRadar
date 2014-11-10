#pragma once
#include "radarpoint.h"
class TrimetPoint :
	public RadarPoint
{
public:
	TrimetPoint(ci::Vec2d pos, std::string label);
	ci::Vec2d getPosition();
	void updatePosition(cinder::Vec2d pos);
};

