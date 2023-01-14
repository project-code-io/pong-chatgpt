#pragma once

#include <math.h>

struct Vector2D {
    double x, y;
    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& v) const { return Vector2D(x + v.x, y + v.y); }
    Vector2D operator-(const Vector2D& v) const { return Vector2D(x - v.x, y - v.y); }
    Vector2D operator*(double s) const { return Vector2D(x * s, y * s); }
    Vector2D operator/(double s) const { return Vector2D(x / s, y / s); }
    double dot(const Vector2D& v) const { return x * v.x + y * v.y; }
    double length() const { return sqrt(x * x + y * y); }
    Vector2D normalize() const { return *this / length(); }
};

