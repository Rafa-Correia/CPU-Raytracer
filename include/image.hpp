#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <string>
#include <vector>

#include <vec3.hpp>

class image
{
public:
    image();

    void fill(int x, int y, vec3 col);

    void to_png(const char *path);

private:
    std::vector<vec3> color_data;
    int width,
        height;
};

#endif