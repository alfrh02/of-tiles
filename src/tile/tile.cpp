#include "tile.h"

void Tile::setup() {
    mesh.set(TILE_SIZE, 1, TILE_SIZE);
}

void Tile::draw(vec3 coords) {
    vec3 c = vec3(coords.x + TILE_SIZE/2, coords.y, coords.z + TILE_SIZE/2);

    mesh.setPosition(c);
    mesh.draw();
}