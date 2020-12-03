#pragma once
#include <SFML/Graphics.hpp>
#include "mazeGenerator.cpp"

void drawMaze(MyTable table)
{
    const float wall = 0.2;
    const float block = 30;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear();

        for (int a = 0; a <= table.hight; a++)
        {
            for (int b = 0; b <= table.width; b++)
            {
                float x = (block * wall) * (1 + b / wall + b);
                float y = (block * wall) * (1 + a / wall + a);
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block * wall, block * wall));
                    rectangle.setPosition(x - block * wall, y - block * wall);
                    window.draw(rectangle);
                }
                if (a == table.hight || b == table.width)
                    continue;
                auto node = table(a, b);
                if (!node.up)
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block, block * wall));
                    rectangle.setPosition(x, y - block * wall);
                    window.draw(rectangle);
                };
                if (!node.left)
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block * wall, block));
                    rectangle.setPosition(x - block * wall, y);
                    window.draw(rectangle);
                };
                if (!node.down)
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block, block * wall));
                    rectangle.setPosition(x, y + block);
                    window.draw(rectangle);
                };
                if (!node.right)
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block * wall, block));
                    rectangle.setPosition(x + block, y);
                    window.draw(rectangle);
                };
            }
        }

        window.display();
    }
}