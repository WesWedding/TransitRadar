#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "RadarData.h"

class TransitRadarApp : public ci::app::AppNative {
  public:
	void setup();
	void mouseDown( ci::app::MouseEvent event );	
	void update();
	void draw();
	static ci::Vec2d projectPoint(const RadarPoint &point, double upLeftCorner, double botRightCorner);

private:
	RadarData data;

};

void TransitRadarApp::setup()
{
	// Grab the initial data
	data.update();



	// Set the viewport to render a view of a map with the following borders:
	//    Upper left: 45.5314969,-122.6667829
	//    Bottom right: 45.5219859,-122.6525972
}

void TransitRadarApp::mouseDown( ci::app::MouseEvent event )
{
}

void TransitRadarApp::update()
{
	data.update();
}

void TransitRadarApp::draw()
{
	// clear out the window with black
	ci::gl::clear( ci::Color( 0, 0, 0 ) ); 

	data.draw();

	// Project those RadarPoints points onto our view!
}

ci::Vec2d TransitRadarApp::projectPoint(const RadarPoint &point, double upLeftCorner, double botRightCorner) 
{
	return ci::Vec2d();
}

CINDER_APP_NATIVE( TransitRadarApp, ci::app::RendererGl )
