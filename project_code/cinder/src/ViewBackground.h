//
//  ViewBackground.h
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#ifndef __Kuafu__ViewBackground__
#define __Kuafu__ViewBackground__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "View.h"

using namespace bongiovi;

class ViewBackground : public View {
    public :
    ViewBackground();
    ViewBackground(string, string);
    void        render(gl::Texture);
    void        render(gl::TextureRef);
    
    private :
    void        _init();
};


#endif /* defined(__Kuafu__ViewBackground__) */
