//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Linear algebra classes.
//
//  Notes:
//      - [https://www.cprogramming.com/tutorial/3d/quaternions.html]
//
//=============================================================================

#pragma once

#include <cmath>
#include "vec.h"

/* Quaternion class */
class Quat {
public:
    Quat() : w(1.0f), v(0.0f) {}
    Quat(float _w, float _x, float _y, float _z) : w(_w), v(_x,_y,_z) {}
    Quat(float _w, const Vec3 &_v) : w(_w), v(_v) {}

    Quat(const Quat& other) :
        w(other.w),
        v(other.v)
    { }

    Quat& operator=(const Quat& other) {
        if (this == &other) return *this;

        w = other.w;
        v = other.v;

        return *this;
    }

    inline void set(float _w, float _x, float _y, float _z) {
        this->w = _w;
        this->v = Vec3(_x,_y,_z);
        return;
    }

    inline void set(float _w, const Vec3 &_v) {
        this->w = _w;
        this->v = _v;
        return;
    }

    inline void zero() {
        this->w = 0.0f;
        this->v = Vec3(0.0f);
        return;
    }

    inline void identity() {
        this->w = 1.0f;
        this->v = Vec3(0.0f);
        return;
    }

    inline float length() {
        return sqrt(w*w + v*v);
    }

    Quat normalize() {
        float length = this->length();
        this->w /= length;
        this->v = this->v * (1/length);
        return *this;
    }

    Mat4 getMatrix() {
        const float &x = this->v.x;
        const float &y = this->v.y;
        const float &z = this->v.z;

        Mat4 rMatrix = Mat4(
                (w*w + x*x - y*y - z*z),  (2*x*y - 2*w*z),  (2*x*z + 2*w*y),  0,
                (2*x*y + 2*w*z),  (w*w - x*x + y*y - z*z),  (2*y*z + 2*w*x),  0,
                (2*x*z - 2*w*y),  (2*y*z - 2*w*x),  (w*w - x*x - y*y + z*z),  0,
                0,  0,  0,  1
                );
        return rMatrix;
    }


    Quat operator*(Quat &q) {
        Quat tQ = Quat();
        const float &wo = q.w;
        const Vec3 &vo = q.v;
        float tW = w*wo - v.x*vo.x - v.y*vo.y - v.z*vo.z;
        float tX = w*vo.x + v.x*wo + v.y*vo.z - v.z*vo.y;
        float tY = w*vo.y + v.x*vo.y - v.y*vo.x + v.z*wo;
        float tZ = w*vo.z + v.x*vo.y - v.y*vo.x + v.z*wo;

        tQ.w = tW;
        tQ.v = Vec3(tX,tY,tZ);
        return tQ;
    }

    friend Quat operator*( float a, const Quat& vo) {
        return Quat(a * vo.w, a * vo.v.x, a * vo.v.y, a * vo.v.z);
    }

    float w;
    Vec3 v;
};
