#include "..\include\RadarPointDrawer.h"

#include "cinder\gl\gl.h"
#include "cinder\app\app.h"


RadarPointDrawer::RadarPointDrawer(void)
{
}


RadarPointDrawer::~RadarPointDrawer(void)
{
}

void
RadarPointDrawer::drawPoint(const RadarPoint& point) {
	ci::gl::drawSolidCircle(ci::Vec2f(0.0f, 0.0f) + ci::app::getWindowSize() / 2, 50.0f);
}
