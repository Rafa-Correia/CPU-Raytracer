#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>

#include <primitive.hpp>

class scene
{
public:
    scene() {}

private:
    std::vector<primitive> primitives;
};

#endif