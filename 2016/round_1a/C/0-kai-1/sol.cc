#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::set;
using std::stack;
using std::string;
using std::vector;


#define N_MAX_SIZE       101
#define MATRIX_MAX_VALUE 0x3fffffff

int N, M;

int matrix[N_MAX_SIZE][N_MAX_SIZE];
int path[N_MAX_SIZE][N_MAX_SIZE];

set<pair<int, int> > roads;

struct Info {
	Info(int _a, int _b, int _c)
	{
		a = _a < _b ? _a : _b;
		b = _a < _b ? _b : _a;
		c = _c;
	}

	int a, b, c;
};

vector<Info> m_roads;


void init_only_once();
void clear_global_variables();
void init_per_case();


void handle_input()
{
	cin >> N >> M;

	int a, b, c;

	for (int iii = 0; iii < N; iii++) {
		for (int jjj = 0; jjj < N; jjj++) {

			matrix[iii][jjj] = MATRIX_MAX_VALUE;
			path[iii][jjj] = -1;

		}
	}

	for (int iii = 0; iii < M; iii++) {

		cin >> a >> b >> c;

		if (a != b) {

			// There maybe more than one roads between a and b
			if (c < matrix[a][b]) {

				matrix[a][b] = c;
				matrix[b][a] = c;

				path[a][b] = b;
				path[b][a] = a;
			}
		}

		m_roads.push_back(Info(a, b, c));
	}
}

void floyd()
{
	for (int iii = 0; iii < N; iii++)
		for (int jjj = 0; jjj < N; jjj++)
			for (int kkk = 0; kkk < N; kkk++) {

				if (jjj != kkk &&
					matrix[jjj][kkk] > matrix[jjj][iii] + matrix[iii][kkk]) {

					matrix[jjj][kkk] = matrix[jjj][iii] + matrix[iii][kkk];

					path[jjj][kkk] = iii;
					path[kkk][jjj] = iii;

				}
			}
}

void get_roads(const int i, const int j)
{
	if (path[i][j] == -1)
		return;

	if (path[i][j] == j || path[i][j] == i) {
		// The end, there is no road between i and j
		if (i < j)
			roads.insert(std::make_pair(i, j));
		else
			roads.insert(std::make_pair(j, i));
	} else {
		// There are roads between i and j
		get_roads(i, path[i][j]);
		get_roads(j, path[i][j]);
	}

	// Do search again
	path[i][j] = -1;
	path[j][i] = -1;
}

void init_roads()
{
	for (int iii = 0; iii < N; iii++)
		for (int jjj = 0; jjj < N; jjj++)
			if (path[iii][jjj] != -1)
				get_roads(iii, jjj);
}

void print()
{
	int a, b, c;

	for (int iii = 0; iii < M; iii++) {

		a = m_roads[iii].a;
		b = m_roads[iii].b;
		c = m_roads[iii].c;

		if (roads.find(std::make_pair(a, b)) == roads.end())
			cout << iii << endl;
		else {
			// Find p, but the time is bigger than c
			if (matrix[a][b] != c)
				cout << iii << endl;
		}
	}
}

long long run()
{
	long long ans = 0;

	floyd();

	init_roads();

	print();

	return ans;
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

		cout << "Case #" << tt << ":" << endl;

		run_ret = run();
	}

	return 0;
}

void init_only_once()
{
}

void clear_global_variables()
{
	roads.clear();
	m_roads.clear();
}

void init_per_case()
{
}
