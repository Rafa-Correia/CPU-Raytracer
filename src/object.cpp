#include <object.hpp>

void object::add_primitive(primitive &prim)
{
    this->geometry.push_back(prim);
    this->bounds.inflate(prim);
}

void object::update_bounds()
{
    // if (this->geometry.empty())
    //     return;
    //
    // vec
    //
    // for (primitive &prim : this->geometry)
    // {
    //
    // }
}

intersection object::intersect(ray &r)
{
    // intersection i;

    bool hit = this->bounds.intersect(r);

    // for now well return yes if hits bounds and no otherwise

    vec3 pos, norm;
    return intersection(pos, norm, NULL, hit);
}