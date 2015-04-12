#include <stdio.h>
#include <stdlib.h>

#include <iostream>


using std::cin;
using std::cout;
using std::endl;

#define STR_MAX_SIZE 10002


// ====== Global Variables ======

int L;
long long X;

char str[STR_MAX_SIZE];

int str_index;
long long X_index;

struct MultiplyResult {
        int is_positive;
        char sum;
};

struct MultiplyResult *mul_ret;

// ------ Global Variables ------

int init_only_once()
{
        mul_ret = new struct MultiplyResult;

        return 0;
}

int init_per_case()
{
        mul_ret->is_positive = 1;
        mul_ret->sum = '1';

        return 0;
}

int handle_input()
{
        scanf("%d %lld", &L, &X);
        scanf("%s", str + 1);

        // printf("L=%d  X=%lld\n", L, X);
        // printf("str=%s\n", str + 1);
        return 0;
}

void multiply(MultiplyResult *mul_ret, const char rs) 
{
        switch (mul_ret->sum) {
        case '1':
                switch (rs) {
                case '1':
                        mul_ret->sum = '1';
                        return;
                case 'i':
                        mul_ret->sum = 'i';
                        return;
                case 'j':
                        mul_ret->sum = 'j';
                        return;
                case 'k':
                        mul_ret->sum = 'k';
                        return;
                default:
                        abort();
                }

        case 'i':
                switch (rs) {
                case '1':
                        mul_ret->sum = 'i';
                        return;
                case 'i':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = '1';
                        return;
                case 'j':
                        mul_ret->sum = 'k';
                        return;
                case 'k':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = 'j';
                        return;
                default:
                        abort();
                }

        case 'j':
                switch (rs) {
                case '1':
                        mul_ret->sum = 'j';
                        return;
                case 'i':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = 'k';
                        return;
                case 'j':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = '1';
                        return;
                case 'k':
                        mul_ret->sum = 'i';
                        return;
                default:
                        abort();
                }

        case 'k':
                switch (rs) {
                case '1':
                        mul_ret->sum = 'k';
                        return;
                case 'i':
                        mul_ret->sum = 'j';
                        return;
                case 'j':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = 'i';
                        return;
                case 'k':
                        mul_ret->is_positive ^= 1;
                        mul_ret->sum = '1';
                        return;
                default:
                        abort();
                }

        default:
                abort();
        }
}

int has_only_one_char()
{
        const char guard = str[1];

        for (int i = 2; i <= L; i++) {
                if (guard != str[i])
                        return 0;
        }

        return 1;
}

int find_is()
{
        str_index = 1;
        X_index = 1;
        mul_ret->sum = '1';

        // Return 0 if X_index > 2
        // T1 * T2 = -1
        // It's useless goto T3
        while (X_index <= 2 && X_index <= X) {
                while (str_index <= L) {

                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply(mul_ret, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('i' == mul_ret->sum)
                                return 1;
                }
                str_index = 1;
                X_index++;
        }

        return 0;
}

int find_js()
{
        mul_ret->sum = '1';
        const long long orig_X_index = X_index;

        while (X_index <= orig_X_index + 2 && X_index <= X) {
                while (str_index <= L) {
                        
                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply(mul_ret, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('j' == mul_ret->sum)
                                return 1;
                }
                str_index = 1;
                X_index++;
        }

        return 0;
}

int find_ks()
{
        // printf("find_ks()\n");
        // printf("X_index=%lld\n", X_index);
        // printf("str_index=%d\n", str_index);

        mul_ret->sum = '1';
        const long long orig_X_index = X_index;

        while (X_index <= orig_X_index + 2 && X_index <= X) {
                while (str_index <= L) {

                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply(mul_ret, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('k' == mul_ret->sum)
                                return 1;
                }
                str_index = 1;
                X_index++;
        }

        return 0;
}

void multiply_result_per_period(MultiplyResult *mul_per_period)
{
        mul_per_period->is_positive = 1;
        mul_per_period->sum = '1';
        
        for (int i = 1; i <= L; i++) {
                multiply(mul_per_period, str[i]);
        }
}

int is_left_equal_to_one()
{
        mul_ret->sum = '1';
        const long long last_X_index = X - X_index;

        while (str_index <= L) {
                // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                multiply(mul_ret, str[str_index]);
                // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);
                str_index++;
        }

        struct MultiplyResult mul_per_period;
        multiply_result_per_period(&mul_per_period);

        // printf("per period result=%c%c\n", mul_per_period.is_positive ? '+' : '-', mul_per_period.sum);
        
        struct MultiplyResult mul_last_X_index = mul_per_period;

        if ('1' == mul_per_period.sum &&
            1 == mul_per_period.is_positive) {

        } else if ('1' == mul_per_period.sum &&
                   0 == mul_per_period.is_positive) {
                switch (last_X_index % 4) {

                case 0:
                case 2:
                        mul_last_X_index.is_positive = 1;
                        break;
                case 1:
                case 3:
                        break;
                default:
                        break;
                }
                
        } else {
                switch (last_X_index % 4) {

                case 0:
                        mul_last_X_index.is_positive = 1;
                        mul_last_X_index.sum = '1';
                        break;
                case 1:
                        break;
                case 2:
                        mul_last_X_index.is_positive = 0;
                        mul_last_X_index.sum = '1';
                        break;
                case 3:
                        mul_last_X_index.is_positive ^= 1;
                        break;

                default:
                        break;
                }
        }

        multiply(mul_ret, mul_last_X_index.sum);

        if ('1' == mul_ret->sum && 
            mul_ret->is_positive == mul_last_X_index.is_positive)
                return 1;

        return 0;
}

int run()
{
        // Return 0 if there is only one character such as iiiii or
        // jjjj
        if (1 == has_only_one_char())
                return 0;


        // Find i str
        if (0 == find_is())
                return 0;

        // Find j str
        if (0 == find_js())
                return 0;

        // Find k str
        if (0 == find_ks())
                return 0;

        // If there is left str, the multiply result must be 1
        if (0 == is_left_equal_to_one())
                return 0;

        return 1;
}

int main()
{
        init_only_once();

        int total_cases_count = 0;
        scanf("%d", &total_cases_count);

        int run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                printf("Case #%d: ", tt);

                if (0 == run_ret)
                        printf("NO\n");
                else 
                        printf("YES\n");
        }




        return 0;
}

