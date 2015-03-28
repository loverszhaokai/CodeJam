#include <iostream>

using namespace std;

int useless;

int first_row;
int second_row;

int first_row_arr[4];
int second_row_arr[4];


void input()
{
        cin >> first_row;

        for (int row = 0; row < 4; ++row) {
                for (int line = 0; line < 4; ++line) {
                        if (row + 1 == first_row)
                                cin >> first_row_arr[line];
                        else 
                                cin >> useless;
                }
        }

        cin >> second_row;

        for (int row = 0; row < 4; ++row) {
                for (int line = 0; line < 4; ++line) {
                        if (row + 1 == second_row)
                                cin >> second_row_arr[line];
                        else 
                                cin >> useless;
                }
        }
}


int run()
{
        int card_number = 0;

        for (int first_line = 0; first_line < 4; ++first_line) {
                for (int second_line = 0; second_line < 4; ++second_line) {
                        if (first_row_arr[first_line] == second_row_arr[second_line]) {
                                if (0 == card_number) 
                                        card_number = first_row_arr[first_line];
                                else 
                                        return -1; // Bad magician!
                        }
                }
        }
        
        return card_number;
}


int main()
{
        int T = 0;
        cin >> T;

        // cout << "T=" << T << endl;

        for (int i = 1; i <=T; ++i) {

                input();

                const int ret = run();

                cout << "Case #" << i << ": ";
                
                if (0 < ret) 
                        cout << ret;
                else if (-1 == ret)
                        cout << "Bad magician!";
                else if (0 == ret)
                        cout << "Volunteer cheated!";

                cout << endl;
        }

        return 0;
}



