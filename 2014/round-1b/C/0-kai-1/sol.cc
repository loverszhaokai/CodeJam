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


// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;


// ------ Global Variables ------


// ====== Function declarations ======


// ------ Function declarations ------


int init_only_once()
{
	log_fs << ">>>>init_only_once()" << endl;
	log_fs << "<<<<init_only_once()" << endl << endl;

        return 0;
}

int handle_input()
{
	log_fs << ">>>>>>handle_input()" << endl;
	log_fs << "<<<<<<handle_input()" << endl << endl;

        return 0;
}

int init_per_case()
{
	log_fs << ">>>>>>init_per_case()" << endl;

	log_fs << "<<<<<<init_per_case()" << endl << endl;

        return 0;
}

int run()
{
	log_fs << ">>>>>>run()" << endl;

	int ans = 0;


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

                cout << "Case #" << tt << ": ";


		cout << endl;

		log_fs << "Case #" << tt << ": " << run_ret << endl;
        }


	log_fs << "<<main()" << endl;
	log_fs.close();
        return 0;
}

