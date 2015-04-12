#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

#define ARR_MAX_SIZE 1010


// ====== Global Variables ======

int arr[ARR_MAX_SIZE];
int D;

int largest_p;

// ------ Global Variables ------

int init_only_once()
{
        return 0;
}

int handle_input()
{
        largest_p = 0;

        cin >> D;
        for (int i = 0; i < D; i++) {
                cin >> arr[i];
                largest_p = std::max(largest_p, arr[i]);
        }

        return 0;
}

int init_per_case()
{
        return 0;
}

void print_arr()
{
        cout << "===print_arr=" << endl;
        for (int i = 0; i < D; i++)
                cout << arr[i] << " ";
        cout << endl;
}

int run()
{
        // cout << "largest_p=" << largest_p << endl;
        if (3 >= largest_p)
                return largest_p;

        int total_minutes;
        int smallest_total_minutes = largest_p;

        for (int iii = 2; iii <= largest_p; iii++) {
                int count_diners = 0;
                for (int jjj = 0; jjj < D; jjj++) {
                        count_diners += arr[jjj] / iii;
                        if (0 != arr[jjj] % iii)
                                count_diners++;
                }
                total_minutes = (count_diners - D) + iii;
                smallest_total_minutes = std::min(smallest_total_minutes, total_minutes);
                // cout << "iii=" << iii << " count_diners=" << count_diners 
                // << " total_minutes=" << total_minutes
                // << " smallest_total_minutes=" << smallest_total_minutes << endl;
                if (iii >= smallest_total_minutes)
                        break;
        }

        return smallest_total_minutes;
}


int main()
{
        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;
        }


        return 0;
}

