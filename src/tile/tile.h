#pragma once

#include "ofMain.h"

using namespace glm;

const int TILE_SIZE = 8;
enum tileDecor : unsigned char
{
    Checkerboard, Gradient, Noise, HarshNoise
};

class Tile {
    public:
        void setup();
        void draw(vec3 coords);

        ofBoxPrimitive mesh;
};