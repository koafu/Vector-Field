#include "grid.h"

Grid::Grid(int resolution)
    : resolution(resolution)
{
    cols = (int) (WIDTH / resolution);
    rows = (int) (HEIGHT / resolution);

    grid = new Node[cols * rows];
    noise.SetNoiseType(FastNoiseLite::NoiseType_ValueCubic);

    for(int x = 0; x < cols; x++)
    {
        for(int y = 0; y < rows; y++)
        {
            grid[cols * y + x] = Node(x, y);
            grid[cols * y + x].score = noise.GetNoise((float)x, (float)y);
        }
    }
}

Grid::~Grid()
{
    delete[] grid;
}

void Grid::build()
{
    for(int x = 0; x < cols; x++)
    {
        for(int y = 0; y < rows; y++)
        {
            grid[cols * y + x].addNeighbors(grid, cols, rows);
            grid[cols * y + x].addVector(resolution);
        }
    }
}

void Grid::draw(sf::RenderWindow &window)
{
    for(int x = 0; x < cols; x++)
    {
        for(int y = 0; y < rows; y++)
        {
            window.draw(grid[cols * y + x].line, 2, sf::Lines);
        }
    }
}
