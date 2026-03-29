#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <string>
#include <vector>

#include <vec3.hpp>
#include <ray.hpp>

typedef struct ray_info_
{
    ray r;
    int x, y;
} ray_info;

class camera
{
public:
    camera() {}
    camera(int width, int height, vec3 pos, vec3 dir) : width(width), height(height), position(pos), direction(dir) {}

    std::vector<ray_info> get_rays();

private:
    vec3 position;
    vec3 direction;

    int width,
        height;
};

#endif