#include "tileMaster.h"

void TileMaster::setup(int tileNumber) {
    for (int i = 0; i < tileNumber; i++) {
        Tile t{};
        t.setup();
        tiles.push_back(t);
    }
}

void TileMaster::draw(vec3 coords) {
    int size = tiles.size();

    int x = -(sqrt(size) / 2);
    int z = x;

    for (int i = 0; i < size; i++) {
        vec3 pos = vec3(x * TILE_SIZE, 0, z * TILE_SIZE);
        if ((int)sqrt(size) % 2 == 1) {
            pos = vec3(x * TILE_SIZE - (TILE_SIZE / 2), 0, z * TILE_SIZE - (TILE_SIZE / 2));
        }

        //ofSetColor((255/25)*i);
        ofSetColor(33);
        if ((x % 2 || z % 2) && (x % 2 == false || z % 2 == 0)) {
            ofSetColor(18);
        }
        tiles[i].draw(pos);

        x++;
        if (x >= sqrt(size) / 2) {
            z++;
            x = -(sqrt(size) / 2);
        }
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