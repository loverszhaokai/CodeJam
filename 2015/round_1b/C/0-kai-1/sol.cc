#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::pair;
using std::make_pair;


// ====== Defines ======

#define HIKER_MAX_SIZE 500001

// ------ Defines ------


// ====== Types ======

struct HikerInfo {

        HikerInfo() {}

        HikerInfo(const int _d, const int _m) : d(_d), m(_m), is_first_circle(1) {}

        int d;
        int m;
	int is_first_circle;
};

// ------ Types ------


// ====== Global Variables ======

#ifdef DBG
std::fstream log_fs;
#endif

set<pair<long long, int> > time_id;

int h_arr_size;
HikerInfo h_arr[HIKER_MAX_SIZE];

// ------ Global Variables ------


// ====== Function declarations ======

void print_array(const int array[], const char *array_name, const int array_size);
void print_map(const set<pair<long long, int> > &sk);

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

	int N, D, H, M;
	long long time_to_end;

        cin >> N;

	h_arr_size = 0;
	time_id.clear();

        for (int iii = 0; iii < N; iii++) {
		cin >> D >> H >> M;
		for (int jjj = 0; jjj < H; jjj++) {
			h_arr[h_arr_size] = HikerInfo(D, M + jjj);
			time_to_end = (long long)(360 - D) * (long long)(M + jjj);
			time_id.insert(make_pair(time_to_end, h_arr_size));
                        h_arr_size++;
                }
        }

#ifdef DBG
        log_fs << endl;
	for (int iii = 0; iii < h_arr_size; iii++) {
		log_fs << "\th_arr[" << iii << "]=\t" << h_arr[iii].d << "\t" << h_arr[iii].m << endl;
        }
        log_fs << endl;

        print_map(time_id);

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

	int ans = h_arr_size;

        if (1 == h_arr_size)
		return 0;

	int cnt_ans = h_arr_size;
	long long time_to_end;
	long long next_circle_time_to_end;
	int h_id;
	set<pair<long long, int> >::iterator it;

	while (cnt_ans <= 2 * h_arr_size) {
		it = time_id.begin();
		time_to_end = (*it).first;

                set<pair<long long, int> >::iterator temp_it;
                while(true) {
                        temp_it = time_id.begin();
			h_id = temp_it->second;
			if (time_to_end == temp_it->first) {
		                if (1 == h_arr[h_id].is_first_circle) {
					h_arr[h_id].is_first_circle = 0;
					cnt_ans--;
		                } else {
					cnt_ans++;
		                }
                        } else {
				break;
                        }

			time_id.erase(temp_it);
			next_circle_time_to_end = time_to_end + 360 * (long long)h_arr[h_id].m;
	                time_id.insert(make_pair(next_circle_time_to_end, h_id));
                }

		ans = std::min(ans, cnt_ans);

                print_map(time_id);
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

#ifdef DBG
		log_fs << endl << "======Case #" << tt << endl << endl;
#endif

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

void print_map(const set<pair<long long, int> > &sk)
{
#ifdef DBG
        log_fs << "\tprint_map=" << endl;

	set<pair<long long, int> >::const_iterator it = sk.begin();

	while (sk.end() != it) {
		log_fs << "\t\t[" << (*it).first << ", " << (*it).second << "]" << endl;
                it++;
        }

	log_fs << endl << endl;
#endif
}

