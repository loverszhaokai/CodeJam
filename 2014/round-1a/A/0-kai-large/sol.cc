#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

// ====== Defines ======

#define N_MAX_SIZE 151
#define L_MAX_SIZE 41

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

int N;
int L;

string cnt_ele_flow[N_MAX_SIZE];
string exp_ele_flow[N_MAX_SIZE];

vector<int> matrix[N_MAX_SIZE][N_MAX_SIZE];

char has_found[N_MAX_SIZE];

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

        std::sort(cnt_ele_flow + 1, cnt_ele_flow + N + 1);
        std::sort(exp_ele_flow + 1, exp_ele_flow + N + 1);

/*
	cout << "cnt_ele_flow: ";
	for (int i = 1; i <= N; i++)	        
		cout << cnt_ele_flow[i] << "\t";
	cout << endl << endl;

	cout << "exp_ele_flow: ";
	for (int i = 1; i <= N; i++)	        
		cout << exp_ele_flow[i] << "\t";
	cout << endl << endl;
*/

        return 0;
}

vector<int> get_flipped_pos(const int cnt_pos, const int exp_pos)
{
	vector<int> ret;
	for (int i = 0; i < L; i++) {
		if (cnt_ele_flow[cnt_pos][i] != exp_ele_flow[exp_pos][i])
			ret.push_back(i);
        }
	return ret;
}

int init_per_case()
{
	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++)
			matrix[iii][jjj] = get_flipped_pos(iii, jjj);
        }

/*
	cout << "\tmatrix=" << endl;

	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			cout << "\t";
			for (int kkk = 0; kkk < matrix[iii][jjj].size(); kkk++) {
				cout << matrix[iii][jjj][kkk] << " ";
                        }
			cout << "    ";
                }
		cout << endl;
        }
*/

        return 0;
}

int is_same()
{
	for (int i = 1; i <= N; i++) {
		if (exp_ele_flow[i] != cnt_ele_flow[i])
			return false;
        }
	return true;
}

int run()
{
	if (is_same()) {
		return 0;
	}

	if (1 == N)
		return matrix[1][1].size();

	int min_num = L_MAX_SIZE;
	vector<int> flipped_pos;
	bool has_same_flipped_pos;

	for (int iii = 1; iii <= N; iii++) {

                // cout << "iii=" << iii << endl;

		memset(has_found, 0, N_MAX_SIZE);
		has_found[iii] = 1;
		flipped_pos = matrix[1][iii];

		for (int jjj = 2; jjj <= N; jjj++) {
			has_same_flipped_pos = false;
			for (int kkk = 1; kkk <= N; kkk++) {
				if (flipped_pos == matrix[jjj][kkk]) {
					if (0 == has_found[kkk]) {
                                                // cout << "\tjjj=" << jjj << endl;
						has_found[kkk] = 1;                                                
						has_same_flipped_pos = true;
                                        }
					break;
                                }
                        }
			if (!has_same_flipped_pos)
				break;
                }

		if (has_same_flipped_pos) {
			min_num = std::min(min_num, (int)flipped_pos.size());
/*
			cout << "flipped_pos: ";
			for (int i = 0; i < flipped_pos.size(); i++) {
				cout << flipped_pos[i] << " ";
                        }
			cout << endl;
*/
                }
                
        }

	if (L_MAX_SIZE == min_num)
	        return -1;
	return min_num;
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

