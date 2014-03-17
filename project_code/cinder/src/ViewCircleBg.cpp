//
//  ViewCircleBg.cpp
//  Kuafu
//
//  Created by Yiwen on 13/03/2014.
//
//

#include "ViewCircleBg.h"

ViewCircleBg::ViewCircleBg() : View("shaders/copy.vert", "shaders/copy.frag"){
    _init();
}


void ViewCircleBg::_init() {
    _texture = Utils::createTexture("common/background.jpg");
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    int i, j, count = 0;
    float numSeg = 36;
    float height = 2200;
    float radius = 2500;
    float segSize = height/(float)numSeg;
    float uvBase = 1.0/numSeg;
    float startPos = 400.0f;
    float theta, x0, z0, x1, z1;
    
    for(j=0; j<numSeg; j++) {
        for(i=0; i<numSeg; i++) {
            theta = i/numSeg * M_PI * 2;
            x0 = radius * cos(theta);
            z0 = radius * sin(theta);
            
            theta = (i+1)/numSeg * M_PI * 2;
            x1 = radius * cos(theta);
            z1 = radius * sin(theta);
            
            positions.push_back(Vec3f(x0,       -startPos + j*segSize,   z0));
            positions.push_back(Vec3f(x1,       -startPos + j*segSize,   z1));
            positions.push_back(Vec3f(x1,       -startPos + (j+1)*segSize,   z1));
            positions.push_back(Vec3f(x0,       -startPos + (j+1)*segSize,   z0));
            
            coords.push_back(Vec2f(uvBase*i, 1.0-uvBase*j));
            coords.push_back(Vec2f(uvBase*(i+1), 1.0-uvBase*j));
            coords.push_back(Vec2f(uvBase*(i+1), 1.0-uvBase*(j+1)));
            coords.push_back(Vec2f(uvBase*i, 1.0-uvBase*(j+1)));
            
            
            indices.push_back(count*4+0);
            indices.push_back(count*4+1);
            indices.push_back(count*4+3);
            indices.push_back(count*4+1);
            indices.push_back(count*4+2);
            indices.push_back(count*4+3);
            
            count++;
        }
    }
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
}


void ViewCircleBg::render() {
    shader->bind();
    shader->uniform("texture", 0);
    _texture->bind(0);
    gl::draw(mesh);
    _texture->unbind();
    shader->unbind();
}