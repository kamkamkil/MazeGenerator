#include "mazeGenerator.hpp"
#include "drawMaze.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <utility>
#include "dijkstra.hpp"

enum menu_state
{
    normal,
    size,
    dijk_set_start,
    dijk_set_end,
    dijk
};

int main(int argc, char const *argv[])
{

    menu_state menu = normal;
    float wall = 0.2;
    const int window_w = 1920;
    const int window_h = 1080;
    int maze_h = 4;
    int maze_w = 4;
    auto maze = mazeGenerator(maze_h, maze_w);
    std::pair<int, int> d_star;
    std::pair<int, int> d_end;

    sf::RenderWindow window(sf::VideoMode(window_w, window_h), "My window");
    bool ismousepress = true;
    while (window.isOpen())
    {
    float block = (window_w < window_h ? window_w : window_h) * 0.80 / maze_h; //@FIXME nie jest to najlepszy sposób na determinacjie wielkości pola ze wzglęgu na wielkość okna

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);

            if (ismousepress)
            {
                switch (menu)
                {
                case normal:
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 300 && localPosition.y > 100 && localPosition.y < 100 + 25)
                        maze = mazeGenerator(maze_h, maze_w);
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 200 && localPosition.y > 130 && localPosition.y < 130 + 25)
                        menu = size;
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 300 && localPosition.y > 160 && localPosition.y < 160 + 25)
                        menu = dijk_set_start;
                    break;
                case size:
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 25 && localPosition.y > 130 && localPosition.y < 130 + 25)
                        maze_w--;
                    if (localPosition.x > 1300 && localPosition.x < 1300 + 25 && localPosition.y > 130 && localPosition.y < 130 + 25)
                        maze_w++;
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 25 && localPosition.y > 190 && localPosition.y < 190 + 25)
                        maze_h--;
                    if (localPosition.x > 1300 && localPosition.x < 1300 + 25 && localPosition.y > 190 && localPosition.y < 190 + 25)
                        maze_h++;
                    if (localPosition.x > 1350 && localPosition.x < 1350 + 100 && localPosition.y > 220 && localPosition.y < 220 + 25)
                    {
                        maze = mazeGenerator(maze_h, maze_w);
                        menu = normal;
                    }
                    break;
                case dijk_set_start:

                    if (localPosition.x < maze_w * (block + block * wall) && localPosition.y < maze_h * (block + block * wall))
                    {
                        int x = std::floor(localPosition.x / (block + block * wall));
                        int y = std::floor(localPosition.y / (block + block * wall));
                        d_star = {y, x};
                    }
                    menu = dijk_set_end;
                    break;
                case dijk_set_end:
                    if (localPosition.x < maze_w * (block + block * wall) && localPosition.y < maze_h * (block + block * wall))
                    {
                        int x = std::floor(localPosition.x / (block + block * wall));
                        int y = std::floor(localPosition.y / (block + block * wall));
                        d_end = {y, x};
                    }
                    menu = dijk;
                    break;
                case dijk:
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 300 && localPosition.y > 100 && localPosition.y < 100 + 25)
                    menu = normal;
                    break;
                }
            }
            ismousepress = false;
        }
        else
        {
            ismousepress = true;
        }

        drawMaze(window, maze, window_w, window_h);

        {
            sf::Font font;
            if (!font.loadFromFile("../fonts/Lato-Black.ttf"))
            {
            }
            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Red);
            switch (menu)
            {
            case normal:
                text.setString("wygeneruj nowy labirynt");
                text.setPosition(1200, 100);
                window.draw(text);
                text.setString("zmien rozmiar labiryntu");
                text.setPosition(1200, 130);
                window.draw(text);
                text.setString("najdz najkrotsza droge metoda dijkstry");
                text.setPosition(1200, 160);
                window.draw(text);
                break;
            case size:
                text.setString("szerokosc labiryntu");
                text.setPosition(1200, 100);
                window.draw(text);

                text.setString("-");
                text.setPosition(1200, 130);
                window.draw(text);

                text.setString("+");
                text.setPosition(1300, 130);
                window.draw(text);

                text.setString(std::to_string(maze_w));
                text.setPosition(1250, 130);
                window.draw(text);

                text.setString("wysokosc labiryntu");
                text.setPosition(1200, 160);
                window.draw(text);

                text.setString("-");
                text.setPosition(1200, 190);
                window.draw(text);

                text.setString(std::to_string(maze_h));
                text.setPosition(1250, 190);
                window.draw(text);

                text.setString("+");
                text.setPosition(1300, 190);
                window.draw(text);

                text.setString("powrot");
                text.setPosition(1350, 220);
                window.draw(text);
                break;
            case dijk_set_start:
                text.setString("wybierz pole startowe");
                text.setPosition(1200, 100);
                window.draw(text);
                break;
            case dijk_set_end:
                text.setString("wybierz pole koncowe");
                text.setPosition(1200, 100);
                window.draw(text);
                break;
            case dijk:
                text.setString("powrot");
                text.setPosition(1200, 100);
                window.draw(text);
                for (auto var : dijkstra(d_star, d_end, maze).first)
                {
                    drawBlock(window, var.second, var.first, block, wall);
                }
                break;
            }

            window.display();
        }
    }

    return 0;
}
