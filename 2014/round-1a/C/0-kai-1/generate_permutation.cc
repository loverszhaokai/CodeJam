#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::map;
using std::vector;

#define MAX_SIZE 10000000
#define N_MAX_SIZE 1001

int arr[N_MAX_SIZE];

map<vector<int>, int> count;

struct SC {
        int count;
	map<vector<int>, int>::const_iterator it;
	int longest_increase_sub_list_count;
};

SC sc[MAX_SIZE];

int get_longest_increase_sub_list_count(const vector<int> &arr)
{
	vector<int> li_sub_list(arr.size(), 0);

	li_sub_list[0] = 1;

	int li_sub_list_count = 0;

        for (int iii = 1; iii < arr.size(); iii++) {

		int longest = 1;

		for (int jjj = iii - 1; jjj >= 0; jjj--) {
			if (arr[iii] > arr[jjj])
				longest = std::max(longest, 1 + li_sub_list[jjj]);
                }

		li_sub_list[iii] = longest;
		li_sub_list_count = std::max(li_sub_list_count, longest);
        }

	return li_sub_list_count;
}

bool is_larger(const struct SC lhs, const struct SC rhs)
{
	return lhs.count > rhs.count;
}

void print_count()
{
	// cout << endl << "\tcount=" << endl;
        
	int index = 0;
	map<vector<int>, int>::const_iterator cit = count.begin();

        while (count.end() != cit) {

/*
		cout << "\t\tarr= ";
		for (int i = 0; i < cit->first.size(); i++) {
			cout << cit->first[i] << " ";
                }

		cout << "count= " << cit->second << endl;
*/

		sc[index].count = cit->second;
		sc[index].it = cit;
		sc[index].longest_increase_sub_list_count = 
			get_longest_increase_sub_list_count(cit->first);

		cit++;
		index++;
        }

        std::sort(sc, sc + index, is_larger);

	for (int i = 0; i < index; i++) {
		cout << "\tcount= " << sc[i].count << "  arr= ";
                for (int j = 0; j < (sc[i].it->first).size(); j++) {
			cout << sc[i].it->first[j] << " ";
                }
		cout << "  li= " << sc[i].longest_increase_sub_list_count << endl;
        }
}

void print_num_count(const map<int, int> &_num_count)
{
	cout << endl << "\tnum_count=" << endl;
	map<int, int>::const_iterator cit = _num_count.begin();

        while (_num_count.end() != cit) {
		cout << "\t\t[" << cit->first << "]=\t" << cit->second << endl;
		cit++;
        }
	cout << endl;
}

int rand_int(const int left, const int right)
{
	if (left > right)
		return 0;
	const int step = right - left;
	return rand() % step + left;
}

void bad_algorithm(const int N)
{
	for (int i = 0; i < N; i++)
		arr[i] = i;

	int p;
	for (int i = 0; i < N; i++) {
		p = rand_int(0, N);
                std::swap(arr[i], arr[p]);
	}
}

void run()
{
	srand(time(NULL));

	int larger_than_500_count = 0;
	int larger_than_510_count = 0;
	int larger_than_520_count = 0;

	int i = 0;
	while (i++ < 30000) {
		bad_algorithm(1000);

		int count = 0;
		for (int iii = 0; iii < 1000; iii++) {
			if (iii < arr[iii])
				count++;
                }

		if (count > 500)
			larger_than_500_count++;

		if (count > 510)
			larger_than_510_count++;

		if (count > 520)
			larger_than_520_count++;

		cout << "count=" << count << "  ";
        }
	cout << endl;
	cout << endl;

	cout << "larger_than_500_count=" << larger_than_500_count << endl;
	cout << "larger_than_510_count=" << larger_than_510_count << endl;
	cout << "larger_than_520_count=" << larger_than_520_count << endl;
	cout << "<= 50           count=" << 30000 - larger_than_500_count << endl;

	// print_count();
	// print_num_count(num_10_count);
	// print_num_count(num_15_count);
	// print_num_count(num_20_count);
}

int main()
{
	run();

	return 0;
}

