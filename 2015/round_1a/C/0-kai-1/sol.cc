#include <climits>
#include <stdio.h>

#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define N_MAX_SIZE 3001

// ------ Defines ------


// ====== Types ======

struct Point {

	Point() : x(0), y(0)
	{}

	Point(const int _x, const int _y) 
	{
		x = _x;
                y = _y;
        }
        
	int x;
	int y;
};

// ------ Types ------


// ====== Global Variables ======

int N;
struct Point points[N_MAX_SIZE];

int point_largest_y;

int edge_matrix[N_MAX_SIZE][N_MAX_SIZE];
double k_matrix[N_MAX_SIZE][N_MAX_SIZE];

struct Point points_ob[N_MAX_SIZE]; // points on the boundary

// ------ Global Variables ------


int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N;

	int largest_y = -1000000;

	int x, y;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		points[i] = Point(x, y);
		if (largest_y < y) {
			largest_y = y;
                        point_largest_y = i;
                }
        }

	cout << "largest_y=" << largest_y << endl;
	cout << "point_largest_y=" << point_largest_y << endl;

        return 0;
}

void print_matrix()
{
	cout << "\n\tedge_matrix:" << endl;
        
	for (int iii = 1; iii <= N; iii++) {
		cout << "\t";
		for (int jjj = 1; jjj <= N; jjj++)
			cout << edge_matrix[iii][jjj] << "  ";
                cout << endl;
        }

	cout << "\n\tk_matrix:" << endl;
	for (int iii = 1; iii <= N; iii++) {
		cout << "\t";
		for (int jjj = 1; jjj <= N; jjj++)
			cout << k_matrix[iii][jjj] << "  ";
                cout << endl;
        }
}

inline double get_k(const struct Point &lhs, const struct Point &rhs)
{
	if (lhs.x == rhs.x)
		return (double)INT_MAX;
	if (lhs.y == rhs.y)
		return (double)0;
	return ((double)(lhs.y - rhs.y)) / ((double)(lhs.x - rhs.x));
}

void get_new_vertex(const int point_id)
{
	double largest_k;
	double smallest_k;
        
	for (int i = 1; i <= N; i++) {
		if (point_id == i)
			continue;

        }
}

void init_k_matrix()
{
	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			if (iii == jjj)
				continue;
			k_matrix[iii][jjj] = get_k(points[iii], points[jjj]);
                }
        }
}

void fun(const double pre_k, const int pre_point_id)
{
	
}

void init_edge_matrix()
{

}

void init_matrix()
{
	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			k_matrix[iii][jjj] = 0;
			edge_matrix[iii][jjj] = 0;
                }
        }

	init_k_matrix();

	print_matrix();
}

int init_per_case()
{
	init_matrix();
        
        return 0;
}

int run()
{
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

                cout << "Case #" << tt << ": " << "something" << endl;
                
        }


        return 0;
}

