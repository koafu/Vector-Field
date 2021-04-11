#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Node
{
    int x, y;
    float score;

    std::vector<Node*> neighbors = std::vector<Node*>(8);

    sf::Vector2f position;
    sf::Vector2f vector;
    sf::Vertex line[2];

    Node() = default;
    Node(int x, int y);
    ~Node();

    void addNeighbors(Node grid[], int cols, int rows);
    void addVector(int resolution);
};
