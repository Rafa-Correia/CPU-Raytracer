#include <image.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

void image::fill(int x, int y, rgb col)
{
    // x is horiz
    // y is vert

    size_t coord = y * this->width + x;
    this->color_data.insert(this->color_data.begin() + coord, col);
}

void image::to_png(const char *path)
{
    size_t row_count = this->width;
    size_t elem_size = 3;
    size_t row_size = row_count * elem_size;

    unsigned char *data = (unsigned char *)malloc(elem_size * this->width * this->height);

    int ctr = 0;
    for (rgb &elem : this->color_data)
    {
        data[ctr] = elem.r;
        data[ctr + 1] = elem.g;
        data[ctr + 2] = elem.b;

        ctr += 3;
    }

    int result = stbi_write_png(path, this->width, this->height, 3, (void *)data, row_size);

    if (result == 0)
        std::cout << "Failed to write image." << std::endl;
}