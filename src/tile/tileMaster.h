#pragma once

#include "ofMain.h"
#include "tile.h"

using namespace glm;

class TileMaster {
    public:
        void setup(int tileNumber);
        void draw(vec3 coords, float yLevel, float islandMargin, tileDecor decor);
        void setTileCount(int num);

    private:
        vector<Tile> tiles;
        ofColor checkerboardOne;
        ofColor checkerboardTwo;
};