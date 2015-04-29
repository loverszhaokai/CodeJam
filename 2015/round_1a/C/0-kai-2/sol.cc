#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>


#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define N_MAX_SIZE 3001
#define PI 3.14159265

double angle_arr[N_MAX_SIZE];

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

double angle_matrix[N_MAX_SIZE][N_MAX_SIZE];
int ans_matrix[N_MAX_SIZE][N_MAX_SIZE];

// ------ Global Variables ------

int init_only_once()
{
        return 0;
}

int handle_input()
{
	cin >> N;

	int x, y;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		points[i] = Point(x, y);
        }

        return 0;
}

void print_matrix()
{
	cout << "\n\tangle_matrix:" << endl;
	for (int iii = 1; iii <= N; iii++) {
		cout << "\t";
		for (int jjj = 1; jjj <= N; jjj++)
			cout << angle_matrix[iii][jjj] << "  ";
                cout << endl;
        }

	cout << "\n\tans_matrix:" << endl;
	for (int iii = 1; iii <= N; iii++) {
		cout << "\t";
		for (int jjj = 1; jjj <= N; jjj++)
			cout << ans_matrix[iii][jjj] << "  ";
                cout << endl;
        }
}

double get_angle(const struct Point &lhs, const struct Point &rhs)
{
	// cout << "lhs=(" << lhs.x << "," << lhs.y << ")" << endl;
	// cout << "rhs=(" << rhs.x << "," << rhs.y << ")" << endl;
        
	if (lhs.y < rhs.y) {
		if (lhs.x < rhs.x) {
			// First quadrant
			return atan((double)(rhs.y - lhs.y) / (double)(rhs.x - lhs.x));
                } else if (lhs.x == rhs.x) {
			return PI / 2;
                } else {
			// Second quadrant
			return PI + atan((double)(rhs.y - lhs.y) / (double)(rhs.x - lhs.x));
                }
        } else if (lhs.y == rhs.y) {
		if (lhs.x < rhs.x)
			return 0;
		else
			return PI;
	} else {
		if (lhs.x > rhs.x) {
			// Third quadrant
			return PI + atan((double)(rhs.y - lhs.y) / (double)(rhs.x - lhs.x));
                } else if (lhs.x == rhs.x) {
			return 3 * PI / 2;
                } else {
			// Fourth quadrant
			return 2 * PI + atan((double)(rhs.y - lhs.y) / (double)(rhs.x - lhs.x));
                }
        }
}

void init_angle_matrix()
{
	for (int iii = 1; iii <= N; iii++) {
		for (int jjj = 1; jjj <= N; jjj++) {
			if (iii == jjj)
				continue;
			// cout << "get_angle(" << iii << "," << jjj << ")" << endl;
			angle_matrix[iii][jjj] = get_angle(points[iii], points[jjj]);
			// cout << "angle_matrix[" << iii << "][" << jjj << "]=" << angle_matrix[iii][jjj] << "  ";
                }
		// cout << endl;
        }
}

int get_first_ans(const int end_index)
{
	int ans = N - 3;
	if (ans < 0)
		return 0;

	int first_index = 0;
	int next_first_index = 0;
	int second_index = -1;

	int count_points_on_the_same_edge = 0;
	int count_points_without_same_edge = 0;

	if (angle_arr[0] > PI)
		return ans;

        for (int iii = 0; iii < end_index; iii++) {
		if (angle_arr[0] == angle_arr[iii]) {
			next_first_index = iii + 1;
			count_points_on_the_same_edge++;
                } else if (PI + angle_arr[0] > angle_arr[iii]) {
			count_points_without_same_edge++;
                } else if (PI + angle_arr[0] == angle_arr[iii]) {
			count_points_on_the_same_edge++;
                } else {
			second_index = iii;
			break;
                }
        }

	count_points_on_the_same_edge++; // Add the point itself
	// cout << "count_points_without_same_edge=" << count_points_without_same_edge << endl;
	// cout << "count_points_on_the_same_edge=" << count_points_on_the_same_edge << endl;
        int cnt_ans = std::min(count_points_without_same_edge, 
		N - count_points_without_same_edge - count_points_on_the_same_edge);
	ans = std::min(ans, cnt_ans);

	if (-1 == second_index) {
		// cout << "return asn=" << ans << endl;
		return ans;
        }

	first_index = next_first_index;
        while (first_index < end_index && angle_arr[first_index] <= PI) {
		count_points_on_the_same_edge = 0;

	        for (int iii = first_index; iii < end_index; iii++) {
			if (angle_arr[first_index] == angle_arr[iii]) {
				next_first_index = iii + 1;
				count_points_on_the_same_edge++;
	                } else 
				break;
	        }

		for (int iii = second_index; iii < end_index; iii++) {
			second_index = iii;
			if (PI + angle_arr[first_index] == angle_arr[iii]) {
				count_points_on_the_same_edge++;
                        } else if (PI + angle_arr[first_index] < angle_arr[iii]) {
                                break;
                        }
                }

		if (PI + angle_arr[first_index] >= angle_arr[second_index]) {
			second_index = end_index;
                }

		count_points_without_same_edge = second_index - first_index - count_points_on_the_same_edge;
		count_points_on_the_same_edge++; // Add the point itself

		cnt_ans = std::min(count_points_without_same_edge, 
			N - count_points_without_same_edge - count_points_on_the_same_edge);
		ans = std::min(ans, cnt_ans);

		first_index = next_first_index;
        }
                
	return ans;
}

int get_second_ans(const int end_index)
{
	int ans = N - 3;
	if (ans < 0)
		return 0;

	int first_index = end_index - 1;
	int next_first_index = 0;
	int second_index = -2;

	int count_points_on_the_same_edge = 0;
	int count_points_without_same_edge = 0;

	if (angle_arr[first_index] < PI)
		return ans;

        for (int iii = first_index; iii > -1; iii--) {
		if (angle_arr[first_index] == angle_arr[iii]) {
			next_first_index = iii - 1;
			count_points_on_the_same_edge++;
                } else if (angle_arr[first_index] - PI < angle_arr[iii]) {
			count_points_without_same_edge++;
                } else if (angle_arr[first_index] - PI == angle_arr[iii]) {
			count_points_on_the_same_edge++;
                } else {
			second_index = iii;
			break;
                }
        }

	count_points_on_the_same_edge++; // Add the point itself
	int cnt_ans = std::min(count_points_without_same_edge, 
		N - count_points_without_same_edge - count_points_on_the_same_edge);

	ans = std::min(ans, cnt_ans);

	if (-2 == second_index) {
		return ans;
        }

	first_index = next_first_index;
        while (first_index > -1 && angle_arr[first_index] > PI) {
		count_points_on_the_same_edge = 0;

	        for (int iii = first_index; iii > -1; iii--) {
			if (angle_arr[first_index] == angle_arr[iii]) {
				next_first_index = iii - 1;
				count_points_on_the_same_edge++;
	                } else 
				break;
	        }

		for (int iii = second_index; iii > -1; iii--) {
			second_index = iii;
			if (angle_arr[first_index] - PI == angle_arr[iii]) {
				count_points_on_the_same_edge++;
                        } else if (angle_arr[first_index] - PI > angle_arr[iii]) {
                                break;
                        }
                }

		if (angle_arr[first_index] - PI <= angle_arr[second_index]) {
			second_index = -1;
                }

		count_points_without_same_edge = first_index - second_index - count_points_on_the_same_edge;
		count_points_on_the_same_edge++; // Add the point itself

		cnt_ans = std::min(count_points_without_same_edge, 
			N - count_points_without_same_edge - count_points_on_the_same_edge);
		ans = std::min(ans, cnt_ans);

		first_index = next_first_index;
        }
                
	return ans;
}

void print_ans(const int end_index)
{
	std::sort(angle_arr, angle_arr + end_index);

/*
	cout << "angle_arr=  ";
	for (int iii = 0; iii < end_index; iii++) {
		cout << angle_arr[iii] << "  ";
        }
	cout << endl;
*/

	const int ans_first = get_first_ans(end_index);
	const int ans_second = get_second_ans(end_index);

	// cout << "ans_first=" << ans_first << endl;
	// cout << "ans_second=" << ans_second << endl;

	const int ans = std::min(ans_first, ans_second);

        cout << ans << endl;
}

void init_ans_matrix()
{
	int index = 0;
        
	for (int iii = 1; iii <= N; iii++) {
                index = 0;
		for (int jjj = 1; jjj <= N; jjj++) {
			if (iii == jjj)
				continue;
			angle_arr[index++] = angle_matrix[iii][jjj];
                }
		print_ans(index);
        }
}

void init_matrix()
{
	init_angle_matrix();

	init_ans_matrix();

	// print_matrix();
}

int init_per_case()
{
	init_matrix();
        
        return 0;
}

int run()
{
	// cout << "run()" << endl;

	// print_matrix();

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

                cout << "Case #" << tt << ":" << endl;

                init_per_case();
        }


        return 0;
}

