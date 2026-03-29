#include <object.hpp>

void object::add_primitive(primitive &prim)
{
    this->geometry.push_back(prim);
    this->bounds.inflate(prim);
}

intersection object::intersect(ray &r)
{
    // intersection i;

    bool hit = this->bounds.intersect(r);

    // for now well return yes if hits bounds and no otherwise

    vec3 pos, norm;
    return intersection(pos, norm, NULL, hit);
}