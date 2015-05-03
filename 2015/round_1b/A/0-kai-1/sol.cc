#include <climits>
#include <cmath>
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
using std::string;


// ====== Defines ======

#define DBG

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;

long long N;
char str[20];

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

	cin >> N;
	sprintf(str, "%lld", N);

#ifdef DBG

	log_fs << "N=" << N << endl;
	log_fs << "str=" << str << endl;
	log_fs << "strlen(str)=" << strlen(str) << endl;

	log_fs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	log_fs << ">>>>>>init_per_case()" << endl;
#endif


#ifdef DBG
	log_fs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

long long get_ans()
{
	log_fs << ">>>>>>>>get_ans()" << endl;
	log_fs << "N=" << N << endl;

	long long ans = 0;
	if (N <= 10) {
                
		ans = N;

        }
        else if (0 == N % 10) {
		// N = ****0
		N--;
		sprintf(str, "%lld", N);
                ans = 1 + get_ans();

        } else {
		// N = ****
		const int half_index = strlen(str) / 2;

		ans += str[0] - '1';
		ans += str[strlen(str) - 1] - '1';

		int temp = 0;
	        for (int iii = 1; iii < half_index; iii++) {
			temp += pow(10.0, iii) * (str[iii] - '0');
	        }

		if ('1' == str[0] && 0 == temp) {
			// Donot need reverse
                } else {
			ans += 1 + temp;
                }

	        for (int iii = 1; iii < strlen(str) - half_index; iii++) {
			ans += pow(10.0, iii) * (str[strlen(str) - iii - 1] - '0');
	        }

		ans += 1;
                
		N = pow(10.0, strlen(str) - 1);
		sprintf(str, "%lld", N);

		ans += get_ans();
        }


	log_fs << "N=" << N << endl;
	log_fs << "ans=" << ans << endl;
	return ans;
}


long long run()
{
#ifdef DBG
	log_fs << ">>>>>>run()" << endl;
#endif

	long long ans = get_ans();

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

        long long run_ret = 0;

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

