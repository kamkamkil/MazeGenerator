#include <utility>
#include <vector>
#include <stack>
#include <unordered_set>
#include <random>
#include <iostream>
#include <iterator>
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
    std::size_t operator () (std::pair<T1, T2> const &pair) const
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
    MyTable(int hight, int width) : data(hight, std::vector<Node>(width, Node())){};
    Node &operator()(int y, int x) { return data[y][x]; }
};

MyTable mazeGenerator(int hight, int width)
{
    MyTable maze(hight, width);
    std::stack<std::pair<int, int>> stack;
    std::unordered_set<std::pair<int, int>,pair_hash> set;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist_hight(0, hight);
    std::uniform_int_distribution<int> uniform_dist_width(0, width);
    random_selector<> selector;
    stack.push({uniform_dist_hight(e1), uniform_dist_width(e1)});
    set.insert(stack.top());
    while (!stack.empty())
    {
        //@TODO przenieść to może do innej funkcji czy coś takiego bo nie wygląda to za dobrze w tej pentli
        std::vector<std::pair<int, int>> v; //@TODO zmiana nazwy
        if (stack.top().first > 0 && set.find({stack.top().first - 1,stack.top().second}) == set.end())
            v.push_back({stack.top().first - 1,stack.top().second});
        if (stack.top().first < hight && set.find({stack.top().first + 1,stack.top().second}) == set.end())
            v.push_back({stack.top().first + 1,stack.top().second});
        if (stack.top().second > 0  && set.find({stack.top().first,stack.top().second - 1 }) == set.end())
            v.push_back({stack.top().first,stack.top().second - 1});
        if (stack.top().second < width  && set.find({stack.top().first,stack.top().second + 1 }) == set.end())
            v.push_back({stack.top().first,stack.top().second + 1});
        auto pair = selector(v);
        


    }

    return maze;
}

int main(int argc, char const *argv[])
{
    mazeGenerator(10, 10);

    return 0;
}
