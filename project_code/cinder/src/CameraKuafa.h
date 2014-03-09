//
//  CameraKuafa.h
//  Kuafu
//
//  Created by Yiwen on 03/03/2014.
//
//

#ifndef __Kuafu__CameraKuafa__
#define __Kuafu__CameraKuafa__

#include <iostream>

using namespace ci;
using namespace std;

class CameraKuafu {
    public :
    CameraKuafu();
    void            mouseDown(Vec2i);
    void            mouseUp(Vec2i);
    void            mouseDrag(Vec2i);
    void            update();
    Vec3f           camera;

    private :
    void            _updateDistance();
    
    bool            _needUpdate;
    Vec2i           _preMouse;
    Vec2i           _mouse;
    
    
    float           _targetRx;
    float           _tempRx;
    float           _rx;
    
    float           _targetRy;
    float           _tempRy;
    float           _ry;
    
    
    float           _distX;
    float           _distY;
    
    
};

#endif /* defined(__Kuafu__CameraKuafa__) */
