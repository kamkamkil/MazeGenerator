#include "mazeGenerator.hpp"
#include "drawMaze.hpp"
#include <SFML/Graphics.hpp>
#include <string>

enum menu_state
{
    normal,
    size
};

int main(int argc, char const *argv[])
{

    menu_state menu = normal;

    const int window_w = 1920;
    const int window_h = 1080;
    int maze_h = 10;
    int maze_w = 10;

    auto maze = mazeGenerator(maze_h, maze_w);

    sf::RenderWindow window(sf::VideoMode(window_w, window_h), "My window");
    bool ismousepress = true;
    while (window.isOpen())
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);

            if (ismousepress)
                switch (menu)
                {
                case normal:
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 300 && localPosition.y > 100 && localPosition.y < 100 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        maze = mazeGenerator(maze_h, maze_w);
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 200 && localPosition.y > 130 && localPosition.y < 130 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        menu = size;
                    break;
                case size:
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 25 && localPosition.y > 130 && localPosition.y < 130 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        maze_w--;
                    if (localPosition.x > 1300 && localPosition.x < 1300 + 25 && localPosition.y > 130 && localPosition.y < 130 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        maze_w++;
                    if (localPosition.x > 1200 && localPosition.x < 1200 + 25 && localPosition.y > 190 && localPosition.y < 190 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        maze_h--;
                    if (localPosition.x > 1300 && localPosition.x < 1300 + 25 && localPosition.y > 190 && localPosition.y < 190 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                        maze_h++;
                    if (localPosition.x > 1350 && localPosition.x < 1350 + 100 && localPosition.y > 220 && localPosition.y < 220 + 25) // doać to FloatRect sf::Text::getGlobalBounds 	( 		) 	const
                    {
                        maze = mazeGenerator(maze_h, maze_w);
                        menu = normal;
                    }
                    break;
                    // default:
                    //     break;
                }
            ismousepress = false;
        }
        else
        {
            ismousepress = true;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawMaze(window, maze, window_w, window_h);

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
        }
        window.display();
    }

    return 0;
}
