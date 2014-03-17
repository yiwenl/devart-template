//
//  ViewGiant.cpp
//  Kuafu
//
//  Created by Yiwen on 12/03/2014.
//
//

#include "ViewGiant.h"


ViewGiant::ViewGiant() : View("shaders/giant.vert", "shaders/giant.frag") {
    _init();
}



void ViewGiant::_init() {
//    ObjLoader loader( cinder::app::loadResource("models/kuafuModel.obj"));
    ObjLoader loader( cinder::app::loadResource("models/testTorso.obj"));
    loader.load( &_meshGiant );
}


void ViewGiant::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind(0);
//    gl::draw(mesh);
    gl::draw(_meshGiant);
    texture->unbind();
    shader->unbind();
}


void ViewGiant::render(gl::Texture texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture.bind(0);
    gl::draw(_meshGiant);
    texture.unbind();
    shader->unbind();
}