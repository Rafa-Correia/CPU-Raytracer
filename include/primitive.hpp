#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <iostream>
#include <triangle.hpp>
#include <material.hpp>

class primitive
{
public:
    primitive() {}

private:
    triangle tri;
    material mat;
};

#endif