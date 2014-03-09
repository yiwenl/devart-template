//
//  ViewMountains.h
//  Kuafu
//
//  Created by Yiwen on 28/02/2014.
//
//

#ifndef __Kuafu__ViewMountains__
#define __Kuafu__ViewMountains__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "Mountain.h"
#include "View.h"
#include "cinder/Perlin.h"

using namespace bongiovi;

class ViewMountain : public View {
public:
    ViewMountain(Mountain*, gl::TextureRef);
    void                    render();
    
private:
    void                    _init();
    Mountain*               _mountain;
    Perlin                  _perlin;
    gl::TextureRef          _texture;
};

#endif /* defined(__Kuafu__ViewMountains__) */
