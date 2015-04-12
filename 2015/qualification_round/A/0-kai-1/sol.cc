#include <stdio.h>

#include <iostream>


using std::cin;
using std::cout;
using std::endl;


#define MAX_SIZE 1001

#define SHY_COUNT(i) (shy_aud_count[i] - '0')

// ====== Global Variables ======

int S_max;
char shy_aud_count[MAX_SIZE];


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
        scanf("%d", &S_max);
        scanf("%s", shy_aud_count);

        // printf("S_max=%d\n", S_max);
        // printf("shy_aud_count=%s\n", shy_aud_count);

        return 0;
}


int run()
{
        int standed_count = 0;
        int invited_count = 0;

        standed_count = SHY_COUNT(0);

        for (int i = 1; i <= S_max; i++) {
                if (standed_count < i) {
                        invited_count += i - standed_count;
                        standed_count += i - standed_count;
                }
                standed_count += SHY_COUNT(i);

                if (standed_count >= S_max)
                        break;
        }

        return invited_count;
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

