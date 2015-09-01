#include <cassert>
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


long long K;
int ANS;

void handle_input()
{
	cin >> K;
}

//       1234567   8   9     15
// S4 = "0010011" "0" "0011011"
//             ^       ^
//            ^         ^
//
// s4[9] = -1 * s4[7]
//

void recursively_run(const int n, const long long kkk, const int swit)
{
	// cout << "recursively_run(" << n << ", " << kkk << ", " << swit << ")" << endl;
	if (n == 1) {
		if (swit == -1)
			ANS = 1;
		else
			ANS = 0;
		return;
	}

	// Here must add (long long) before pow(), it dangerous
	const long long total = (long long)pow(2.0, n) - 1;
	const long long mid = (total + 1) / 2;

	if (kkk < mid) {
		return recursively_run(n - 1, kkk, swit);
	} else if (kkk == mid) {
		if (swit == -1)
			ANS = 1;
		else
			ANS = 0;
		return;
	} else if (kkk > total) {
		assert(false);
	} else {
		return recursively_run(n - 1, total + 1 - kkk, -1 * swit);
	}
}

long long run()
{
	int ans = 0;

	recursively_run(62, K, 1);

	return ans;
}

int main()
{
	int total_cases_count = 0;
	cin >> total_cases_count;

	long long run_ret = 0;

	for (int tt = 1; tt <= total_cases_count; tt++) {

		handle_input();

		run_ret = run();

		cout << "Case #" << tt << ": " << ANS << endl;
	}
	return 0;
}
