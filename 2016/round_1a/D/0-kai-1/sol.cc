#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::make_pair;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

void init_only_once();
void clear_global_variables();
void init_per_case();

struct pairhash {
    public:
        template <typename T, typename U>
            std::size_t operator()(const std::pair<T, U> &x) const
            {
                return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
            }
};

#define N_MAX_SIZE 101

int S, R, C;
vector<pair<int, char> > X;

// The positions of eaten food
set<pair<int, int> > eaten_foods;

typedef pair<int, int> Position;

#define MP make_pair

/*
struct Position {

	Position()
	{
		r = l = 0;
	}

	Position(int _r, int _l)
	{
		r = _r;
		l = _l;
	}

	int r, l;
};
*/

enum Direction { RIGHT, DOWN, LEFT, UP };

class Snake {

public:

Snake()
{
	len = 1;
	head = MP(1, 1);
	children[head] = 1;
	tq.push(head);
}

Position get_new_head(Direction d)
{
	Position new_head = MP(head.first, head.second);

	switch (d) {
		case RIGHT:
			new_head.second++;
			if (new_head.second > C)
				new_head.second = 1;
			break;

		case DOWN:
			new_head.first++;
			if (new_head.first > R)
				new_head.first = 1;
			break;

		case LEFT:
			new_head.second--;
			if (new_head.second < 1)
				new_head.second = C;
			break;

		case UP:
			new_head.first--;
			if (new_head.first < 1)
				new_head.first = R;

			break;
		default:
			assert(0);
			break;
	}

	return new_head;
}

bool move_next(Direction d)
{
	Position new_head = get_new_head(d);

	if ((new_head.first + new_head.second) % 2 != 0 &&
		eaten_foods.find(make_pair(new_head.first, new_head.second)) == eaten_foods.end()) {

		len++;

		// Eat food, so do not delete the oldest child
		eaten_foods.insert(make_pair(new_head.first, new_head.second));

	} else {

		// Delete the oldest child
		children[tq.front()] = 0;
		tq.pop();

		if (children[new_head] == 1) {
			// Just to increase the length() of children
			return false;
		}

	}

	children[new_head] = 1;
	head = new_head;
	tq.push(new_head);

	return true;
}

int length()
{
	return len;
}

void print()
{
	cout << "\tSnake children:" << endl;

	for (auto it = children.begin(); it != children.end(); it++) {
		cout << "(" << it->first.first << "," << it->first.second << ") ";
		it++;
	}
	cout << endl;
	cout << endl;
}

private:
	int len;
	Position head;
	unordered_map<Position, int, pairhash> children;
	queue<Position> tq;
};

void handle_input()
{
	cin >> S >> R >> C;

	int t;
	char d;

	for (int iii = 0; iii < S; iii++) {
		cin >> t >> d;
		X.push_back(make_pair(t, d));
	}
}

Direction get_next_direction(Direction drect, char x)
{
	switch (drect) {

		case RIGHT:
			if (x == 'L')
				return UP;
			return DOWN;

		case DOWN:
			if (x == 'L')
				return RIGHT;
			return LEFT;

		case LEFT:
			if (x == 'L')
				return DOWN;
			return UP;

		case UP:
			if (x == 'L')
				return LEFT;
			return RIGHT;

		default:
			assert(0);
			break;
	}
	assert(0);
}

int run()
{
	int ans = 0;

	Direction drect = RIGHT;
	int cnt_sec = 0;
	int X_index = 0;

	Snake snake;

	while (X_index < X.size()) {

		while (cnt_sec < X[X_index].first) {

			// Move to the same direction
			if (!snake.move_next(drect))
				return snake.length();

// snake.print();

			cnt_sec++;
		}

		drect = get_next_direction(drect, X[X_index].second);

		X_index++;
	}

	int iii = 0;
	while (iii < R || iii < C) {

		if (!snake.move_next(drect))
			return snake.length();

// snake.print();
		iii++;
	}

	return snake.length();
}

int main()
{
	init_only_once();

	int total_cases_count = 0;
	cin >> total_cases_count;

	long long run_ret = 0;

	for (int tt = 1; tt <= total_cases_count; tt++) {

		clear_global_variables();

		handle_input();

		init_per_case();

		run_ret = run();

		cout << "Case #" << tt << ": " << run_ret << endl;

	}

	return 0;
}

void init_only_once()
{
}

void clear_global_variables()
{
	X.clear();
	eaten_foods.clear();
}

void init_per_case()
{
}

