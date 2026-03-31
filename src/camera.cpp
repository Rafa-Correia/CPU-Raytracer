#include <camera.hpp>

std::vector<ray_info> camera::get_rays()
{
    std::vector<ray_info> ret;

    vec3 middle = this->position + this->direction;
    vec3 right = vec3::normalize(vec3::cross(this->direction, this->up));
    vec3 up = vec3::normalize(vec3::cross(right, this->direction));

    vec3 origin = this->position;

    double ratio = this->width / this->height;

    double fov_rad_horiz = this->fov * (M_PI / 180.0);
    double fov_rad_vert = fov_rad_horiz * ratio;

    // so, for something 1 unit away, the side to make fov degrees is...
    // assume half the fov to make it a right triangle
    // so sin(half_fov)

    double sin_i = std::sin(fov_rad_vert / 2.0), sin_j = std::sin(fov_rad_horiz / 2.0);
    double cos_i = std::cos(fov_rad_vert / 2.0), cos_j = std::cos(fov_rad_horiz / 2.0);

    double size_i = sin_i * 1.0 / cos_i, size_j = sin_j * 1.0 / cos_j;

    double delta_i = size_i / this->height, delta_j = size_j / this->width;

    double curr_off_i = -(size_i / 2.0), curr_off_j = -(size_j / 2.0);

    int i, j;
    for (i = 0; i < this->height; i++)
    {
        curr_off_j = -(size_j / 2.0);
        for (j = 0; j < this->width; j++)
        {

            // angle for top right is ?
            //
            // imagine a grid, a little bit in front of the camera
            // the aspect ratio of this grid is the same as the camera
            // the distance of this grid from the camera is determined by the fov

            // uhhhhhhhhhhhhhhhhh
            // actually, lets say that the grid is a fixed distance away.
            // it's size must be figured out from the fov
            vec3 point = middle + right * curr_off_j + up * curr_off_i;

            vec3 dir = point - origin;
            dir = vec3::normalize(dir);

            ray r(origin, dir);

            ray_info info{r, j, i};
            // info.r = r;

            ret.push_back(info);

            curr_off_j += delta_j;
        }
        curr_off_i += delta_i;
    }

    return ret;
}