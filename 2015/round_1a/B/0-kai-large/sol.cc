#include <cmath>
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

int get_count_at_time(const long long _time)
{
	int count = 0;
	for (int iii = 1; iii <= B; iii++)
		count += 1 + _time / Mk[iii];
	return count;
}

long long get_cnt_time(const long long low_time, const long long high_time)
{
// log_fs << ">>>>>>>>>>get_cnt_time(" << low_time << "," << high_time << ")" << endl;

	if (low_time > high_time)
		abort();
	if (low_time == high_time - 1 || low_time == high_time) {
// log_fs << "<<<<<<<<<<get_cnt_time(" << low_time << "," << high_time << ") = " << high_time << endl;
		return high_time;
        }
        
	const long long middle_time = (high_time + low_time) / 2;
	const int count = get_count_at_time(middle_time);

        if (N <= count)
		return get_cnt_time(low_time, middle_time);
	return get_cnt_time(middle_time, high_time);
}

long long get_cnt_time()
{
	log_fs << ">>>>>>>>get_cnt_time()" << endl;

	int time_2_low_pow = 0;

	if (N <= B)
		return 0;

	long long high_time = 0;
	long long low_time = 0;
	long long cnt_time = 0;
	int count = 0;
        
        while (true) {
		cnt_time = (long long)pow(2.0, time_2_low_pow);
		count = get_count_at_time(cnt_time);

		log_fs << "<<<<<<<<cnt_time=" << cnt_time << endl;
		log_fs << "<<<<<<<<count=" << count << endl;
		log_fs << "<<<<<<<<N=" << N << endl;

		if (count >= N) {
			high_time = cnt_time;
			if (0 == time_2_low_pow)
				low_time = 0;
                        else
				low_time = (int)pow(2.0, time_2_low_pow - 1);
			break;
                }
		time_2_low_pow++;
        }

	log_fs << "<<<<<<<<low_time=" << low_time << endl;
	log_fs << "<<<<<<<<high_time=" << high_time << endl;

	cnt_time = get_cnt_time(low_time, high_time);
	log_fs << ">>>>>>>>get_cnt_time(" << low_time << "," << high_time << ")=" << cnt_time << endl;
	log_fs << "<<<<<<<<get_cnt_time()" << endl;
        return cnt_time;
}

int run()
{
	log_fs << ">>>>>>run()" << endl;

	int ans = 0;

	const long long cnt_time = get_cnt_time();
	long long pre_time = cnt_time - 1;
	int count = 0;

	if (-1 == pre_time)
		count = 0;
	else
		count = get_count_at_time(pre_time);

	for (int iii = 1; iii <= B; iii++) {
		if (0 == cnt_time % Mk[iii]) {
			count++;
                        if (count == N) {
                                ans = iii;
				break;
                        }
                }
        }

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

