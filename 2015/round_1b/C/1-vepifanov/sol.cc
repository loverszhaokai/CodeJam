#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

#include <fstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int d[500000];
int t[500000];
int was[500000];

set<pair<ll, int> > all;

fstream log_fs;

void print_all()
{
        log_fs << "\tprint_all()" << endl;
	set<pair<ll, int> >::iterator it = all.begin();
        while (it != all.end()) {
		log_fs << "\t\t" << it->first << "  " << it->second << endl;
                it++;
        }
	log_fs << endl;
}

int main () {


	log_fs.open("log.txt", std::fstream::out);

	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

                log_fs << "====Case " << it << endl;
		scanf ("%d", &n);
		int ooo = 0;
		for (int i = 0; i < n; i++) {
			int d, h, m;
			scanf ("%d%d%d", &d, &h, &m);
			for (int j = 0; j < h; j++) {
				::d[ooo] = d;
				::t[ooo] = m + j;
				was[ooo] = 0;
				ooo++;
			}
		}

		log_fs << "\tt=" << endl << "\t";
		for (int kkk = 0; kkk < ooo; kkk++) {
			log_fs << "\tt[" << kkk << "]=" << t[kkk];
                }
                log_fs << endl << endl;

		all.clear ();

		int cur = ooo, ans = ooo;

		for (int i = 0; i < ooo; i++) 
			all.insert (mp ((ll)(360 - d[i]) * t[i], i));

		ll last_x = 0;
		while (cur <= 2 * ooo) {

	                print_all();

			ll x = all.begin ()->fi;
			int y = all.begin ()->se;

                        log_fs << "\tx=" << x << endl;
                        log_fs << "\ty=" << y << endl << endl;

			all.erase (all.begin ());

			if (x > last_x)
				ans = min (ans, cur);
			last_x = x;

			if (was[y])
				cur++; 
			else 
				cur--;

//			printf ("%I64d %d : %d %d\n", x, y, cur,
//			was[y]);

			was[y] = 1;
			all.insert (mp (x + (ll)360 * t[y], y));
		}

		cout << "Case #" << it << ": " << ans;
		cout << endl;

		log_fs << "Case #" << it << ": " << ans << endl << endl << endl;

		fprintf (stderr, "%d / %d = %.2f | %.2f\n", 
			it, tt, (double)clock () / CLOCKS_PER_SEC,
			((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}

	log_fs.close();

	return 0;
}
