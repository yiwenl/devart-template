//
//  ViewGiant.h
//  Kuafu
//
//  Created by Yiwen on 12/03/2014.
//
//

#ifndef __Kuafu__ViewGiant__
#define __Kuafu__ViewGiant__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "cinder/TriMesh.h"
#include "cinder/ObjLoader.h"
#include "View.h"


using namespace bongiovi;

class ViewGiant : public View {
public:
    ViewGiant();
    void                    render(gl::TextureRef);
    
private:
    void                    _init();
    cinder::TriMesh         _meshGiant;
};

#endif /* defined(__Kuafu__ViewGiant__) */
