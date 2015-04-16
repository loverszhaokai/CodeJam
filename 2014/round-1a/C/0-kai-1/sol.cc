#include <stdio.h>

#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define N_SIZE 1000

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

int N;
int arr[N_SIZE];
int lisl_count_arr[N_SIZE];

// ------ Global Variables ------


int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
        }

        return 0;
}

int init_per_case()
{
        return 0;
}

int get_longest_increase_sub_list_count()
{
	for (int i = 0; i < N; i++)
        	lisl_count_arr[i] = 0;

	lisl_count_arr[0] = 1;

	int longest_count = 0;

        for (int iii = 1; iii < N; iii++) {

		int longest = 1;

		for (int jjj = iii - 1; jjj >= 0; jjj--) {
			if (arr[iii] > arr[jjj])
				longest = std::max(longest, 1 + lisl_count_arr[jjj]);
                }

		lisl_count_arr[iii] = longest;
		longest_count = std::max(longest_count, longest);
        }

	return longest_count;
}

int run()
{
	// return get_longest_increase_sub_list_count();

	int count = 0;
	for (int iii = 0; iii < N; iii++) {
		if (arr[iii] > iii)
			count++;
        }

        // cout << count << endl;

	return count < (N / 2 + 16);
}

int main()
{
        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_ret = 0;

	int good_count = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": ";
                
		if (0 == run_ret)
			cout << "BAD" << endl;
                else {
			good_count++;
			cout << "GOOD" << endl;
                }
        }

	// cout << good_count << endl;

        return 0;
}

