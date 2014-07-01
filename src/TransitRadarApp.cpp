#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "RadarData.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TransitRadarApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

private:
	RadarData data;

};

void TransitRadarApp::setup()
{
	data.update();
}

void TransitRadarApp::mouseDown( MouseEvent event )
{
}

void TransitRadarApp::update()
{
	data.update();
}

void TransitRadarApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( TransitRadarApp, RendererGl )
