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

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;

int N;
int D;
int H;
int M;

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

        cin >> N >> D >> H >> M;

        for (int iii = 0; iii < N; iii++) {

        }

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

#ifdef DBG
	log_fs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}



int run()
{
#ifdef DBG
	log_fs << ">>>>>>run()" << endl;
#endif

	int ans = 0;


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

                cout << "Case #" << tt << ": ";


		cout << endl;

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

