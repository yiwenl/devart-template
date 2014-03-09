//
//  ViewMountains.cpp
//  Kuafu
//
//  Created by Yiwen on 28/02/2014.
//
//

#include "ViewMountains.h"
#include "GlobalSettings.h"


ViewMountain::ViewMountain(Mountain* m, gl::TextureRef texture) : View("shaders/mountain.vert", "shaders/mountain.frag") {
    _texture    = texture;
    _mountain   = m;
    _init();
}


void ViewMountain::_init() {
    float _size     = _mountain->height * 5.0;
    float _height   = _mountain->height * 1.0;
    int _num        = 50;
    float posOffset = 30.0;
    float _x        = _mountain->x*posOffset;
    float _z        = _mountain->y*posOffset;
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticPositions();
    layout.setStaticTexCoords2d();
    layout.mCustomStatic.push_back(make_pair(gl::VboMesh::Layout::CUSTOM_ATTR_FLOAT3, 0 ));
    
    int i = 0;
    int j = 0;
    int index = 0;
    float sx = -_size/2 + _x;
    float sy = -_size/2 + _z;
    float span = _size / _num;
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    vector<Vec3f> rotations;
    
    float h = (rand() % 100 )/100 * _height;
    float power = rand() % 3 + 2;
    float perlinOffset = .05f;
    float perlinHeight;
    float seed = rand() % 10000;
    
    
    for(j=0; j<=_num; j++) {
        for(i=0; i<=_num; i++){
            perlinHeight = _perlin.fBm(Vec3f(i*perlinOffset, j*perlinOffset, seed)) * 20.0f;
            h = sin((float)i/_num * pi) * sin((float)j/_num * pi);
            h = pow(h, power) * _height-100.0f + perlinHeight*h;
//            cout << h << endl;
            positions.push_back(Vec3f(sx + i*span, h, sy + j*span));
            coords.push_back(Vec2f( (float)i/_num, (float)j/_num));
            rotations.push_back(Vec3f(1.0, 1.0, 1.0) );
        }
    }
    
    for ( j = 0; j<_num; j++) {
        for ( i = 0; i<_num; i++) {
            index = i + j * (_num+1);
            
            indices.push_back(index+1);
            indices.push_back(index+_num+1);
            indices.push_back(index+_num+2);
            indices.push_back(index+_num+1);
            indices.push_back(index+1);
            indices.push_back(index);
        }
    }
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
    
    mesh.getStaticVbo().bind();
    size_t offset = sizeof(Vec3f) * positions.size() + sizeof(Vec2f) * coords.size();
    mesh.getStaticVbo().bufferSubData(offset, sizeof(Vec3f)*rotations.size(), &rotations[0] );
    mesh.getStaticVbo().unbind();
    
    shader->bind();
    GLuint loc = shader->getAttribLocation("colorOffset");
    mesh.setCustomStaticLocation(0, loc);
    shader->unbind();

}


void ViewMountain::render() {
    shader->bind();
    shader->uniform( "texture", 0 );
    shader->uniform( "contrastOffset", GlobalSettings::getInstance().contrast );
    shader->uniform( "saturationOffset", GlobalSettings::getInstance().saturation);
    shader->uniform( "brightness", GlobalSettings::getInstance().brightness );
    _texture->bind(0);
    gl::draw(mesh);
    _texture->unbind();
    shader->unbind();
}