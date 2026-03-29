#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
#include <primitive.hpp>
#include <vec3.hpp>
#include <aabb.hpp>
#include <intersection.hpp>

class object
{
public:
    object() {}

    void add_primitive(primitive &prim);

    intersection intersect(ray &r);

private:
    std::vector<primitive> geometry;
    aa_bounds bounds;

    vec3 position;
    // double radius = 1.0; // temp! all objects will be simple spheres for now

    void update_bounds();
};

#endif