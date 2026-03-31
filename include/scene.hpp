#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>

#include <object.hpp>
#include <camera.hpp>
#include <image.hpp>

class scene
{
public:
    scene() {}

    void add_object(object obj) { this->objects.push_back(obj); }
    void set_camera(camera cam) { this->cam = cam; };

    image draw();

private:
    std::vector<object>
        objects;
    camera cam;

    rgb trace(ray &r);
};

#endif