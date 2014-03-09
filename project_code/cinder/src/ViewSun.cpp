//
//  ViewSun.cpp
//  Kuafu
//
//  Created by Yiwen on 27/02/2014.
//
//

#include "ViewSun.h"

ViewSun::ViewSun() : View("shaders/copy.vert", "shaders/copy.frag") {
    _init();
}

ViewSun::ViewSun(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewSun::_init() {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    int i, j, index = 0;
    float numSeg = 80;
    float uvBase = 1.0/numSeg;
    float radius = 50.0f;
    Vec3f pos(0.0, 100.0, 0.0);
    
    for(j=0; j<=numSeg; j++) {
        for(i=0; i<=numSeg; i++) {
            Vec3f p = _getVertex(i, j, numSeg, radius);
            p += pos;
            positions.push_back(p);
            coords.push_back(Vec2f(i*uvBase, j*uvBase));
        }
    }
    
    
    for(j=0; j<numSeg; j++) {
        for(i=0; i<numSeg; i++) {
            index = i + j * ( numSeg +1);
            indices.push_back(index);
            indices.push_back(index+1);
            indices.push_back(index+numSeg+1);
            indices.push_back(index+1);
            indices.push_back(index+numSeg+2);
            indices.push_back(index+numSeg+1);
        }
    }

    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
}


Vec3f ViewSun::_getVertex(int i, int j, float numSeg) { return _getVertex(i, j, numSeg, 1.0f); }

Vec3f ViewSun::_getVertex(int i, int j, float numSeg, float radius) {
    Vec3f p;
    float angle0 = j/numSeg * M_PI - M_PI_2;
    float angle1 = i/numSeg * M_PI * 2.0f;
    
    p.y = radius*sin(angle0);
    p.x = radius*cos(angle0) * sin(angle1);
    p.z = radius*cos(angle0) * cos(angle1);
    
    return p;
}


void ViewSun::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind(0);
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}