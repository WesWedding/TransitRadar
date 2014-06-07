#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TransitRadarApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void TransitRadarApp::setup()
{
}

void TransitRadarApp::mouseDown( MouseEvent event )
{
}

void TransitRadarApp::update()
{
}

void TransitRadarApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( TransitRadarApp, RendererGl )
