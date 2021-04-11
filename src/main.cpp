#include <SFML/Graphics.hpp>
#include <iostream>

#include "FastNoiseLite.h"
#include "grid.h"
#include "constants.h"

const unsigned int WIDTH = 1280;
const unsigned int HEIGHT = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Noise Field", sf::Style::Titlebar | sf::Style::Close);

    Grid grid(5);
    grid.build();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color(40,40,40,255));
        grid.draw(window);
        window.display();
    }
    return 0;
}
