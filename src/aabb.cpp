#include <aabb.hpp>

bool aa_bounds::intersect(ray &r)
{
    // hard maths :(
    // need to define the 3 planes that the ray will intersect.
    // since it's a quad prism, (almost cube), it will always intersect 2 planes (except at edges), so just
    // taking the front one will be enough

    vec4 p1, p2, p3;
    vec3 norm_x(1.0, 0.0, 0.0), norm_y(0.0, 1.0, 0.0), norm_z(0.0, 0.0, 1.0);

    if (r.direction.x > 0)
        p1 = vec4(norm_x * -1, -1 * lower_bounds.x);
    else
        p1 = vec4(norm_x, -1 * upper_bounds.x);

    if (r.direction.y > 0)
        p2 = vec4(norm_y * -1, -1 * lower_bounds.y);
    else
        p2 = vec4(norm_y, -1 * upper_bounds.y);

    if (r.direction.z > 0)
        p3 = vec4(norm_z * -1, -1 * lower_bounds.z);
    else
        p3 = vec4(norm_z, -1 * upper_bounds.z);

    // now what?
    // if any point (vec3) p intersects the plane, it's because
    // vec4(p, 1.0) dot (vec4) plane == 0
    // so we solve for p and then what?
    // how?

    // x * px + y * py + z * pz + 1 * pd = 0. uh
}

void aa_bounds::inflate(primitive &prim)
{
    // simple checks :)

    // v1
    if (prim.tri.v1.x < this->lower_bounds.x)
        this->lower_bounds.x = prim.tri.v1.x;
    if (prim.tri.v1.y < this->lower_bounds.y)
        this->lower_bounds.y = prim.tri.v1.y;
    if (prim.tri.v1.z < this->lower_bounds.z)
        this->lower_bounds.z = prim.tri.v1.z;

    if (prim.tri.v1.x > this->upper_bounds.x)
        this->upper_bounds.x = prim.tri.v1.x;
    if (prim.tri.v1.y > this->upper_bounds.y)
        this->upper_bounds.y = prim.tri.v1.y;
    if (prim.tri.v1.z > this->upper_bounds.z)
        this->upper_bounds.z = prim.tri.v1.z;

    // v2
    if (prim.tri.v2.x < this->lower_bounds.x)
        this->lower_bounds.x = prim.tri.v2.x;
    if (prim.tri.v2.y < this->lower_bounds.y)
        this->lower_bounds.y = prim.tri.v2.y;
    if (prim.tri.v2.z < this->lower_bounds.z)
        this->lower_bounds.z = prim.tri.v2.z;

    if (prim.tri.v2.x > this->upper_bounds.x)
        this->upper_bounds.x = prim.tri.v2.x;
    if (prim.tri.v2.y > this->upper_bounds.y)
        this->upper_bounds.y = prim.tri.v2.y;
    if (prim.tri.v2.z > this->upper_bounds.z)
        this->upper_bounds.z = prim.tri.v2.z;

    // v3
    if (prim.tri.v3.x < this->lower_bounds.x)
        this->lower_bounds.x = prim.tri.v3.x;
    if (prim.tri.v3.y < this->lower_bounds.y)
        this->lower_bounds.y = prim.tri.v3.y;
    if (prim.tri.v3.z < this->lower_bounds.z)
        this->lower_bounds.z = prim.tri.v3.z;

    if (prim.tri.v3.x > this->upper_bounds.x)
        this->upper_bounds.x = prim.tri.v3.x;
    if (prim.tri.v3.y > this->upper_bounds.y)
        this->upper_bounds.y = prim.tri.v3.y;
    if (prim.tri.v3.z > this->upper_bounds.z)
        this->upper_bounds.z = prim.tri.v3.z;
}