//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Linear algebra classes.
//
//=============================================================================

#pragma once

/* Quaternion class */
class Quat {
public:
    Quat() : w(1), x(0), y(0), z(0) {}
    Quat(float _w, float _x, float _y, float _z) : w(_w), x(_x), y(_y), z(_z) {}
    Quat(float _w, const Vec3 &v) : w(_w), x(v.x), y(v.y), z(v.z) {}

    Quat operator*(Quat &q) {
        tQ = Quat();
        tQ.w = w*q.w - x*q.x - y*q.y - z*q.z;
        tQ.x = w*q.x + x*q.w + y*q.z - z*q.y;
        tQ.y = w*q.y + x*q.y - y*q.x + z*q.w;
        tQ.z = w*q.z + x*q.y - y*q.x + z*q.w;
        return tQ;
    }

    float w, x, y, z;
};
