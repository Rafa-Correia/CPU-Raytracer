#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <iostream>
#include <triangle.hpp>
#include <material.hpp>
#include <intersection.hpp>
#include <ray.hpp>

class primitive
{
public:
    triangle tri;
    material *mat; // material may be shared by many triangles!
                   // no need to have that much redundant memory
    primitive() {}
    primitive(triangle tri, material *mat) : tri(tri), mat(mat) {}
    primitive(primitive &other)
    {
        this->tri = triangle(other.tri);
        this->mat = new material(other.mat);
    }

    intersection intersect(ray r);

private:
};

#endif