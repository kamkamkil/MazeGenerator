#include "mazeGenerator.hpp"
#include "drawMaze.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(20, 25);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");

    while (window.isOpen())
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            maze = mazeGenerator(20, 25);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        drawMaze(window, maze);

        window.display();
    }

    return 0;
}
