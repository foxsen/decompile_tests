#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int main(){
	int n; cin >> n;
	vector<tuple<int, int, int, int, int>> v;
	FOR(i, n){
		int f, a, t, x, y;
		cin >> f >> a >> t >> x >> y;
		v.emplace_back(f, a, t, x, y);
	}
	double ans[2][2];
	ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -1;
	FOR(i, n - 1){
		int pf, pa, pt, px, py;
		int f, a, t, x, y;
		tie(pf, pa, pt, px, py) = v[i];
		tie(f, a, t, x, y) = v[i+1];
		if (pt == t && a != pa) {
			double nt = sqrt(pow(x - px, 2) + pow(y - py, 2));
			if (ans[t][0] <= nt) {
				if (abs(ans[t][0] - nt) < 1e-6) {
					ans[t][1] = min<double>(ans[t][1], (f - pf) / 60.);
				} else {
					ans[t][1] = (f - pf)/60.;
				}
				ans[t][0] = nt;
			}
		}
	}

	FOR(i, 2) printf("%.10lf %.10lf\n", ans[i][0], ans[i][1]);
}