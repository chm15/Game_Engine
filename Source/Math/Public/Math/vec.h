//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Linear algebra classes.
//
//=============================================================================

#pragma once


template<int I>
class Vec {
public:
    Vec();

private:
    int elements[I];

};

template<>
class Vec<3> {
public:
    int& x = this->elements[0];
    int& y = this->elements[1];
    int& z = this->elements[2];
};




typedef Vec<3> Vec3;
