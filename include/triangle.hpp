#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <vec3.hpp>

class triangle
{
public:
    vec3 v1, v2, v3;

    triangle() : v1(vec3()), v2(vec3()), v3(vec3()) {}
    triangle(vec3 &v1, vec3 &v2, vec3 &v3) : v1(v1), v2(v2), v3(v3) {}

private:
};

#endif