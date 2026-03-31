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
    std::vector<primitive> geometry = std::vector<primitive>(10);
    aa_bounds bounds = aa_bounds();

    vec3 position = vec3();
    // double radius = 1.0; // temp! all objects will be simple spheres for now

    void update_bounds();
};

#endif