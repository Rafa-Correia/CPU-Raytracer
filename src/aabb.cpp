#include <aabb.hpp>

/* bool aa_bounds::intersect(ray &r)
{
    // static size_t ctr = 0;
    // hard maths :(
    // need to define the 3 planes that the ray will intersect.
    // since it's a quad prism, (almost cube), it will always intersect 2 planes (except at edges), so just
    // taking the front one will be enough

    // printf("Attempting intersection:\tbounds[%f, %f, %f ~ %f, %f, %f]\n", lower_bounds.x, lower_bounds.y, lower_bounds.z, upper_bounds.x, upper_bounds.y, upper_bounds.z);

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
    // point = pos0 + c * dir
    // we need to solve for c!!!!!
    // pos0 dot p + dir dot p * c = 0
    // c = - pos . p / dir . p
    // calculate point and check bounds!

    vec4 orig4 = vec4(r.origin, 1);
    vec4 dir4 = vec4(r.direction, 0);

    double c1 = -vec4::dot(orig4, p1) / vec4::dot(dir4, p1);
    double c2 = -vec4::dot(orig4, p2) / vec4::dot(dir4, p2);
    double c3 = -vec4::dot(orig4, p3) / vec4::dot(dir4, p3);

    vec3 i1 = r.origin + (r.direction * c1);
    vec3 i2 = r.origin + (r.direction * c2);
    vec3 i3 = r.origin + (r.direction * c3);

    // ctr++;

    // if (ctr % 100 == 0)
    //     std::cout << ctr << std::endl;

    if (i1.y >= this->lower_bounds.y && i1.y <= this->upper_bounds.y && i1.z >= this->lower_bounds.z && i1.z <= this->upper_bounds.z)
        return true;
    if (i2.y >= this->lower_bounds.y && i2.y <= this->upper_bounds.y && i2.z >= this->lower_bounds.z && i2.z <= this->upper_bounds.z)
        return true;
    if (i3.y >= this->lower_bounds.y && i3.y <= this->upper_bounds.y && i3.z >= this->lower_bounds.z && i3.z <= this->upper_bounds.z)
        return true;

    return false;
} */

bool aa_bounds::intersect(ray &r)
{
    static const double epsilon = 1e-23;
    static size_t ctr = 0;
    static size_t row = 0;

    vec3 t_low, t_high; // x y and z intersections
    vec3 t_close_a, t_far_a;

    double t_close, t_far;

    t_low = this->lower_bounds - r.origin;
    t_low.x /= r.direction.x + epsilon;
    t_low.y /= r.direction.y + epsilon;
    t_low.z /= r.direction.z + epsilon;

    t_high = this->upper_bounds - r.origin;
    t_high.x /= r.direction.x + epsilon;
    t_high.y /= r.direction.y + epsilon;
    t_high.z /= r.direction.z + epsilon;

    t_close_a.x = std::min(t_low.x, t_high.x);
    t_close_a.y = std::min(t_low.y, t_high.y);
    t_close_a.z = std::min(t_low.z, t_high.z);

    t_far_a.x = std::max(t_low.x, t_high.x);
    t_far_a.y = std::max(t_low.y, t_high.y);
    t_far_a.z = std::max(t_low.z, t_high.z);

    t_close = std::max(t_close_a.x, t_close_a.y);
    t_close = std::max(t_close, t_close_a.z);

    t_far = std::max(t_far_a.x, t_far_a.y);
    t_far = std::max(t_far, t_far_a.z);

    ctr++;

    if (ctr % 1920 == 0)
    {
        std::cout << "Ray no. " << ctr << " [" << row << "]: o[" << r.origin.x << ", " << r.origin.y << ", " << r.origin.z << "]";
        std::cout << " ~ d[" << r.direction.x << ", " << r.direction.y << ", " << r.direction.z << "]";
        std::cout << "\n\n";

        std::cout << "t_close: " << t_close;
        std::cout << "\nt_far: " << t_far;
        std::cout << "\n\n";

        vec3 closest_intersection = r.origin + r.direction * t_close;
        vec3 farthest_intersection = r.origin + r.direction * t_far;

        std::cout << "Closest intersection: [" << closest_intersection.x << ", " << closest_intersection.y << ", " << closest_intersection.z << "]";
        std::cout << "\nFarthest intersection: [" << farthest_intersection.x << ", " << farthest_intersection.y << ", " << farthest_intersection.z << "]";
        std::cout << "\n\n";

        std::cout << "Bounds: l[" << this->lower_bounds.x << ", " << this->lower_bounds.y << ", " << this->lower_bounds.z << "]";
        std::cout << " ~ u[" << this->upper_bounds.x << ", " << this->upper_bounds.y << ", " << this->upper_bounds.z << "]";

        std::cout << "\n===============================================================";

        std::cout << std::endl;

        row++;
    }

    if (t_close > t_far)
        return false;

    if (t_close < 0.0)
        return false;

    return true;
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