#pragma once

#include "ofMain.h"
#include "tile.h"

using namespace glm;

class TileMaster {
    public:
        void setup(int tileNumber);
        void draw(vec3 coords, bool centred);

    private:
        vector<Tile> tiles;
};