#pragma once

#include "FastNoiseLite.h"
#include "constants.h"
#include "node.h"

class Grid
{
private:
    int cols, rows;
    int resolution;

    Node* grid = nullptr;

    FastNoiseLite noise;
    float* noiseData = nullptr;

public:
    Grid(int resolution);
    ~Grid();

    void build();
    void draw(sf::RenderWindow &window);
};
