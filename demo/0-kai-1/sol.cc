#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

void init_only_once();
void clear_global_variables();
void init_per_case();




void handle_input()
{
}

long long run()
{
	long long ans = 0;



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
}

void init_per_case()
{
}
