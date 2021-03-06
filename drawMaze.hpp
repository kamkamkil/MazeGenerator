#pragma once
#include <SFML/Graphics.hpp>
#include "mazeGenerator.hpp"
/**
 * @brief rysuje labirynt za pomocą sfml 
 * 
 * @param window okno w jakim rysujemy
 * @param table labirynt
 * @param window_w wysokość okna 
 * @param window_h szerokość okna 
 * @param wall_s grubość sciany określona jako ułamek wielkości bloku 
 */
void drawMaze(sf::RenderWindow &window, MyTable table, int window_w = 1280, int window_h = 720, float wall_s = 0.2)
{
    const float wall = wall_s;
    const float block = (window_w < window_h ? window_w : window_h) * 0.80 / table.hight; //@FIXME nie jest to najlepszy sposób na determinacjie wielkości pola ze wzglęgu na wielkość okna

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
}
/**
 * @brief rysuje blok we-w labiryntu 
 * 
 * @param window okno w jakim rysujemy
 * @param x współrzędna x bloku  
 * @param y współrzędna y bloku 
 * @param block wielkość bloku 
 * @param wall grubość sciany określona jako ułamek wielkości bloku 
 */
void drawBlock(sf::RenderWindow &window, int x, int y, int block, float wall)
{
    x = (block * wall) * (1 + x / wall + x);
    y = (block * wall) * (1 + y / wall + y);
    sf::RectangleShape rectangle(sf::Vector2f(block, block));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color(100, 250, 50));
    window.draw(rectangle);
}