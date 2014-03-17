#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"

#include "GiantModel.h"
#include "GlobalSettings.h"
#include "SceneKuafu.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class KuafuApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    void keyDown( KeyEvent event );
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseWheel( MouseEvent event );
    
    private :
    SceneKuafu*                 _scene;
    params::InterfaceGlRef      _params;
};

void KuafuApp::setup()
{
    int w = 1280;
    setWindowSize(w, w*9/16);
    setFrameRate(60);
    setWindowPos(0, 0);
    srand(time(NULL));
    gl::enable( GL_TEXTURE_2D );
    gl::enable( GL_TEXTURE_RECTANGLE_ARB );
    gl::enable( GL_DEPTH_TEST );
//    gl::enable( GL_CULL_FACE );
    gl::enableAlphaBlending();
    gl::Texture::Format fmt;
    fmt.enableMipmapping();
    fmt.setMinFilter(GL_LINEAR_MIPMAP_LINEAR);
    getWindow()->setTitle("Kuafu the giant - 夸父追日");
    
    _scene = new SceneKuafu();
    GiantModel::getInstance().init(_scene);
    
    _params = params::InterfaceGl::create( "Kuafu the Giant", Vec2i( 300, getWindowHeight()-50 ) );
    _params->addSeparator();
    _params->addText("Mountains Visual");
    _params->addParam( "Contrast", &GlobalSettings::getInstance().contrast, "min=0.0 max=1.0 step=.02");
    _params->addParam( "Saturation", &GlobalSettings::getInstance().saturation, "min=0.0 max=1.0 step=.02");
    _params->addParam( "Brightness", &GlobalSettings::getInstance().brightness, "min=0.0 max=10.0 step=.1");

}


void KuafuApp::update() {
    GiantModel::getInstance().update();
    _scene->update();
}

void KuafuApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    _scene->render();
    _params->draw();
}


void KuafuApp::mouseWheel( MouseEvent event ){
    _scene->cameraDistance -= event.getWheelIncrement() * 2.0f;
}

void KuafuApp::mouseDown( MouseEvent event ){
    _scene->sceneQuat->mouseDown(event.getPos());
    _scene->cameraKuafu->mouseDown(event.getPos());
}

void KuafuApp::mouseUp( MouseEvent event ){
    _scene->sceneQuat->mouseUp(event.getPos());
    _scene->cameraKuafu->mouseUp(event.getPos());
}

void KuafuApp::mouseDrag( MouseEvent event ){
    _scene->sceneQuat->mouseDrag(event.getPos());
    _scene->cameraKuafu->mouseDrag(event.getPos());
}

void KuafuApp::mouseMove( MouseEvent event ){
    Vec2f pos = event.getPos();
    _scene->sceneQuat->mouseMove(pos);
}


void KuafuApp::keyDown( KeyEvent event) {
    switch(event.getChar()) {
        case 'f' :
            setFullScreen(!isFullScreen());
            break;
        case 'h' :
            if(_params->isMaximized() ) _params->minimize();
            else _params->maximize();
            break;
            
    }
}

CINDER_APP_NATIVE( KuafuApp, RendererGl )
