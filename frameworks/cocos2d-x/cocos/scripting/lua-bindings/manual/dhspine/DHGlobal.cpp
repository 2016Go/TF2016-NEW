//
//  DHGlobal.cpp
//  MyTest
//
//  Created by youbin on 14-12-31.
//
//

#include "DHGlobal.h"

NS_CC_BEGIN

PolygonDrawCmd::PolygonDrawCmd()
:textureID(0)
,verticesCount(0)
,trianglesCount(0)
,blendMode(SpineBlendType::sbt_none)
,hue(0) {
    
}

PolygonDrawCmd::~PolygonDrawCmd() {
    
}
    
void DHMatrix::matrixMult(float a[3][3], float b[3][3], float c[3][3]) {
    int x, y;
    float temp[3][3];
    
    for(y=0; y<3; y++) {
        for(x=0; x<3; x++) {
            temp[y][x] = b[y][0] * a[0][x] + b[y][1] * a[1][x] + b[y][2] * a[2][x];
        }
    }
    for(y=0; y<3; y++) {
        for(x=0; x<3; x++) {
            c[y][x] = temp[y][x];
        }
    }
}

void DHMatrix::xRotateMat(float mat[3][3], float rs, float rc) {
    mat[0][0] = 1.0;
    mat[0][1] = 0.0;
    mat[0][2] = 0.0;
    
    mat[1][0] = 0.0;
    mat[1][1] = rc;
    mat[1][2] = rs;
    
    mat[2][0] = 0.0;
    mat[2][1] = -rs;
    mat[2][2] = rc;
}
    
void DHMatrix::yRotateMat(float mat[3][3], float rs, float rc) {
    mat[0][0] = rc;
    mat[0][1] = 0.0;
    mat[0][2] = -rs;
    
    mat[1][0] = 0.0;
    mat[1][1] = 1.0;
    mat[1][2] = 0.0;
    
    mat[2][0] = rs;
    mat[2][1] = 0.0;
    mat[2][2] = rc;
}

void DHMatrix::zRotateMat(float mat[3][3], float rs, float rc) {
    mat[0][0] = rc;
    mat[0][1] = rs;
    mat[0][2] = 0.0;
    
    mat[1][0] = -rs;
    mat[1][1] = rc;
    mat[1][2] = 0.0;
    
    mat[2][0] = 0.0;
    mat[2][1] = 0.0;
    mat[2][2] = 1.0;
}
    
void DHMatrix::hueMatrix(float angle) {
    if (angle == 0) {
        mat[0][0] = 1.0;
        mat[0][1] = 0.0;
        mat[0][2] = 0.0;
        
        mat[1][0] = 0.0;
        mat[1][1] = 1.0;
        mat[1][2] = 0.0;
        
        mat[2][0] = 0.0;
        mat[2][1] = 0.0;
        mat[2][2] = 1.0;
        return;
    }
    
#define SQRT_2      sqrt(2.0)
#define SQRT_3      sqrt(3.0)
    
    float mag, rot[3][3];
    float xrs, xrc;
    float yrs, yrc;
    float zrs, zrc;
    
    // Rotate the grey vector into positive Z
    mag = SQRT_2;
    xrs = 1.0/mag;
    xrc = 1.0/mag;
    xRotateMat(mat, xrs, xrc);
    mag = SQRT_3;
    yrs = -1.0/mag;
    yrc = SQRT_2/mag;
    yRotateMat(rot, yrs, yrc);
    matrixMult(rot, mat, mat);
    
    // Rotate the hue
    zrs = sin(angle);
    zrc = cos(angle);
    zRotateMat(rot, zrs, zrc);
    matrixMult(rot, mat, mat);
    
    // Rotate the grey vector back into place
    yRotateMat(rot, -yrs, yrc);
    matrixMult(rot,  mat, mat);
    xRotateMat(rot, -xrs, xrc);
    matrixMult(rot,  mat, mat);
}

void DHMatrix::saturationMatrix(float s) {
    if (s == 1) {
        return;
    }
    
    const float rwgt = 0.3086;
    const float gwgt = 0.6094;
    const float bwgt = 0.0820;
    float rot[3][3];
    rot[0][0] = (1.0-s)*rwgt + s;
    rot[0][1] = (1.0-s)*rwgt;
    rot[0][2] = (1.0-s)*rwgt;
    rot[1][0] = (1.0-s)*gwgt;
    rot[1][1] = (1.0-s)*gwgt + s;
    rot[1][2] = (1.0-s)*gwgt;
    rot[2][0] = (1.0-s)*bwgt;
    rot[2][1] = (1.0-s)*bwgt;
    rot[2][2] = (1.0-s)*bwgt + s;
    matrixMult(rot, mat, mat);
}

void DHMatrix::brightnessMatrix(float b) {
    if (b == 1.f) {
        return;
    }
    
    float rot[3][3];
    rot[0][0] = b;
    rot[0][1] = 0.0;
    rot[0][2] = 0.0;
    
    rot[1][0] = 0.0;
    rot[1][1] = b;
    rot[1][2] = 0.0;
    
    rot[2][0] = 0.0;
    rot[2][1] = 0.0;
    rot[2][2] = b;
    
    matrixMult(rot, mat, mat);
}

void DHMatrix::premultiplyAlpha(float alpha) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat[i][j] *= alpha;
        }
    }
}


namespace DHMatrixHelper {

//function
void xRotateMat(float mat[3][3], float rs, float rc)
{
    mat[0][0] = 1.0;
    mat[0][1] = 0.0;
    mat[0][2] = 0.0;
    
    mat[1][0] = 0.0;
    mat[1][1] = rc;
    mat[1][2] = rs;
    
    mat[2][0] = 0.0;
    mat[2][1] = -rs;
    mat[2][2] = rc;
}

void yRotateMat(float mat[3][3], float rs, float rc)
{
    mat[0][0] = rc;
    mat[0][1] = 0.0;
    mat[0][2] = -rs;
    
    mat[1][0] = 0.0;
    mat[1][1] = 1.0;
    mat[1][2] = 0.0;
    
    mat[2][0] = rs;
    mat[2][1] = 0.0;
    mat[2][2] = rc;
}


void zRotateMat(float mat[3][3], float rs, float rc)
{
    mat[0][0] = rc;
    mat[0][1] = rs;
    mat[0][2] = 0.0;
    
    mat[1][0] = -rs;
    mat[1][1] = rc;
    mat[1][2] = 0.0;
    
    mat[2][0] = 0.0;
    mat[2][1] = 0.0;
    mat[2][2] = 1.0;
}

void matrixMult(float a[3][3], float b[3][3], float c[3][3])
{
    int x, y;
    float temp[3][3];
    
    for(y=0; y<3; y++) {
        for(x=0; x<3; x++) {
            temp[y][x] = b[y][0] * a[0][x] + b[y][1] * a[1][x] + b[y][2] * a[2][x];
        }
    }
    for(y=0; y<3; y++) {
        for(x=0; x<3; x++) {
            c[y][x] = temp[y][x];
        }
    }
}
    
}

NS_CC_END