//
//  SceneKuafu.cpp
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#include "SceneKuafu.h"
#include "GiantModel.h"
#include "Utils.h"

using namespace bongiovi::utils;

SceneKuafu::SceneKuafu() {
    _initTextures();
    _initViews();
    cameraKuafu = new CameraKuafu();
}


void SceneKuafu::_initTextures() {
    _texBg          = Utils::createTexture("common/background.png");
    _texSun         = Utils::createTexture("common/sun.png");
    _texGround      = Utils::createTexture("common/ground.png");
    
    int i = 0;
    for(i=1; i<=27; i++) {
        string s = to_string(i);
        while(s.length() < 2) s = "0" + s;
        s = "red/TextureRed" + s + ".jpg";
        gl::TextureRef t = gl::Texture::create( loadImage( app::loadResource( s ) ) );
        _inkTextures.push_back(t);
    }
    
    gl::Fbo::Format format;
    format.setColorInternalFormat( GL_RGBA32F_ARB );
    format.setMinFilter(GL_LINEAR_MIPMAP_LINEAR);
    format.setMagFilter(GL_LINEAR_MIPMAP_LINEAR);
    
    int size = 1024;
    _fboPost = new gl::Fbo(size, size, format);
}


void SceneKuafu::_initViews() {
    _vBg            = new ViewBackground();
    _vGround        = new ViewGround();
    _vSun           = new ViewSun();
}


void SceneKuafu::generateMountains() {
    vector<Mountain*> mountains = GiantModel::getInstance().getMountains();
    
    cout << "Generate Mountains" << endl;
    vector<Mountain*>::iterator it = mountains.begin();
    while(it!= mountains.end() ) {
        ViewMountain* vm = new ViewMountain(*it, _inkTextures[rand()%_inkTextures.size()]);
        _mountains.push_back(vm);
        it++;
    }
}

void SceneKuafu::update() {
    sceneQuat->update();
    cameraKuafu->update();
    _center.y = 20.0f;
//    _eye = Vec3f( 0.0f, 0.0f, cameraDistance );
    _eye.set(cameraKuafu->camera * cameraDistance);
	_camera->lookAt( _eye, _center, _up );
	gl::setMatrices( *_camera );
//    gl::rotate(sceneQuat->quat);
}


void SceneKuafu::render() {
    gl::setMatrices(*_cameraOrtho);

    gl::disable(GL_DEPTH_TEST);
    _vBg->render(_texBg);
    gl::enable(GL_DEPTH_TEST);
    
    gl::setMatrices(*_camera);
//    gl::rotate(sceneQuat->quat);
    _vGround->render(_texGround);
    _vSun->render(_texSun);
    
    vector<ViewMountain*>::iterator iter = _mountains.begin();
    while(iter != _mountains.end()) {
        (*iter)->render();
        iter++;
    }
}