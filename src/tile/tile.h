#pragma once

#include "ofMain.h"

using namespace glm;

const int TILE_SIZE = 8;

class Tile {
    public:
        void setup();
        void draw(vec3 coords);

        ofBoxPrimitive mesh;
};