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
	Iter select(Iter start, Iter end) {
		std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
		std::advance(start, dis(gen));
		return start;
	}

	//convenience function
	template <typename Iter>
	Iter operator()(Iter start, Iter end) {
		return select(start, end);
	}

	//convenience function that works on anything with a sensible begin() and end(), and returns with a ref to the value type
	template <typename Container>
	auto operator()(const Container& c) -> decltype(*begin(c))& {
		return *select(begin(c), end(c));
	}

private:
	RandomGenerator gen;
};
struct node
{
    node() : up(false), down(false), right(false), left(false){};
    bool up;
    bool down;
    bool right;
    bool left;
};

class MyTable
{
private:
    std::vector<std::vector<node>> data;

public:
    MyTable(int hight, int width) : data(hight, std::vector<node>(width, node())){};
    node &operator()(int y, int x) { return data[y][x]; }
};

MyTable mazeGenerator(int hight, int width)
{
    MyTable maze(hight, width);
    std::stack<std::pair<int, int>> stack;
    std::unordered_set<std::pair<int, int>> set;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist_hight(0, hight);
    std::uniform_int_distribution<int> uniform_dist_width(0, width);
    stack.push(std::pair(uniform_dist_hight(e1),uniform_dist_width(e1)));
    set.insert(stack.top());
    while(!stack.empty())
    {




    }



    return maze;
}

int main(int argc, char const *argv[])
{
    mazeGenerator(10, 10);

    return 0;
}
