#include "tileMaster.h"

void TileMaster::setup(int tileNumber) {
    setTileCount(tileNumber);

    checkerboardOne = ofColor(255, 0, 255);
    checkerboardTwo = ofColor(18);
}

void TileMaster::draw(vec3 coords, float yLevel, float islandMargin, tileDecor decor) {
    int size = tiles.size();

    int x = -(sqrt(size) / 2);
    float y = 0;
    int z = x;

    for (int i = 0; i < size; i++) {
        // noise
        y = ofNoise(vec2(x, z)) * yLevel;
        y *= 2;

        // centre the camera properly
        // if the total amount of tiles is a square number, draw the tiles exactly in the centre of the scene
        // otherwise draw it from the corner of the tile
        vec3 pos = vec3(0, 0, 0);
        float tempTileSize = TILE_SIZE + islandMargin;
        if ((int)sqrt(size) % 2 == 1) {
            pos = vec3(
                x * tempTileSize - (tempTileSize / 2),
                y,
                z * tempTileSize - (tempTileSize / 2)
            );
        } else {
            pos = vec3(
                x * tempTileSize,
                y,
                z * tempTileSize
            );
        }

        switch(decor) {
            case Checkerboard:
                ofSetColor(checkerboardOne);
                if ((x % 2 || z % 2) && (x % 2 == false || z % 2 == 0)) {
                    ofSetColor(checkerboardTwo);
                }
                break;
            case Gradient:
                ofSetColor(((float)255 / size) * i);
                break;
            case Noise:
                ofSetColor(ofNoise(vec2(x, z)) * 255);
                break;
            case HarshNoise:
                ofSetColor(round(ofNoise(vec2(x, z))) * 255);
                break;
        }

        tiles[i].draw(pos);

        x++;
        if (x >= sqrt(size) / 2) {
            z++;
            x = -(sqrt(size) / 2);
        }
    }
}

void TileMaster::setTileCount(int num) {
    tiles.clear();
    for (int i = 0; i < num; i++) {
        Tile t{};
        t.setup();
        tiles.push_back(t);
    }
}