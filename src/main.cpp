#include <iostream>
#include <string>
#include <vector>

#include <camera.hpp>
#include <object.hpp>
#include <primitive.hpp>
#include <scene.hpp>
#include <image.hpp>

int main(int argc, char *argv[])
{
    // flow:
    //  create camera and objects
    //  create scene
    //  get array of rays from camera
    //  trace each ray through the scene
    //  cool

    // lets have a simple scene with a single triangle and paint it white if hits and black otherwise
    // still need to keep info on an image somehow?

    vec3 cam_pos = vec3(0.0, 0.0, 3.0);
    vec3 cam_dir = vec3(0.0, 0.0, -1.0);
    int width = 1920;
    int height = 1080;

    double fov = 60.0;

    camera cam = camera(width, height, fov, cam_pos, cam_dir);
    scene sc = scene();
    sc.set_camera(cam);

    object obj = object();

    vec3 v1 = vec3(-1.0, 0.0, 0.0);
    vec3 v2 = vec3(0.0, 1.0, 0.0);
    vec3 v3 = vec3(1.0, 0.0, 0.0);
    triangle tri = triangle(v1, v2, v3);
    primitive prim = primitive(tri, NULL);

    obj.add_primitive(prim);
    // obj.update_bounds();

    sc.add_object(obj);

    image img = sc.draw();
    img.to_png("./bin/img.png");
}