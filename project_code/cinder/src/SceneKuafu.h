//
//  SceneKuafu.h
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#ifndef __Kuafu__SceneKuafu__
#define __Kuafu__SceneKuafu__

#include <iostream>
#include "cinder/qtime/QuickTime.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Fbo.h"
#include "Scene.h"
#include "CameraKuafa.h"
#include "ViewSun.h"
#include "ViewGround.h"
#include "ViewBackground.h"
#include "ViewMountains.h"
#include "ViewGiant.h"
#include "ViewCircleBg.h"

using namespace bongiovi;

class SceneKuafu : public Scene {
    public :
    SceneKuafu();
    void                    update();
    void                    render();
    void                    generateMountains();
    CameraKuafu*            cameraKuafu;
    
    
    private :
    void                    _initTextures();
    void                    _initViews();
    qtime::MovieGl          _movie;

    // VIEWS
    ViewBackground*         _vBg;
    ViewGround*             _vGround;
    ViewSun*                _vSun;
    ViewGiant*              _vGiant;
    ViewCircleBg*           _vCirBg;
    vector<ViewMountain*>   _mountains;

    // TEXTURES
    gl::TextureRef          _texBg;
    gl::TextureRef          _texGround;
    gl::TextureRef          _texSun;
    vector<gl::TextureRef>  _inkTextures;
    
    //  FBO
    gl::Fbo*                _fboPost;

};

#endif /* defined(__Kuafu__SceneKuafu__) */
