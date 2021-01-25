//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Linear algebra classes.
//
//=============================================================================

#pragma once

#include <initializer_list>

// Base Vector for purposes of template specialization.
template<class T, int I>
class VecBase {
public:
    VecBase() : elements{} {}

    template<typename... Args>
    VecBase(Args... args) : elements{static_cast<T>(args)...} {}

protected:
    T elements[I] {};
};

// Primary Vector template
template<class T, int I>
class Vec : public VecBase<T, I> {
public:
    template<typename... Args>
    Vec(Args... args) : VecBase<T, I>{args...}{}

};

// Vector template specialization
template<class T>
class Vec<T,3> : public VecBase<T, 3> {
public:
    T& x = this->elements[0];
    T& y = this->elements[1];
    T& z = this->elements[2];

    template<typename... Args>
    Vec(Args... args) : VecBase<T, 3>{args...}{}
};


template<class T>
class Vec<T,4> : public VecBase<T, 4> {
public:
    T& x = this->elements[0];
    T& y = this->elements[1];
    T& z = this->elements[2];
    T& w = this->elements[3];

    template<typename... Args>
    Vec(Args... args) : VecBase<T, 4>{args...}{}
};


// Alias
typedef Vec<float, 3> Vec3;
typedef Vec<float, 4> Vec4;
