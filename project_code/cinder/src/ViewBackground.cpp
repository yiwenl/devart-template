//
//  ViewBackground.cpp
//  v10
//
//  Created by Yiwen on 17/02/2014.
//
//


#include "ViewBackground.h"

ViewBackground::ViewBackground() : View("shaders/copy.vert", "shaders/copy.frag") {
    _init();
}

ViewBackground::ViewBackground(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewBackground::_init() {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    float size = 1;
    positions.push_back(Vec3f(-size,   -size,   0));
    positions.push_back(Vec3f( size,   -size,   0));
    positions.push_back(Vec3f( size,    size,   0));
    positions.push_back(Vec3f(-size,    size,   0));
    
    coords.push_back(Vec2f(0, 1));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(0, 0));
    
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
}


void ViewBackground::render(gl::Texture texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture.bind(0);
    gl::draw(mesh);
    texture.unbind();
    shader->unbind();
}


void ViewBackground::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind(0);
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}
