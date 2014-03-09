//
//  ViewGround.h
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#ifndef __Kuafu__ViewGround__
#define __Kuafu__ViewGround__

#include <iostream>
#include "View.h"
#include "cinder/gl/Texture.h"

using namespace bongiovi;

class ViewGround : public View {
public:
    ViewGround();
    ViewGround(string vsPath, string fsPath);
    void                    render(gl::TextureRef);
    
private:
    void                    _init();
};

#endif /* defined(__Kuafu__ViewGround__) */
