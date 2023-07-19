#pragma once



/* vector 2 float edition */
struct Vec2F
{
    // the 2 points
    float x, y;

    // constructer with values
    Vec2F(float p_x, float p_y)
    : x(p_x), y(p_y)
    {}
    // constructer without values
    Vec2F()
    : x(0), y(0)
    {}
};

/* vector 2 int edition */
struct Vec2I
{
    // the 2 ints
    int x, y;

    // constructer with values
    Vec2I(int p_x, int p_y)
    : x(p_x), y(p_y)
    {}
    // constructer without values
    Vec2I()
    : x(0), y(0)
    {}
};