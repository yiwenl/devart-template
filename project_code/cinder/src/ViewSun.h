//
//  ViewSun.h
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#ifndef __Kuafu__ViewSun__
#define __Kuafu__ViewSun__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "View.h"

using namespace bongiovi;

class ViewSun : public View {
public:
    ViewSun();
    ViewSun(string vsPath, string fsPath);
    void                    render(gl::TextureRef texture);
    
private:
    void                    _init();
    Vec3f                   _getVertex(int, int, float);
    Vec3f                   _getVertex(int, int, float, float);
};

#endif /* defined(__Kuafu__ViewSun__) */
