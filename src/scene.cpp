#include <scene.hpp>

image scene::draw()
{
    image img;

    std::vector<ray_info> rays = this->cam.get_rays();

    for (ray_info &ri : rays)
    {
        vec3 col = this->trace(ri.r);
        img.fill(ri.x, ri.y, col);
    }

    return img;
}

vec3 scene::trace(ray &r)
{
    vec3 col = vec3(0.0, 0.0, 0.0);

    for (object &obj : this->objects)
    {
        intersection i = obj.intersect(r);

        if (i.intersects)
        {
            col = vec3(1.0, 1.0, 1.0);
            break;
        }
    }

    return col;
}