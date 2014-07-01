#pragma once
#include "radarpoint.h"
class TrimetPoint :
	public RadarPoint
{
public:
	TrimetPoint(cinder::Vec2d pos, std::string label);
	void updatePosition(cinder::Vec2d pos);
};

