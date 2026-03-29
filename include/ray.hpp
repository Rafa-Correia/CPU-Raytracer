#ifndef RAY_HPP
#define RAY_HPP

#include <iostream>
#include <string>
#include <vector>

#include <vec3.hpp>
#include <intersection.hpp>

class ray
{
public:
    vec3 origin,
        direction;

    ray(vec3 origin, vec3 direction) : origin(origin), direction(direction) {};
    ray reflect(intersection inter);

private:
};

#endif