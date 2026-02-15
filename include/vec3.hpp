#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include <cmath>

class vec3
{
public:
    double x, y, z;

    vec3() {}
    vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    inline double magnitude() const { return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z); }

    void normalize()
    {
        double mag = this->magnitude();
        this->x /= mag;
        this->y /= mag;
        this->z /= mag;
    }

    static vec3 normalize(const vec3 &vec) { return vec / vec.magnitude(); }

    static double dot(vec3 &v1, vec3 &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

    static vec3 cross(vec3 &v1, vec3 &v2)
    {
        return vec3(v1.y * v2.z - v1.z * v2.y,
                    v1.z * v2.x - v1.x * v2.z,
                    v1.x * v2.y - v1.y * v2.x);
    }

    /**
     * operators!
     */
    vec3 operator+(const vec3 &other) const { return vec3(this->x + other.x, this->y + other.y, this->z + other.z); }
    vec3 operator+(const double &scalar) const { return vec3(this->x + scalar, this->y + scalar, this->z + scalar); }
    vec3 operator-(const vec3 &other) const { return vec3(this->x - other.x, this->y - other.y, this->z - other.z); }
    vec3 operator-(const double &scalar) const { return vec3(this->x - scalar, this->y - scalar, this->z - scalar); }

    vec3 operator*(const double &scalar) const { return vec3(this->x * scalar, this->y * scalar, this->z * scalar); }
    vec3 operator/(const double &scalar) const { return vec3(this->x / scalar, this->y / scalar, this->z / scalar); }

    vec3 &operator+=(const vec3 &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }
    vec3 &operator+=(const double &scalar)
    {
        this->x += scalar;
        this->y += scalar;
        this->z += scalar;

        return *this;
    }
    vec3 &operator-=(const vec3 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }
    vec3 &operator-=(const double &scalar)
    {
        this->x -= scalar;
        this->y -= scalar;
        this->z -= scalar;

        return *this;
    }

    vec3 &operator*=(const double &scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }
    vec3 &operator/=(const double &scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;

        return *this;
    }

private:
};

#endif