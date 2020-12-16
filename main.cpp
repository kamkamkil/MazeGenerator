#include "mazeGenerator.hpp"
#include "drawMaze.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    const int window_w = 1920;
    const int window_h = 1080;
    const int maze_h = 10;
    const int maze_w = 10;

    auto maze = mazeGenerator(maze_h, maze_w);

    sf::RenderWindow window(sf::VideoMode(window_w, window_h), "My window");

    while (window.isOpen())
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            maze = mazeGenerator(maze_h, maze_w);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawMaze(window, maze, window_w, window_h);
        {
            sf::Font font;
            if (!font.loadFromFile("../fonts/Lato-Black.ttf"))
            {
            }
            sf::Text text;
            text.setFont(font);
            text.setString("wygeneruj nowy labirynt");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Red);
            text.setPosition(1200,100);
            window.draw(text);
        }

        window.display();
    }

    return 0;
}
