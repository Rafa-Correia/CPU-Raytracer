#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <string>
#include <vector>

#include <rgb.hpp>

class image
{
public:
    image() = delete;
    image(int width, int height) : width(width), height(height) { color_data.reserve(width * height); }

    void fill(int x, int y, rgb col);

    void to_png(const char *path);

private:
    std::vector<rgb> color_data;
    int width,
        height;
};

#endif