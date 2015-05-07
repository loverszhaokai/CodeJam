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

#ifdef DBG
std::fstream log_fs;
#endif

int A,B,K;

// ------ Global Variables ------


// ====== Function declarations ======


// ------ Function declarations ------


int init_only_once()
{
#ifdef DBG
	log_fs << ">>>>init_only_once()" << endl;
	log_fs << "<<<<init_only_once()" << endl << endl;
#endif

        return 0;
}

int handle_input()
{
#ifdef DBG
	log_fs << ">>>>>>handle_input()" << endl;
#endif

	cin >> A >> B >> K;

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

	for (int iii = 0; iii < A; iii++) {
		for (int jjj = 0; jjj < B; jjj++) {
#ifdef DBG
                        log_fs << iii << "&" << jjj << "=" << (iii & jjj) << endl;
#endif
			if ((iii & jjj) < K) {
#ifdef DBG
	                        log_fs << "K=" << K << "    " << iii << "&" << jjj << "=" << (iii & jjj) << endl;
#endif
				ans++;
                        }
                }
        }

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

