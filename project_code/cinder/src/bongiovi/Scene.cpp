//
//  Scene.cpp
//  KuaFuCinder
//
//  Created by Yiwen on 08/01/2014.
//
//

#include "Scene.h"
#include "cinder/Camera.h"

using namespace ci;
using namespace std;
using namespace bongiovi;


Scene::Scene() {
    _camera         = new CameraPersp();
    _cameraOrtho    = new CameraOrtho();
    sceneQuat       = new SceneQuat();
    
    cameraDistance  = 500.0f;
	_eye			= Vec3f( 0.0f, 0.0f, cameraDistance );
	_center			= Vec3f::zero();
	_up				= Vec3f::yAxis();
	_camera->setPerspective( 45.0f, ci::app::getWindowAspectRatio(), 1.0f, 2000.0f );
    _cameraOrtho->setOrtho( -1, 1, -1, 1, -1, 1 );
};



void Scene::update() {
    sceneQuat->update();
    _eye = Vec3f( 0.0f, 0.0f, cameraDistance );
	_camera->lookAt( _eye, _center, _up );
	gl::setMatrices( *_camera );
    gl::rotate(sceneQuat->quat);
}


void Scene::render() {
    cout << "Shouldn't show this render" << endl;
}