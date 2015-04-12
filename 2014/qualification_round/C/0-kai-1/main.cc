#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_SIZE 52

int r_g, c_g, m_g;

// '#' means block which is around the matrix
// '*' means mine
// 'N' means contains a number but not zero
// '0' means there is no mine in current cell neighbours
// 'c' is the last '0' at the bottom right corner
char matrix_arr[MAX_SIZE][MAX_SIZE];

void input()
{
        cin >> r_g >> c_g >> m_g;
}

void dbg_print()
{
        cout << "The content of matrix_arr:" << endl;

        for (int row = 0; row < r_g + 2; row++) {

                for (int col = 0; col < c_g + 2; col++) {

                        if ('#' != matrix_arr[row][col])
                                cout << "_ ";
                        else
                                cout << matrix_arr[row][col] << " ";
                }
                cout << endl;
        }
        cout << endl;
}

void print(const bool has_swap_row_and_col)
{
        // cout << "The content of matrix_arr:" << endl;        

        if (has_swap_row_and_col) {

                for (int col = 1; col <= c_g; col++) {
                        for (int row = 1; row <= r_g; row++) {

                                // if ('.' == matrix_arr[row][col])
                                // cout << "_ ";
                                // else
                                cout << matrix_arr[row][col];
                        }
                        cout << endl;
                }
                
        } else {
                for (int row = 1; row <= r_g; row++) {

                        for (int col = 1; col <= c_g; col++) {

                                // if ('.' == matrix_arr[row][col])
                                // cout << "_ ";
                                // else
                                cout << matrix_arr[row][col];
                        }
                        cout << endl;
                }
        }

        // cout << endl;
}

int run()
{
        bool has_swap_row_and_column = false;

        if (r_g > c_g) {
                int temp = r_g;
                r_g = c_g;
                c_g = temp;
                has_swap_row_and_column = true;
        }

        for (int row = 1; row <= r_g; row++)
                for (int col = 1; col <= c_g; col++)
                        matrix_arr[row][col] = '*';
                

        const int not_mine_count = r_g * c_g - m_g;
        
        if (1 == not_mine_count)
                goto OK;

        if (1 == r_g) {
                for (int col = 2; col <= not_mine_count; col++)
                        matrix_arr[1][col] = '.';
                goto OK;
        } 
        else if (2 == r_g) {
                if (2 == not_mine_count)
                        goto ERR;
                
                if (0 != not_mine_count % 2)
                        goto ERR;
                
                matrix_arr[2][1] = '.';
                
                for (int col = 2; col <= not_mine_count / 2; col++) {
                        matrix_arr[1][col] = '.';
                        matrix_arr[2][col] = '.';
                }
                goto OK;
        }
        else {

                if (2 == not_mine_count 
                    || 3 == not_mine_count
                    || 5 == not_mine_count
                    || 7 == not_mine_count)
                        goto ERR;

                if (c_g >= not_mine_count / 2
                    && 0 == not_mine_count % 2) {
                        for (int col = 1; col <= not_mine_count / 2; col++) {
                                matrix_arr[1][col] = '.';
                                matrix_arr[2][col] = '.';
                        }
                        goto OK;
                }
                
                for (int rn = 3; rn <= r_g; rn++) {
                        const int c = not_mine_count / rn;
                        const int r = not_mine_count % rn;

                        if (c == c_g && 0 == r) {
                                for (int col = 1; col <= c; col++) {
                                        for (int row = 1; row <= rn; row++) {
                                                matrix_arr[row][col] = '.';
                                        }
                                }
                                goto OK;
                        }

                        if (c >= c_g)
                                continue;

                        if (1 == c)
                                continue;
                        if (2 == c && 1 == r)
                                continue;

                        for (int col = 1; col <= c; col++) {
                                for (int row = 1; row <= rn; row++) {
                                        matrix_arr[row][col] = '.';
                                }
                        }

                        for (int row = 1; row <= r; row++) {
                                matrix_arr[row][c + 1] = '.';
                        }

                        if (1 == r) {
                                matrix_arr[2][c + 1] = '.';
                                matrix_arr[rn][c] = '*';
                        }
                        goto OK;
                }
        }
        
ERR:
        return 0;

OK:
        matrix_arr[1][1] = 'c';
        print(has_swap_row_and_column);
        return 1;
}


int main()
{
        int total_test_cases = 0;

        cin >> total_test_cases;

        for (int tt = 1; tt <= total_test_cases; ++tt) {

                input();
                
                cout << "Case #" << tt << ":" << endl;

                const int ret = run();

                if (0 == ret) 
                        cout << "Impossible" << endl;
        }

        return 0;
}

