#include <climits>
#include <cstring>
#include <cstdio>

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

char points_id_ob[N_MAX_SIZE]; // points on the boundary

// ------ Global Variables ------

void get_next_vertex(const int pre_point_id, const int cnt_point_id);


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
	if (lhs.y == rhs.y)
		return (double)0;
	return ((double)(lhs.y - rhs.y)) / ((double)(lhs.x - rhs.x));
}

void init_k_matrix()
{
	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			if (iii == jjj || points[iii].x == points[jjj].x)
				k_matrix[iii][jjj] = 0;
			else
				k_matrix[iii][jjj] = get_k(points[iii], points[jjj]);
                }
        }
}

// 
// next_k: is the first k in (-oo, +oo)
// 
void get_next_vertex_vertical(const int cnt_point_id)
{
	bool first_time = true;
	int next_point_id = -1;
	double temp_k;
	double smallest_k;
        
	for (int iii = 1; iii <= N; iii++) {
		if (1 == edge_matrix[cnt_point_id][iii])
			continue;
		if (cnt_point_id == iii)
			continue;

		if (points[cnt_point_id].x == points[iii].x) {
                        next_point_id = iii;
			break;
                }

		temp_k = k_matrix[cnt_point_id][iii];

		if (first_time) {
			smallest_k = temp_k;
                        first_time = false;
			next_point_id = iii;
                }

		if (smallest_k > temp_k) {
			smallest_k = temp_k;
                        next_point_id = iii;
                }
        }

	if (-1 == next_point_id)
		return;

	points_id_ob[next_point_id] = 1;
	edge_matrix[cnt_point_id][next_point_id] = 1;
	edge_matrix[next_point_id][nct_point_id] = 1;

	get_next_vertex(cnt_point_id, next_point_id);
}

// 
// next_k: is the first k in [pre_k, +oo), vertical line, (-oo, pre_k)
// 
void get_next_vertex(const int pre_point_id, const int cnt_point_id)
{
	if (points[pre_point_id].x == points[cnt_point_id].x)
		get_next_vertex_vertical(cnt_point_id);

	bool has_k_1 = false;
        bool has_k_2 = false;
        bool has_k_3 = false;

	int next_point_id = -1;

	const double pre_k = k_matrix[pre_point_id][cnt_point_id];
	double temp_k;
	double smallest_k_1;
	double smallest_k_3;
        
	for (int iii = 1; iii <= N; iii++) {
		if (1 == points_id_ob[iii])
			continue;
		if (cnt_point_id == iii)
			continue;
		if (points[cnt_point_id].x == points[iii].x) {
			has_k_2 = true;
			if (!has_k_1)
				next_point_id = iii;
                } else {
			temp_k = k_matrix[cnt_point_id][iii];

			if (temp_k >= pre_k) {
				if (!has_k_1) {
					smallest_k_1 = temp_k;
					has_k_1 = true;
					next_point_id = iii;
                                }
				if (smallest_k_1 > temp_k) {
					smallest_k_1 = temp_k;
					next_point_id = iii;
                                }
                        }

			if (temp_k < pre_k && !has_k_1 && !has_k_2) {
				if (!has_k_3) {
					smallest_k_3 = temp_k;
					has_k_3 = true;
                                }
				if (smallest_k_3 > temp_k) {
					smallest_k_3 = temp_k;
                                        next_point_id = iii;
                                }
                        }
                }
        }

	if (!has_k_1 && !has_k_2 && !has_k_3)
		return;

	points_id_ob[next_point_id] = 1;
	edge_matrix[cnt_point_id][next_point_id] = 1;
	edge_matrix[next_point_id][nct_point_id] = 1;
	get_next_vertex(cnt_point_id, next_point_id);
}

void init_edge_matrix()
{
	memset(points_id_ob, 0, sizeof(points_id_ob));



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

