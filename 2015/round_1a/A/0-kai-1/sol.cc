#include <stdio.h>

#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define N_MAX_SIZE 1001

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

int N;
int arr[N_MAX_SIZE];

int max_speed;
long long ret1, ret2;

// ------ Global Variables ------


int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
        
        return 0;
}

int init_per_case()
{
        return 0;
}

void get_first_result()
{
	int speed = 0;
        ret1 = 0;
	max_speed = 0;

	for (int i = 2; i <= N; i++) {
		speed = arr[i - 1] - arr[i];
		if (0 < speed) {
			ret1 += speed;
			max_speed = std::max(max_speed, speed);
                }
        }
}

void get_second_result()
{
	int add = 0;
        ret2 = 0;

	for (int i = 1; i <= N - 1; i++) {
		if (arr[i] <= max_speed)
			ret2 += arr[i];
		else
			ret2 += max_speed;
        }
}

int run()
{
	get_first_result();
	get_second_result();
        
        return 0;
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

                cout << "Case #" << tt << ": " << ret1 << " " << ret2 << endl;
        }


        return 0;
}

