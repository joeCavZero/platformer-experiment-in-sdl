#ifndef VECTOR2_HPP
#define VECTOR2_HPP

struct Vector2 {
    int x, y;
    Vector2(int x, int y): x(x), y(y) {}
    Vector2(): x(0), y(0) {}
};

struct Vector2f {
    float x, y;
    Vector2f(float x, float y): x(x), y(y) {}
    Vector2f(): x(0), y(0) {}
};

#endif