#include "tile.h"

void Tile::setup() {
    mesh.set(TILE_SIZE, 1, TILE_SIZE);
}

void Tile::draw(vec3 coords) {
    mesh.setPosition(coords);
    mesh.draw();
}