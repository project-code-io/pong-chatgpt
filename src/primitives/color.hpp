#pragma once

#include <algorithm>

struct ColorRGBA {
  static const ColorRGBA Red;
  static const ColorRGBA Blue;
  static const ColorRGBA White;
  static const ColorRGBA Black;

  float r, g, b, a;
  ColorRGBA() : r(0), g(0), b(0), a(1) {}
  ColorRGBA(float r, float g, float b, float a = 1) : r(r), g(g), b(b), a(a) {}
  ColorRGBA operator+(const ColorRGBA& c) const { return ColorRGBA(r + c.r, g + c.g, b + c.b, a + c.a); }
  ColorRGBA operator-(const ColorRGBA& c) const { return ColorRGBA(r - c.r, g - c.g, b - c.b, a - c.a); }
  ColorRGBA operator*(float s) const { return ColorRGBA(r * s, g * s, b * s, a * s); }
  ColorRGBA operator/(float s) const { return ColorRGBA(r / s, g / s, b / s, a / s); }

  void clamp() {
    r = std::max(0.0f, std::min(r, 1.0f));
    g = std::max(0.0f, std::min(g, 1.0f));
    b = std::max(0.0f, std::min(b, 1.0f));
    a = std::max(0.0f, std::min(a, 1.0f));
  }
};

