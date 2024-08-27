#ifndef SIZE_HPP
#define SIZE_HPP

struct Size {
    int width, height;
    Size(int width, int height): width(width), height(height) {}
    Size(): width(0), height(0) {}
};

struct Sizef {
    float width, height;
    Sizef(float width, float height): width(width), height(height) {}
    Sizef(): width(0), height(0) {}
};

#endif