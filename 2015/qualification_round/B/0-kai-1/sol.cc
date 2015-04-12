#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

#define ARR_MAX_SIZE 1000010


// ====== Global Variables ======

int arr[ARR_MAX_SIZE];
int arr_last_index;

int D;

int count[1010][2];
int total_3_count;
int total_2_count;

// ------ Global Variables ------

void calculate(const int num)
{
        int r;
        for (int i = 0; i <= num / 2; i++) {
                r = num - i * 2;
                if (0 == r % 3) {
                        count[num][0] = r / 3;
                        count[num][1] = i;
                        return;
                }
        }

        abort();
}

int init_only_once()
{
        count[1][0] = 0;
        count[1][1] = 1;

        for (int i = 2; i <= 1000; i++) {
                calculate(i);
        }

        return 0;
}

int init_per_case()
{
        return 0;
}

int handle_input()
{
        cin >> D;
        arr_last_index = D;
        total_3_count = 0;
        total_2_count = 0;

        for (int i = 0; i < D; i++) {
                cin >> arr[i];
                total_3_count += count[arr[i]][0];
                total_2_count += count[arr[i]][1];
        }

        return 0;
}

void print_arr()
{
        cout << "===print_arr=" << endl;
        for (int i = 0; i < arr_last_index; i++)
                cout << arr[i] << " ";
        cout << endl;
}

bool is_larger(int i, int j)
{
        return i > j;
}

int run_1()
{
        std::sort(arr, arr + D, is_larger);
        // print_arr();

        int total_minutes = arr[0];
        int smallest_total_minutes = total_minutes;

        if (3 >= smallest_total_minutes)
                return smallest_total_minutes;

        int i = 1;
        
        while (true) {

                if (3 >= arr[0])
                        return smallest_total_minutes;

                if (i > smallest_total_minutes)
                        return smallest_total_minutes;

                if (0 == arr[0] % 2) {
                        arr[0] /= 2;
                        arr[arr_last_index++] = arr[0];
                } else {
                        arr[0] = arr[0] / 2 + 1;
                        arr[arr_last_index++] = arr[0] - 1;
                }
                
                std::sort(arr, arr + arr_last_index, is_larger);

                // print_arr();
                total_minutes = i + arr[0];
                smallest_total_minutes = std::min(smallest_total_minutes, total_minutes);

                i++;
        }

        abort();
        return 0;
}

int run_2()
{
        return total_3_count + total_2_count - D + (0 == total_3_count ? 2 : 3);
}

int run()
{
        return std::min(run_1(), run_2());
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
                // cout << endl;
        }


        return 0;
}

