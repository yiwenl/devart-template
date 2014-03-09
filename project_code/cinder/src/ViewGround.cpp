//
//  ViewGround.cpp
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#include "ViewGround.h"

ViewGround::ViewGround() : View("shaders/copy.vert", "shaders/copy.frag") {
    _init();
}

ViewGround::ViewGround(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewGround::_init() {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    float size = 3000;
    float y = -100;
    positions.push_back(Vec3f(-size,   y, -size));
    positions.push_back(Vec3f( size,   y, -size));
    positions.push_back(Vec3f( size,   y,  size));
    positions.push_back(Vec3f(-size,   y,  size));
    
    float coordOffset = 10.0f;
    coords.push_back(Vec2f(0, coordOffset));
    coords.push_back(Vec2f(coordOffset, coordOffset));
    coords.push_back(Vec2f(coordOffset, 0));
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


void ViewGround::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind(0);
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}