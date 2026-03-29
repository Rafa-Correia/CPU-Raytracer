#ifndef VEC4_HPP
#define VEC4_HPP

#include <iostream>
#include <cmath>
#include <vec4.hpp>

class vec4
{
public:
    double x = 0.0, y = 0.0, z = 0.0, w = 0.0;

    vec4() {}
    vec4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
    vec4(vec3 v, double w = 0) : x(v.x), y(v.y), z(v.z), w(w) {}

    inline double
    magnitude() const
    {
        return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    // void normalize()
    // {
    //     double mag = this->magnitude();
    //     this->x /= mag;
    //     this->y /= mag;
    //     this->z /= mag;
    // }

    // static vec3 normalize(const vec3 &vec) { return vec / vec.magnitude(); }

    static double dot(vec4 &v1, vec4 &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }

    // static vec3 cross(vec3 &v1, vec3 &v2)
    // {
    //     return vec3(v1.y * v2.z - v1.z * v2.y,
    //                 v1.z * v2.x - v1.x * v2.z,
    //                 v1.x * v2.y - v1.y * v2.x);
    // }

    /**
     * operators!
     */
    vec4 operator+(const vec4 &other) const { return vec4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w); }
    vec4 operator+(const double &scalar) const { return vec4(this->x + scalar, this->y + scalar, this->z + scalar, this->w + scalar); }
    vec4 operator-(const vec4 &other) const { return vec4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w); }
    vec4 operator-(const double &scalar) const { return vec4(this->x - scalar, this->y - scalar, this->z - scalar, this->w - scalar); }

    vec4 operator*(const double &scalar) const { return vec4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar); }
    vec4 operator/(const double &scalar) const { return vec4(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar); }

    vec4 &operator+=(const vec4 &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;

        return *this;
    }
    vec4 &operator+=(const double &scalar)
    {
        this->x += scalar;
        this->y += scalar;
        this->z += scalar;
        this->w += scalar;

        return *this;
    }
    vec4 &operator-=(const vec4 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;

        return *this;
    }
    vec4 &operator-=(const double &scalar)
    {
        this->x -= scalar;
        this->y -= scalar;
        this->z -= scalar;
        this->w -= scalar;

        return *this;
    }

    vec4 &operator*=(const double &scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;

        return *this;
    }
    vec4 &operator/=(const double &scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;

        return *this;
    }

private:
};

#endif