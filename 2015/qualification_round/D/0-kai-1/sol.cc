#include <stdio.h>
#include <stdlib.h>

#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Global Variables ======

int X, R, C;


// ------ Global Variables ------



int init_only_once()
{

        return 0;
}


int init_per_case()
{

        return 0;
}

int handle_input()
{
        cin >> X >> R >> C;

        return 0;
}


// Return 0 if GABRIEL
// Return 1 if RICHARD
// 
// 1. Return 1 if (X > R && X > C)
//
// 2. Return 1 if (0 != (R * C) % X), since there is no way to fill
// completely
// 
// 3. Return 0 if 1 == X or 2 == X or 3 == X
// 
// 4. When 4 == X
// 
//   4.1 Return 1 if 1 == R or 1 == C or 2 == R or 2 == C
//
//   4.2 Return 0 
// 
// 
int run()
{
        if (X > R && X > C)
                return 1;

        if (0 != (R * C) % X)
                return 1;

        if (1 == X || 2 == X)
                return 0;
        else if (3 == X) {
                if (1 == R || 1 == C)
                        return 1;
                return 0;
        } else if (4 == X) {
                if (1 == R || 1 == C || 2 == R || 2 == C)
                        return 1;
                return 0;
        } else {
                abort();
                return 1;
        }
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

                // if (3 == X)
                // cout << "X=" << X << " R=" << R << " C=" << C << endl;

                cout << "Case #" << tt << ": ";
                
                if (0 == run_ret)
                        cout << "GABRIEL" << endl;
                else 
                        cout << "RICHARD" << endl;
        }


        return 0;
}

