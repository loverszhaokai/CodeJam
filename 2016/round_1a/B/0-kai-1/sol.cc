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

#define N_MAX_SIZE 1001
#define M_MAX_SIZE 101

int N;
int N_arr[N_MAX_SIZE];
int M;
int M_arr[M_MAX_SIZE][2];

void handle_input()
{
	cin >> N >> M;

	for (int iii = 0; iii < N; iii++) {
		cin >> N_arr[iii];
	}

	for (int iii = 0; iii < M; iii++) {
		cin >> M_arr[iii][0] >> M_arr[iii][1];
	}
}

long long run()
{
	int ans = 0;

	for (int iii = 0; iii < M; iii++) {

		long double total_v = 1.0;
		const int left = M_arr[iii][0];
		const int right = M_arr[iii][1];
		const int step = right - left + 1;

		for (int jjj = left; jjj <= right; jjj++) {
			total_v *= (pow(N_arr[jjj], 1.0 / step));
		}

// cout << "step==" << step << endl;
// cout << "total_v==" << total_v << endl;

		printf("%.9Lf\n", total_v);
	}

	return ans;
}

int main()
{
	int total_cases_count = 0;
	cin >> total_cases_count;

	long long run_ret = 0;

	for (int tt = 1; tt <= total_cases_count; tt++) {

		handle_input();

		cout << "Case #" << tt << ":" << endl;

		run_ret = run();
	}

	return 0;
}
