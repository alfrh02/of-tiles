#include "tileMaster.h"

void TileMaster::setup(int tileNumber) {
    for (int i = 0; i < tileNumber; i++) {
        Tile t{};
        t.setup();
        tiles.push_back(t);
    }
}

void TileMaster::draw(vec3 coords, float islandMargin) {
    int size = tiles.size();

    int x = -(sqrt(size) / 2);
    float y = 0;
    int z = x;

    for (int i = 0; i < size; i++) {
        // noise
        y = ofNoise(vec2(x, z));
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

        // // gradient
        // ofSetColor((255/25)*i);
        // // noise
        // ofSetColor((y/2) * 255);

        // // checkerboard pattern
        // ofSetColor(33);
        // if ((x % 2 || z % 2) && (x % 2 == false || z % 2 == 0)) {
        //     ofSetColor(18);
        // }

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

void TileMaster::increment() {
    Tile t{};
    t.setup();
    tiles.push_back(t);
}

void TileMaster::decrement() {
    if (tiles.size() != 1) {
        tiles.pop_back();
    }
}