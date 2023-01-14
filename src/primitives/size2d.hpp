#pragma once

struct Size2D {
    int width, height;
    Size2D() : width(0), height(0) {}
    Size2D(int width, int height) : width(width), height(height) {}
    Size2D operator+(const Size2D& s) const { return Size2D(width + s.width, height + s.height); }
    Size2D operator-(const Size2D& s) const { return Size2D(width - s.width, height - s.height); }
    Size2D operator*(int s) const { return Size2D(width * s, height * s); }
    Size2D operator/(int s) const { return Size2D(width / s, height / s); }
    int area() const { return width * height; }
};

