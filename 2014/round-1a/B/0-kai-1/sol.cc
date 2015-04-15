#include <stdio.h>

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

int matrix[N_MAX_SIZE][N_MAX_SIZE];


// ------ Global Variables ------

void print_matrix()
{
	cout << endl;
	cout << "\tprint_matrix()" << endl;

	for (int iii = 0; iii <= N; iii++) {
		cout << "\t\t";
		for (int jjj = 1; jjj <= N; jjj++)
			cout << matrix[iii][jjj] << "\t";
		cout << endl;
        }
	cout << endl;
}

int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N;

	int a, b;

	for (int iii = 1; iii <= N; iii++)
		for (int jjj = 1; jjj <= N; jjj++)
			matrix[iii][jjj] = 0;

	for (int i = 1; i <= N; i++)
		matrix[0][i] = -1;

	for (int i = 1; i <= N - 1; i++) {
		cin >> a >> b;
                matrix[a][b] = -1;
                matrix[b][a] = -1;
        }

	// print_matrix();
        
        return 0;
}

int get_max_children(const int parent_node, const int cnt_node)
{
	int largest = 0;
        int larger = 0;
        
	for (int iii = 1; iii <= N; iii++) {
		if (parent_node == iii || 0 == matrix[cnt_node][iii])
			continue;

		if (-1 == matrix[cnt_node][iii])
			matrix[cnt_node][iii] = get_max_children(cnt_node, iii);

		if (matrix[cnt_node][iii] > largest) {
			larger = largest;
                        largest = matrix[cnt_node][iii];
                } else if (matrix[cnt_node][iii] > larger) {
			larger = matrix[cnt_node][iii];
                }
        }

	if (0 == larger)
		return 1;
	return 1 + larger + largest;
}

void init_matrix()
{
	for (int iii = 0; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			if (-1 == matrix[iii][jjj]) {
                                // Recalculate
				matrix[iii][jjj] = get_max_children(iii, jjj);
                        }
                }
        }
}

int init_per_case()
{
	init_matrix();
        return 0;
}

int run()
{
	// print_matrix();

	int max_nodes = 0;
        
	for (int iii = 1; iii <= N; iii++)
		max_nodes = std::max(max_nodes, matrix[0][iii]);
        
        return N - max_nodes;
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

