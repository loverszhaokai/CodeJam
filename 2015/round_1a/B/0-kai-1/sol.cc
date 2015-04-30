#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define B_MAX_SIZE 1001

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;

int B, N;
int Mk[B_MAX_SIZE];


// ------ Global Variables ------

long long greatest_common_divisor(const long long lhs, const long long rhs)
{
	// log_fs << ">>>>>>>>>>>>greatest_common_divisor(" << lhs << "," << rhs << ")" << endl;

	int large = lhs;
	int small = rhs;
	int temp;
        
	if (large < small)
                std::swap(large, small);
	while (0 != large % small) {
		temp = small;
		small = large % small;
		large = temp;
        }

	// log_fs << "<<<<<<<<<<<<greatest_common_divisor(" << lhs << "," << rhs << ") = " << small << endl;
	return small;
}

long long least_common_multiple(const long long lhs, const long long rhs)
{
	log_fs << ">>>>>>>>>>least_common_multiple(" << lhs << "," << rhs << ")" << endl;
	const int ret = lhs * rhs / greatest_common_divisor(lhs, rhs);
	log_fs << "<<<<<<<<<<least_common_multiple(" << lhs << "," << rhs << ") = " << ret << endl << endl;
	return ret;
}

int init_only_once()
{
	log_fs << ">>>>init_only_once()" << endl;
	log_fs << "<<<<init_only_once()" << endl << endl;
        return 0;
}

int handle_input()
{
	log_fs << ">>>>>>handle_input()" << endl;

	cin >> B >> N;

	// log_fs << ">>>>>>  B=" << B << "  N=" << N << endl;
        
	for (int i = 1; i <= B; i++)
		cin >> Mk[i];

	log_fs << "<<<<<<handle_input()" << endl << endl;        
        return 0;
}

int init_per_case()
{
	log_fs << ">>>>>>init_per_case()" << endl;

	log_fs << "<<<<<<init_per_case()" << endl << endl;
        return 0;
}

int get_lcm()
{
	log_fs << ">>>>>>>>get_lcm()" << endl;

	int lcm = 1;
	for (int iii = 1; iii <= B; iii++)
		lcm = least_common_multiple(lcm, Mk[iii]);
	log_fs << "<<<<<<<<get_lcm() = " << lcm << endl << endl;
	return lcm;
}

int get_count_T(const int lcm)
{
	log_fs << ">>>>>>>>get_count_T(" << lcm << ")" << endl;

	int count_T = 0;
	for (int iii = 1; iii <= B; iii++)
		count_T += lcm / Mk[iii];

	log_fs << "<<<<<<<<get_count_T(" << lcm << ") = " << count_T << endl << endl;
	return count_T;
}

int get_ans(const int lcm)
{
	log_fs << ">>>>>>>>get_ans(" << lcm << ")" << endl;
	
	int cnt_p = 0;
	for (int iii = 0; iii < lcm; iii++) {
		for (int jjj = 1; jjj <= B; jjj++) {
			if (0 == iii % Mk[jjj]) {
				cnt_p++;
                                if (cnt_p == N) {
	log_fs << "<<<<<<<<get_ans(" << lcm << ") = " << jjj << endl << endl;                                        
					return jjj;
                                }
                        }
                }
        }

	abort();
	return 0;
}

int run()
{
	log_fs << ">>>>>>run()" << endl;

	const int lcm = get_lcm();
	const int count_T = get_count_T(lcm);

	N = N % count_T;

	if (0 == N)
		N = count_T;

	log_fs << "<<<<<<  N=" << N << endl;        

	const int ans = get_ans(lcm);

	log_fs << "<<<<<<run() = " << ans << endl << endl;        
	return ans;
}

int main()
{
        log_fs.open("log.txt", std::fstream::out);
	log_fs << ">>main()" << endl << endl;

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;
		log_fs << "Case #" << tt << ": " << run_ret << endl;
        }

	log_fs << "<<main()" << endl;
	log_fs.close();
        return 0;
}

