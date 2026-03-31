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
    int width,
        height;

    camera() {}
    camera(int width, int height, double fov, vec3 pos, vec3 dir) : width(width), height(height), fov(fov), position(pos), direction(vec3::normalize(dir)) {}

    std::vector<ray_info> get_rays();

private:
    double fov; // horizontal fov

    vec3 position;
    vec3 direction;

    vec3 up = vec3(0.0, 1.0, 0.0);
};

#endif