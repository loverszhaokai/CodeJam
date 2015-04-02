#include <stdio.h>

#include <algorithm>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define MAX_SIZE 1011

// ------ Defines ------



// ====== Global Variables ======

int N_per_case;

double naomi_mass[MAX_SIZE];
double ken_mass[MAX_SIZE];

// ------ Global Variables ------



int init_only_once()
{

        return 0;
}


int handle_input()
{
        cin >> N_per_case;

        for (int index = 1; index<= N_per_case; index++) {
                cin >> naomi_mass[index];
        }

        for (int index = 1; index<= N_per_case; index++) {
                cin >> ken_mass[index];
        }

        return 0;
}


int init_per_case()
{
        std::sort(naomi_mass, naomi_mass + N_per_case + 1);
        std::sort(ken_mass, ken_mass + N_per_case + 1);


        return 0;
}


int run_dwar()
{
        int naomi_index = 1;

        while (naomi_index <= N_per_case) {

                bool is_ok = true;
                const int interval = naomi_index - 1;
                
                for (int index = naomi_index; index <= N_per_case; index++) {

                        if (naomi_mass[index] < ken_mass[index - interval]) {
                                naomi_index++;
                                is_ok = false;
                                break;
                        }
                }

                if (is_ok) {
                        return N_per_case - naomi_index + 1;
                }
        }
        
        return 0;
}


int run_war()
{
        int naomi_index = 1;
        int ken_index = 1;

        while (naomi_index <= N_per_case && ken_index <= N_per_case) {

                if (naomi_mass[naomi_index] < ken_mass[ken_index]) {
                        naomi_index++;
                        ken_index++;
                } else {
                        ken_index++;
                }
        }

        return N_per_case - naomi_index + 1;
}


int main()
{
        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_war_ret = 0;
        int run_dwar_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_dwar_ret = run_dwar();
                run_war_ret = run_war();

                cout << "Case #" << tt << ": " << run_dwar_ret << " " << run_war_ret << endl;
                
        }


        return 0;
}

