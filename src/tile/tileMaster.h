#pragma once

#include "ofMain.h"
#include "tile.h"

using namespace glm;

class TileMaster {
    public:
        void setup(int tileNumber);
        void draw(vec3 coords, float islandMargin);
        void setTileCount(int num);
        void increment();
        void decrement();

    private:
        vector<Tile> tiles;
};