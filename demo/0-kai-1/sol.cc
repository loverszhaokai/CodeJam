#include <stdio.h>

#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Global Variables ======






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

