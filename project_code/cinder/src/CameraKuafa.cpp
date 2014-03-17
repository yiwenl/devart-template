//
//  CameraKuafa.cpp
//  Kuafu
//
//  Created by Yiwen on 03/03/2014.
//
//

#include "CameraKuafa.h"

#define cameraSpeed .05f

CameraKuafu::CameraKuafu() {
    _mouse.set(0, 0);
    _preMouse.set(0, 0);
    camera.set(1.0f, 0.0f, 0.0f);
    _targetRx = 0.0f;
    _targetRy = 0.0f;
}


void CameraKuafu::mouseDown(Vec2i pos) {
    _needUpdate     = true;
    _preMouse       = pos;
    _tempRx         = _rx;
    _tempRy         = _ry;
}

void CameraKuafu::mouseUp(Vec2i pos) {
    _needUpdate     = false;
}

void CameraKuafu::mouseDrag(Vec2i pos) {
    _mouse          = pos;
}

void CameraKuafu::update() {
    if(_needUpdate) {
        _updateDistance();
        _targetRx = _tempRx + _distX;
        _targetRy = _tempRy + _distY;
    }
    
//    _rx += (_targetRx - _rx) * cameraSpeed;
    _ry += (_targetRy - _ry) * cameraSpeed;
    
    if(_rx > M_PI_2) {
        _rx = _targetRx = M_PI_2;
    } else if ( _rx < -M_PI_2) {
        _rx = _targetRx = -M_PI_2;
    }
    
    camera.x = -cos(_rx) * cos(_ry);
    camera.y = -sin(_rx);
    camera.z = cos(_rx) * sin(_ry);
}



void CameraKuafu::setRotateY(float theta) {
    _targetRy = theta;
}

void CameraKuafu::_updateDistance() {
    _distY = (_mouse.x - _preMouse.x) / 200.0f;
    _distX = -(_mouse.y - _preMouse.y) / 200.0f;
}