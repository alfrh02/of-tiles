#include "tileMaster.h"
#include "math.h"

void TileMaster::setup(int tileNumber) {
    for (int i = 0; i < tileNumber; i++) {
        Tile t{};
        t.setup();
        tiles.push_back(t);
    }
}

void TileMaster::draw(vec3 coords, bool centred) {
    int size = tiles.size();

    int x = coords.x;
    int z = coords.z;
    if (centred) {
        x = -(sqrt(size) / 2);
        z = x;
    }

    for (int i = 0; i < size; i++) {
        vec3 pos = vec3(x * TILE_SIZE, 0, z * TILE_SIZE);

        //ofSetColor((255/25)*i);
        ofSetColor(33);
        if ((x % 2 || z % 2) && (x % 2 == false || z % 2 == 0)) {
            ofSetColor(18);
        }
        tiles[i].draw(pos);

        x++;
        if (centred) {
            if (x >= sqrt(size) / 2) {
                z++;
                x = -(sqrt(size) / 2);
            }
        } else if (x >= sqrt(size)) {
            z++;
            x = coords.x;
        }
    }
}