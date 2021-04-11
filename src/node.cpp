#include <cmath>

#include "node.h"

Node::Node(int x, int y)
    : x(x), y(y)
{
    position.x = (float) x;
    position.y = (float) y;
}

Node::~Node()
{
}

void Node::addNeighbors(Node grid[], int cols, int rows)
{
    neighbors.clear();

    // adjacent neighbors
    if(y-1 >= 0)
    {
        neighbors.push_back(&grid[cols * (y-1) + x]);
    }
    if(y+1 < rows)
    {
        neighbors.push_back(&grid[cols * (y+1) + x]);
    }
    if(x-1 >= 0)
    {
        neighbors.push_back(&grid[cols * y + (x-1)]);
    }
    if(x+1 < cols)
    {
        neighbors.push_back(&grid[cols * y + (x+1)]);
    }

    // diagonal neighbors
    if(x-1 >= 0 && y-1 >= 0)
    {
        neighbors.push_back(&grid[cols * (y-1) + (x-1)]);
    }
    if(x+1 < cols && y-1 >= 0)
    {
        neighbors.push_back(&grid[cols * (y-1) + (x+1)]);
    }
    if(x-1 >= 0 && y+1 < rows)
    {
        neighbors.push_back(&grid[cols * (y+1) + (x-1)]);
    }
    if(x+1 < cols && y+1 < rows)
    {
        neighbors.push_back(&grid[cols * (y+1) + (x+1)]);
    }
}

void Node::addVector(int resolution)
{
    float min = 2.0f;
    Node* min_neighbor = nullptr;
    for(auto& neighbor : neighbors)
    {
        if(std::abs(neighbor->score) < min) 
        {
            min = std::abs(neighbor->score);
            min_neighbor = neighbor;
        }
    }
    vector = min_neighbor->position - position;

    //line[0] = sf::Vertex(position * (float)resolution);
    //line[1] = sf::Vertex((position + vector) * (float)resolution);

    line[0] = sf::Vertex(sf::Vector2f(x * resolution, y * resolution));
    line[1] = sf::Vertex(sf::Vector2f(x * resolution + (vector.x - 4),
                y * resolution + (vector.y - 4)));
}
