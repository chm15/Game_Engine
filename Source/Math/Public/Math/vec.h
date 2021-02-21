//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Linear algebra classes.
//
//=============================================================================

#pragma once



// Vec3 MUST have the same memory footprint as a POD struct
// comprised of three floats (four bytes each).
class Vec3 {
public:
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vec3(float val) : x(val), y(val), z(val) {}

    float operator[](int val) {
        float data[3] = {x,y,z};
        return data[val];
    }

    Vec3 operator+(const Vec3 &other) {
        return Vec3(x+other.x, y+other.y, z+other.z);
    }

    Vec3 operator-(const Vec3 &other) {
        return Vec3(x-other.x, y-other.y, z-other.z);
    }

    float operator*(const Vec3 &other) {
        return x*other.x + y*other.y + z*other.z;
    }

    Vec3 operator*(const float &a) {
        return Vec3(x*a + y*a + z*a);
    }


public:
    float x, y, z;
};


class Vec4 {
public:
    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
    Vec4(float val) : x(val), y(val), z(val), w(val) {}

    float operator[](int val) {
        float data[4] = {x,y,z,w};
        return data[val];
    }

    Vec4 operator+(const Vec4 &other) {
        return Vec4(x+other.x, y+other.y, z+other.z, w*other.w);
    }

    Vec4 operator-(const Vec4 &other) {
        return Vec4(x-other.x, y-other.y, z-other.z, w-other.w);
    }

    float operator*(const Vec4 &other) {
        return x*other.x + y*other.y + z*other.z + w*other.w;
    }

    Vec4 operator*(const float &a) {
        return Vec4(x*a + y*a + z*a + w*a);
    }

    //friend Quat operator*( float a, const Quat& vo) {
    //    return Quat(a * vo.w, a * vo.v.x, a * vo.v.y, a * vo.v.z);
    //}


public:
    float x, y, z, w;
};


class Mat4 {
public:
    Mat4() {
        this->set(0.0);
    }

    Mat4(float val) { 
        this->set(val);
    }


    Mat4(   float x1, float x2, float x3, float x4,
            float y1, float y2, float y3, float y4,
            float z1, float z2, float z3, float z4,
            float w1, float w2, float w3, float w4
        ) : data{ Vec4(x1,y1,z1,w1), Vec4(x2,y2,z2,w2), Vec4(x3,y3,z3,w3), Vec4(x4,y4,z4,w4)}  {}


    void set(float val) {
        // Set everything to one vale.
        for (int i=0;i<4;i++) {
            this->data[i] = Vec4(val);
        }
    }

    Vec4 rowVec(int index) {
        return Vec4(data[0][index], data[1][index], data[2][index], data[3][index]);
    }

    Vec4 operator*(const Vec4 &other) {
        Vec4 temp;
        return Vec4(this->rowVec(0) * other, this->rowVec(1) * other, this->rowVec(2) * other, this->rowVec(3) * other);
    }

private:
    Vec4 data[4];
};




class ScaleMatrix : public Mat4 {
public:
    ScaleMatrix(float _x, float _y, float _z) : Mat4(_x,0,0,0,  0,_y,0,0,  0,0,_z,0,  0,0,0,1) {}
    ScaleMatrix(float val) : Mat4(val,0,0,0,  0,val,0,0,  0,0,val,0,  0,0,0,1) {}
};

class RotationMatrix : public Mat4 {
public:
    
};
