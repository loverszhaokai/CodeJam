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
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::map;
using std::pair;
using std::make_pair;
using std::stack;
using std::string;
using std::vector;

void init_only_once();
void clear_global_variables();
void init_per_case();


#define N_MAX_SIZE 101

int S, R, C;
vector<pair<int, char> > X;

int matrix[N_MAX_SIZE][N_MAX_SIZE];


struct Position {

	Position()
	{}

	Position(int _r, int _l)
	{
		r = _r;
		l = _l;
	}

	bool operator == (const Position &rhs)
	{
		return this->r == rhs.r && this->l == rhs.l;
	}
	
	int r, l;
};

enum Direction { RIGHT, DOWN, LEFT, UP };

class Snake {

public:

Snake()
{
	children.push_front(Position(1, 1));
}

Position get_new_head(Direction d)
{
	Position new_head(children.front().r, children.front().l);

	switch (d) {
		case RIGHT:
			new_head.l++;
			if (new_head.l > C)
				new_head.l = 1;
			break;

		case DOWN:
			new_head.r++;
			if (new_head.r > R)
				new_head.r = 1;
			break;

		case LEFT:
			new_head.l--;
			if (new_head.l < 1)
				new_head.l = C;
			break;

		case UP:
			new_head.r--;
			if (new_head.r < 1)
				new_head.r = R;

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

	if (matrix[new_head.r][new_head.l]) {

		// Eat food, so do not delete the oldest child
		matrix[new_head.r][new_head.l] = 0;
		children.push_front(new_head);

	} else {

		// Delete the oldest child
		children.pop_back();
		if (is_die(new_head)) {
			// Just to increase the length() of children
			children.push_front(new_head);
			return false;
		}
		children.push_front(new_head);

	}

	return true;
}

bool is_die(const Position &new_head)
{
	if (std::find(children.begin(), children.end(), new_head) != children.end())
		return true;
	return false;
}

int length()
{
	return children.size();
}

void print()
{
	cout << "\tSnake children:" << endl;

	list<Position>::iterator it = children.begin();
	while (it != children.end()) {
		cout << "(" << it->r << "," << it->l << ") ";
		it++;
	}
	cout << endl;
	cout << endl;
}

private:
	list<Position> children;
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
}

void init_per_case()
{
	for (int iii = 1; iii <= R; iii++)
		for (int jjj = 1; jjj <=C; jjj++)
			matrix[iii][jjj] = (iii + jjj) % 2;
}

