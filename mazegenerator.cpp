#include <utility>
#include <vector>
#include <stack>
#include <unordered_set>
#include <random>
#include <iostream>
#include <iterator>
#include <SFML/Graphics.hpp>

//stolen from : https://gist.github.com/cbsmith/5538174

template <typename RandomGenerator = std::default_random_engine>
struct random_selector
{
    //On most platforms, you probably want to use std::random_device("/dev/urandom")()
    random_selector(RandomGenerator g = RandomGenerator(std::random_device()()))
        : gen(g) {}

    template <typename Iter>
    Iter select(Iter start, Iter end)
    {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(gen));
        return start;
    }

    //convenience function
    template <typename Iter>
    Iter operator()(Iter start, Iter end)
    {
        return select(start, end);
    }

    //convenience function that works on anything with a sensible begin() and end(), and returns with a ref to the value type
    template <typename Container>
    auto operator()(const Container &c) -> decltype(*begin(c)) &
    {
        return *select(begin(c), end(c));
    }

private:
    RandomGenerator gen;
};
//stolen from https://www.techiedelight.com/use-pair-key-std-unordered_set-cpp/
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

///////////////////////////////////////

struct Node
{
    Node() : up(false), down(false), right(false), left(false){};
    bool up;
    bool down;
    bool right;
    bool left;
};

class MyTable
{
private:
    std::vector<std::vector<Node>> data;

public:
    const int hight;
    const int width;
    MyTable(int hight, int width) : data(hight, std::vector<Node>(width, Node())), hight(hight), width(width){};
    Node &operator()(int y, int x) { return data[y][x]; }
    Node &operator()(std::pair<int, int> p) { return data[p.first][p.second]; }
    void display()
    {
        int a = 0;
        int b = 0;
        for (auto var : data)
        {
            for (auto var1 : var)
            {
                std::cout << "( " << a << ", " << b << " ) " << ((var1.up) ? "up" : "_");
                std::cout << "  " << ((var1.left) ? "left " : "_");
                std::cout << "  " << ((var1.down) ? "down" : "_");
                std::cout << "  " << ((var1.right) ? "right" : "_");
                std::cout << std::endl;
                b++;
            }
            a++;
            b = 0;
        }
    }
};

MyTable mazeGenerator(int hight, int width)
{
    MyTable maze(hight, width);
    std::stack<std::pair<int, int>> stack;
    std::unordered_set<std::pair<int, int>, pair_hash> set;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist_hight(0, hight - 1);
    std::uniform_int_distribution<int> uniform_dist_width(0, width - 1);
    random_selector<> selector;
    stack.push({uniform_dist_hight(e1), uniform_dist_width(e1)});
    set.insert(stack.top());
    while (!stack.empty())
    {
        auto c_node = stack.top();
        //@TODO przenieść to może do innej funkcji czy coś takiego bo nie wygląda to za dobrze w tej pentli
        std::vector<std::pair<int, int>> v; //@TODO zmiana nazwy
        if (c_node.first > 0 && set.find({c_node.first - 1, c_node.second}) == set.end())
            v.push_back({c_node.first - 1, c_node.second});
        if (c_node.first < hight - 1 && set.find({c_node.first + 1, c_node.second}) == set.end())
            v.push_back({c_node.first + 1, c_node.second});
        if (c_node.second > 0 && set.find({c_node.first, c_node.second - 1}) == set.end())
            v.push_back({c_node.first, c_node.second - 1});
        if (c_node.second < width - 1 && set.find({c_node.first, c_node.second + 1}) == set.end())
            v.push_back({c_node.first, c_node.second + 1});
        if (!v.empty())
        {
            auto pair = selector(v);
            set.insert(pair);
            if (c_node.first != pair.first)
                if (c_node.first - 1 == pair.first)
                {
                    maze(c_node).up = true;
                    maze(pair).down = true;
                }
                else
                {
                    maze(c_node).down = true;
                    maze(pair).up = true;
                }
            else
            {
                if (c_node.second - 1 == pair.second)
                {
                    maze(c_node).left = true;
                    maze(pair).right = true;
                }
                else
                {
                    maze(c_node).right = true;
                    maze(pair).left = true;
                }
            }

            stack.push(pair);
        }
        else
        {
            stack.pop();
        }
    }

    return maze;
}

void drawMaze(MyTable table)
{
    const float wall = 0.1;
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

        for (int a = 0; a < table.hight; a++)
        {
            for (int b = 0; b < table.width; b++)
            {
                auto node = table(a, b);
                float x = (block * wall) * (1 + b / wall + b);
                float y = (block * wall) * (1 + a / wall + a);
                {
                    sf::RectangleShape rectangle(sf::Vector2f(block * wall, block * wall));
                    rectangle.setPosition(x - block * wall, y - block * wall);
                    window.draw(rectangle);
                }
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

int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(15, 25);
    drawMaze(maze);
    return 0;
}
