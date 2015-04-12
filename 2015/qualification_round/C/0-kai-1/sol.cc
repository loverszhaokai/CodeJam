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

int is_positive = 1;
char multiply_sum;

// ------ Global Variables ------

int init_only_once()
{
        return 0;
}

int init_per_case()
{
        is_positive = 1;
        
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

char multiply(const char ls, const char rs) 
{
        switch (ls) {
        case '1':
                switch (rs) {
                case '1':
                        return '1';
                case 'i':
                        return 'i';
                case 'j':
                        return 'j';
                case 'k':
                        return 'k';
                default:
                        abort();
                }

        case 'i':
                switch (rs) {
                case '1':
                        return 'i';
                case 'i':
                        is_positive ^= 1;
                        return '1';
                case 'j':
                        return 'k';
                case 'k':
                        is_positive ^= 1;
                        return 'j';
                default:
                        abort();
                }

        case 'j':
                switch (rs) {
                case '1':
                        return 'j';
                case 'i':
                        is_positive ^= 1;
                        return 'k';
                case 'j':
                        is_positive ^= 1;
                        return '1';
                case 'k':
                        return 'i';
                default:
                        abort();
                }

        case 'k':
                switch (rs) {
                case '1':
                        return 'k';
                case 'i':
                        return 'j';
                case 'j':
                        is_positive ^= 1;
                        return 'i';
                case 'k':
                        is_positive ^= 1;
                        return '1';
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
        multiply_sum = '1';

        while (X_index <= X) {
                while (str_index <= L) {

                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply_sum = multiply(multiply_sum, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('i' == multiply_sum)
                                return 1;
                }
                str_index = 1;
                X_index++;
        }

        return 0;
}

int find_js()
{
        multiply_sum = '1';

        while (X_index <= X) {
                while (str_index <= L) {
                        
                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply_sum = multiply(multiply_sum, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('j' == multiply_sum)
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

        multiply_sum = '1';

        while (X_index <= X) {
                while (str_index <= L) {

                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply_sum = multiply(multiply_sum, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;

                        if ('k' == multiply_sum)
                                return 1;
                }
                str_index = 1;
                X_index++;
        }

        return 0;
}

int is_left_equal_to_one()
{
        multiply_sum = '1';

        while (X_index <= X) {
                while (str_index <= L) {

                        // printf("multiply('%c', '%c')=", multiply_sum, str[str_index]);
                        
                        multiply_sum = multiply(multiply_sum, str[str_index]);

                        // printf("%c%c\n", is_positive ? ' ' : '-', multiply_sum);

                        str_index++;
                }
                str_index = 1;
                X_index++;
        }

        if ('1' == multiply_sum && 1 == is_positive)
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

