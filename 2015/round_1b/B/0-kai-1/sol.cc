#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define DBG

#define MAX_SIZE 10010

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;

int R, C, N, M;

int matrix[MAX_SIZE][MAX_SIZE];

// ------ Global Variables ------


// ====== Function declarations ======

void print_array(const int array[], const char *array_name, const int array_size);

// ------ Function declarations ------

int init_only_once()
{
#ifdef DBG
	log_fs << ">>>>init_only_once()" << endl;
#endif 

#ifdef DBG
	log_fs << "<<<<init_only_once()" << endl << endl;
#endif

        return 0;
}

int handle_input()
{
#ifdef DBG
	log_fs << ">>>>>>handle_input()" << endl;
#endif

        cin >> R >> C >> N;
	M = R * C - N;

#ifdef DBG
	log_fs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	log_fs << ">>>>>>init_per_case()" << endl;
#endif

        for (int iii = 1; iii <= R; iii++) {
		for (int jjj = 1; jjj <= C; jjj++) {
			matrix[iii][jjj] = 4;
                }
        }

	for (int iii = 1; iii <= C; iii++) {
		matrix[1][iii] = 3;
                matrix[R][iii] = 3;
        }
        
	for (int iii = 1; iii <= R; iii++) {
		matrix[iii][1] = 3;
                matrix[iii][C] = 3;
        }

	matrix[1][1] = 2;
        matrix[1][C] = 2;
        matrix[R][1] = 2;
        matrix[R][C] = 2;

#ifdef DBG
	log_fs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

int get_sol_1()
{
        log_fs << "<<<<<<<<get_sol_1()" << endl;
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;

        if (R == 1 || C == 1) {
		const int max_R_C = std::max(R, C);
		count_1 = 1;
		if (1 == max_R_C % 2)
			count_1 += 1;
		if (max_R_C >= 3)
			count_2 += (max_R_C-2) / 2;
		int sol = 0;
		if (M <= count_2) {
			sol += 2 * M;
                } else {
			sol += 2 * count_2;
			sol += 1 * (M - count_2);
                }
		return sol;
        }

	// The first line
	count_2 = 1;
	if (1 == C % 2)
		count_2 += 1;
	if (C >= 3)
		count_3 += (C-2) / 2;

	// The last line
	if (1 == R % 2) {
		count_2 *= 2;
		count_3 *= 2;
        } else {
		if (0 == C % 2)
			count_2 += 1;
		if (C >= 3)
			count_3 += (C-1) / 2;
        }

	for (int iii = 2; iii < R; iii++) {
		if (1 == iii % 2) {
			// Odd line
			count_3 += 1;
			if (1 == C % 2)
				count_3 += 1;
			if (C >= 3)
				count_4 += (C-2) / 2;
                } else {
			// Even line
			if (0 == C % 2)
				count_3 += 1;
			if (C >= 3)
				count_4 += (C-1) / 2;
                }
        }

        log_fs << "count_2=" << count_2 << "  " 
               << "count_3=" << count_3 << "  "
               << "count_4=" << count_4 << endl;

	int sol = 0;
	if (M <= count_4) {
		sol += 4 * M;
        } else if (M <= (count_4 + count_3)) {
		sol += 4 * count_4;
		sol += 3 * (M - count_4);
        } else {
		sol += 4 * count_4;
		sol += 3 * count_3;
                sol += 2 * (M - count_4 - count_3);
        }
	return sol;
}

int get_sol_2()
{
        log_fs << "<<<<<<<<get_sol_2()" << endl;
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;

        if (R == 1 || C == 1) {
		const int max_R_C = std::max(R, C);

		if (0 == max_R_C % 2)
			count_1 += 1;
		if (max_R_C >= 3)
			count_2 += (C-1) / 2;

		int sol = 0;
		if (M <= count_2) {
			sol += 2 * M;
                } else {
			sol += 2 * count_2;
			sol += 1 * (M - count_2);
                }
		return sol;
        }

	// The first line
	if (0 == C % 2)
		count_2 += 1;
	if (C >= 3)
		count_3 += (C-1) / 2;

	// The last line
	if (1 == R % 2) {
		count_2 *= 2;
		count_3 *= 2;
        } else {
		count_2 += 1;
		if (1 == C % 2)
			count_2 += 1;
		if (C >= 3)
			count_3 += (C-2) / 2;
        }

	for (int iii = 2; iii < R; iii++) {
		if (1 == iii % 2) {
			// Odd line
			if (0 == C % 2)
				count_3 += 1;
			if (C >= 3)
				count_4 += (C-1) / 2;

                } else {
			// Even line
			count_3 += 1;
			if (1 == C % 2)
				count_3 += 1;
			if (C >= 3)
				count_4 += (C-2) / 2;
                }
        }

        log_fs << "count_2=" << count_2 << "  " 
               << "count_3=" << count_3 << "  "
               << "count_4=" << count_4 << endl;

	int sol = 0;
	if (M <= count_4) {
		sol += 4 * M;
        } else if (M <= (count_4 + count_3)) {
		sol += 4 * count_4;
		sol += 3 * (M - count_4);
        } else {
		sol += 4 * count_4;
		sol += 3 * count_3;
                sol += 2 * (M - count_4 - count_3);
        }
	return sol;
}

int get_sum()
{
	int sum = 0;

	if (1 == R || 1 == C) {
		const int max_R_C = std::max(R, C);
		sum = 2 + 2 * (max_R_C - 2);
        } else {
		sum = 2 * 4;
                sum += 3 * (R - 2) * 2;
                sum += 3 * (C - 2) * 2;
		sum += 4 * (R * C - 4 - 2 * (R - 2) - 2 * (C - 2));
        }
        
        return sum;
}

int get_ans()
{
#ifdef DBG
	log_fs << ">>>>>>>>get_ans()" << endl;
#endif
	int ans = 0;

	const int sol_1 = get_sol_1();
	const int sol_2 = get_sol_2();

	const int sol = std::max(sol_1, sol_2);

	const int sum = get_sum();

#ifdef DBG
	log_fs << ">>>>>>>>sol=" << sol << endl;
	log_fs << ">>>>>>>>sum=" << sum << endl;
#endif

	return (sum / 2) - sol;
}

int run()
{
#ifdef DBG
	log_fs << ">>>>>>run()" << endl;
#endif

        if (1 == R && 1 == C) {
		return 0;
        }

	if (0 == R * C % 2) {
		if (N <= R * C / 2)
			return 0;
        } else {
		if (N <= 1 + R * C / 2)
			return 0;
        }

	const int ans = get_ans();

#ifdef DBG
	log_fs << "<<<<<<run() = " << ans << endl << endl;
#endif
	return ans;
}

int main()
{
#ifdef DBG
        log_fs.open("log.txt", std::fstream::out);
	log_fs << ">>main()" << endl << endl;
#endif

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		log_fs << "Case #" << tt << ": " << run_ret << endl;
#endif
        }

#ifdef DBG
	log_fs << "<<main()" << endl;
	log_fs.close();
#endif
        return 0;
}

void print_array(const int array[], const char *array_name, const int array_size)
{
#ifdef DBG

        log_fs << "\t[" << array_name << "]=" << endl << "\t";

	for (int iii = 0; iii < array_size; iii++) {
		log_fs << array[iii] << "  ";
        }
	log_fs << endl << endl;
#endif
}

