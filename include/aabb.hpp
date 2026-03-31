#ifndef AABB_HPP
#define AABB_HPP

#include <iostream>
#include <string>
#include <vector>

#include <vec3.hpp>
#include <vec4.hpp>
#include <primitive.hpp>
#include <ray.hpp>

class aa_bounds
{
public:
    aa_bounds() {}
    // aa_bounds(std::vector<primitive> &geometry);

    bool intersect(ray &r);

    // deprecated
    void inflate(primitive &prim);

    void update_bounds();

private:
    vec3 position;

    vec3 lower_bounds;
    vec3 upper_bounds;
};

#endif