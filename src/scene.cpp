#include <scene.hpp>

image scene::draw()
{
    image img(this->cam.width, this->cam.height);

    std::vector<ray_info> rays = this->cam.get_rays();

    for (ray_info &ri : rays)
    {
        rgb col = this->trace(ri.r);
        img.fill(ri.x, ri.y, col);
    }

    return img;
}

rgb scene::trace(ray &r)
{
    rgb col = rgb(0, 0, 0);

    for (object &obj : this->objects)
    {
        intersection i = obj.intersect(r);

        if (i.intersects)
        {
            col = rgb(255, 255, 255);
            break;
        }
    }

    return col;
}