#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;

using std::string;


// ====== Defines ======

#define N_MAX_SIZE 151
#define L_MAX_SIZE 41

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

int N;
int L;

int combination[L_MAX_SIZE];
int c_size;

string cnt_ele_flow[N_MAX_SIZE];
string exp_ele_flow[N_MAX_SIZE];

string new_ele_flow[N_MAX_SIZE];

// ------ Global Variables ------


int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N >> L;

	for (int i = 1; i <= N; i++)
		cin >> cnt_ele_flow[i];
	        
	for (int i = 1; i <= N; i++)
		cin >> exp_ele_flow[i];

        std::sort(exp_ele_flow + 1, exp_ele_flow + N + 1);

/*
	cout << "exp_ele_flow: ";
	for (int i = 1; i <= N; i++)	        
		cout << exp_ele_flow[i] << "\t";
	cout << endl << endl;
*/

        return 0;
}

int init_per_case()
{
	for (int i = 1; i <= N; i++)
		new_ele_flow[i] = cnt_ele_flow[i];
        
        return 0;
}

// e.g.
// c_size == 3, pos == 2
// 
// The first combination : 1    2    3
// The second combination: 1    2    4
// ...
// The last combination  : L-2  L-1  L
// 
// The last value of pos 2 is: L-1
//
inline int cnt_pos_is_last(const int pos)
{
	return L - c_size + pos == combination[pos];
}

// Return 0 if not
// Return 1 otherwise
int is_last()
{
	for (int i = 1; i <= c_size; i++) {
		if (!cnt_pos_is_last(i))
			return 0;
        }
	return 1;
}

// 
// Update values of combination from @(pos + 1) to the end
// 
// e.g.
// c_size = 5, L = 10
// 
// The first combination : 1 2 3 4  5
// The second combination: 1 2 3 4  6
// ...
// The 6th combination   : 1 2 3 4  10
// The 7th combination   : 1 2 3 5  6
// ...
// The 21th combination  : 1 2 3 9  10
// 
// update_after_pos(3)
// 
// The 22th combination  : 1 2 4 5  6
void update_after_pos(const int pos)
{
	for (int i = pos + 1; i <= c_size; i++)
		combination[i] = combination[i - 1] + 1;
}

int get_next_combination()
{
	if (is_last()) {
		if (L == c_size)
			return -1; // Current combination is the end
		else {
			c_size++;
			for (int i = 1; i <= c_size; i++)
				combination[i] = i;
			return 0;
                }
        }

	for (int i = c_size; i >= 1; i--) {
		if (!cnt_pos_is_last(i)) {
			combination[i]++;
			update_after_pos(i);
			break;
                }
        }

	return 0;
}

void init_combination()
{
	c_size = 1;
	combination[1] = 1;
}

void flip()
{
	for (int i = 1; i <= N; i++)
		new_ele_flow[i] = cnt_ele_flow[i];

	int pos;

	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= c_size; jjj++) {
			pos = combination[jjj] - 1;
			if ('0' == new_ele_flow[iii][pos])
				new_ele_flow[iii][pos] = '1';
			else
				new_ele_flow[iii][pos] = '0';
                }
        }
}

int is_same()
{
	for (int i = 1; i <= N; i++) {
		if (exp_ele_flow[i] != new_ele_flow[i])
			return false;
        }
	return true;
}

int run()
{
	std::sort(new_ele_flow + 1, new_ele_flow + N + 1);
	if (is_same()) {
		return 0;
	}

	init_combination();
	do {
/*
		cout << "\tflip bits : ";
		for (int i = 1; i <= c_size; i++) {
			cout << combination[i] << " ";
                }
		cout << endl;
*/

		flip();

		std::sort(new_ele_flow + 1, new_ele_flow + N + 1);

/*
		cout << "\tafter flip: ";
                for (int i = 1; i <= N; i++) {
			cout << "[" << i << "]=" << new_ele_flow[i] << "  ";
                }
		cout << endl;
*/

		if (is_same()) {
			return c_size;
                }
                
        } while (-1 != get_next_combination());

        return -1;
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

                cout << "Case #" << tt << ": ";

		if (-1 == run_ret)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << run_ret << endl;
        }

        return 0;
}

