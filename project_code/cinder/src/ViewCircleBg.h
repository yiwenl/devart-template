//
//  ViewCircleBg.h
//  Kuafu
//
//  Created by Yiwen on 13/03/2014.
//
//

#ifndef __Kuafu__ViewCircleBg__
#define __Kuafu__ViewCircleBg__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "Utils.h"
#include "View.h"

using namespace bongiovi;
using namespace bongiovi::utils;

class ViewCircleBg : public View {
public:
    ViewCircleBg();
    void                    render();
    
private:
    void                    _init();
    gl::TextureRef          _texture;
};

#endif /* defined(__Kuafu__ViewCircleBg__) */
