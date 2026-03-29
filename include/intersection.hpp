#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

#include <iostream>
#include <string>
#include <vector>

#include <vec3.hpp>
#include <material.hpp>

// honestly, this is most likely exagerated.
// simply having a struct would most likely be enough

class intersection
{
public:
    vec3 position,
        normal;
    material *mat;
    bool intersects;

    intersection(vec3 &pos, vec3 &normal, material *mat, bool &intersects) : position(pos), normal(normal), mat(mat), intersects(intersects) {};

private:
};

#endif