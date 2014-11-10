#include "..\include\TrimetPoint.h"


TrimetPoint::TrimetPoint(ci::Vec2d pos, std::string label) : RadarPoint(pos, label)
{
}

ci::Vec2d TrimetPoint::getPosition() {
	return position;
}

void TrimetPoint::updatePosition(ci::Vec2d pos)
{
};
