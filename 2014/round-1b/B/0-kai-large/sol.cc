#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using std::bitset;
using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======


// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

#ifdef DBG
std::fstream log_fs;
#endif

int A,B,K;

bitset<32> A_b, B_b, K_b;

bool f_ans[32][2][2][2];
long long m_ans[32][2][2][2];

// ------ Global Variables ------


// ====== Function declarations ======


// ------ Function declarations ------


int init_only_once()
{
#ifdef DBG
	log_fs << ">>>>init_only_once()" << endl;
	log_fs << "<<<<init_only_once()" << endl << endl;
#endif

        return 0;
}

int handle_input()
{
#ifdef DBG
	log_fs << ">>>>>>handle_input()" << endl;
#endif

	cin >> A >> B >> K;

#ifdef DBG
	log_fs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	log_fs << ">>>>>>init_per_case()" << endl;
#endif

        memset(f_ans, 0, sizeof(f_ans));

#ifdef DBG
	log_fs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

int get_high_bit_pos(const bitset<32> &_bs)
{
	int high_bit_pos = 0;
	for (int iii = 0; iii < _bs.size(); iii++) {
		if (0 != _bs[iii])
			high_bit_pos = iii;
        }
	return high_bit_pos;
}

int get_decimal(const bitset<32> &_bs, const int _fp, const int _ep)
{
	if (_fp < 0 || _ep < 0)
		return 0;

	int decimal = 0;
        
	for (int jjj = _fp; jjj < _ep; jjj++) {
		decimal += _bs[jjj] * pow(2.0, jjj - _fp);
        }

	return decimal;
}

long long get_ans(const int _pos, const bool _smaller_than_A, 
		const bool _smaller_than_B, const bool _smaller_than_K)
{
	long long ans = 0;

	if (_pos < 0) {
		if (_smaller_than_A && _smaller_than_B && _smaller_than_K)
			return 1;
                return 0;
        }

	if (f_ans[_pos][_smaller_than_A][_smaller_than_B][_smaller_than_K])
		return m_ans[_pos][_smaller_than_A][_smaller_than_B][_smaller_than_K];

	for (int iii = 0; iii < 2; iii++) {
		for (int jjj = 0; jjj < 2; jjj++) {

			if (!_smaller_than_A && iii > A_b[_pos])
				continue;
			if (!_smaller_than_B && jjj > B_b[_pos])
				continue;
			if (!_smaller_than_K && (iii & jjj) > K_b[_pos])
				continue;

			ans += get_ans(_pos - 1, _smaller_than_A || (iii < A_b[_pos]),
					_smaller_than_B || (jjj < B_b[_pos]),
					_smaller_than_K || ((iii & jjj) < K_b[_pos]));
                }
        }

	f_ans[_pos][_smaller_than_A][_smaller_than_B][_smaller_than_K] = true;
        m_ans[_pos][_smaller_than_A][_smaller_than_B][_smaller_than_K] = ans;

        return ans;
}

long long run()
{
#ifdef DBG
	log_fs << ">>>>>>run()" << endl;
#endif
	long long ans = 0;

	if (K > A || K > B)
		return (long long)A * B;

        A_b = bitset<32>(A);
        B_b = bitset<32>(B);
        K_b = bitset<32>(K);

#ifdef DBG
	log_fs << "<<<<<<A= " << A << " A_b = " << A_b << endl;
	log_fs << "<<<<<<B= " << B << " B_b = " << B_b << endl;
	log_fs << "<<<<<<K= " << K << " K_b = " << K_b << endl;
#endif

	ans = get_ans(31, false, false, false);

#ifdef DBG
	log_fs << "<<<<<<run() = " << ans << endl << endl;
#endif
	return ans;
}

int main()
{
#ifdef DBG
        log_fs.open("log.txt", std::fstream::out);
	log_fs << ">>main()" << endl << endl;
#endif

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        long long run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		log_fs << "Case #" << tt << ": " << run_ret << endl;
#endif
        }


#ifdef DBG
	log_fs << "<<main()" << endl;
	log_fs.close();
#endif
        return 0;
}

