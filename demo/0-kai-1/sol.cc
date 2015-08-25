#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

// ====== Defines ======


// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

#ifdef DBG
std::fstream logs;
#endif



// ------ Global Variables ------


void init_only_once()
{
#ifdef DBG
	logs << ">>>>" << __FUNCTION__ << "()" << endl;
#endif



#ifdef DBG
	logs << "<<<<" << __FUNCTION__ << "()" << endl << endl;;
#endif
}

void clear_global_variables()
{
#ifdef DBG
	logs << ">>>>" << __FUNCTION__ << "()" << endl;
#endif



#ifdef DBG
	logs << "<<<<" << __FUNCTION__ << "()" << endl << endl;;
#endif
}

void handle_input()
{
#ifdef DBG
	logs << ">>>>>>" << __FUNCTION__ << "()" << endl;
#endif



#ifdef DBG
	logs << "<<<<<<" << __FUNCTION__ << "()" << endl << endl;;
#endif
}


void init_per_case()
{
#ifdef DBG
	logs << ">>>>>>" << __FUNCTION__ << "()" << endl;
#endif



#ifdef DBG
	logs << "<<<<<<" << __FUNCTION__ << "()" << endl << endl;;
#endif
}


long long run()
{
#ifdef DBG
	logs << ">>>>>>" << __FUNCTION__ << "()" << endl;
#endif

	int ans = 0;



#ifdef DBG
	logs << "<<<<<<" << __FUNCTION__ << "() return " << ans << endl << endl;;
#endif
	return ans;
}


int main()
{
#ifdef DBG
	logs.open("log.txt", std::fstream::out);
	logs << ">>" << __FUNCTION__ << "()" << endl << endl;
#endif

	init_only_once();

	int total_cases_count = 0;
	cin >> total_cases_count;

	long long run_ret = 0;

	for (int tt = 1; tt <= total_cases_count; tt++) {

		clear_global_variables();

		handle_input();

		init_per_case();

		run_ret = run();

		cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		logs << "Case #" << tt << ": " << run_ret << endl;
#endif
	}


#ifdef DBG
	logs << "<<main()" << endl;
	logs.close();
#endif
	return 0;
}

