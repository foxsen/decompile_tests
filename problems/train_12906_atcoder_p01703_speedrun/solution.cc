//
//  main.cpp
//
//  Under GPLv3 license
//

// #pragma GCC diagnostic error "-std=c++14"
// #pragma GCC optimize("O3")
// #pragma comment(linker, "/STACK:1024000000,1024000000")

#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
// #include <unordered_map>
// #include <unordered_set>
#include <utility>
#include <vector>

#define pb push_back
#define pf push_front
#define mp make_pair

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int INF = (1 << 30) - 1;
const LL LINF = (1LL << 61) - 1;
const double EPS = 1e-10;
const int N = 1e5 + 1000;
const int LEN = 50;

int T;
int n;
vector<double> p;
double dp[N];

void init() {
  p.clear();
  memset(dp, 0, sizeof dp);
}

int main() {
// ios::sync_with_stdio(false);
// cin.tie(0);
// freopen(".in", "r", stdin);
// freopen(".out", "w", stdout);

#ifndef ONLINE_JUDGE
  double __start_time = clock();
#endif

  // insert code heree

  while (scanf("%d", &n)) {
    if (n == 0) break;
    init();

    double buff = 0.00;
    for (int i = 0; i < n; i++) {
      double x;
      scanf("%lf", &x);
      if (x == 1.00) {
        buff += 1.00;
      } else {
        if (buff > 0) p.pb(buff), buff = 0.00;
        p.pb(x);
      }
    }

    if (buff > 0) p.pb(buff);

    n = (int)p.size();

    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = INF;
      buff = 0;

      for (int j = i + 1; j <= n && j - i <= LEN; j++) {
        if (p[j - 1] < 1.00)
          buff = (buff + 1.00) / p[j - 1];
        else
          buff += p[j - 1];
        dp[i] = min(dp[i], buff + dp[j] + 1);
      }
    }

    printf("%.8lf\n", dp[0] - 1.00);
  }

#ifndef ONLINE_JUDGE
  cout << "LOCAL RUNNING TIME = "
       << double(((double)clock() - __start_time) / (double)CLOCKS_PER_SEC)
       << " sec" << endl;
#endif

  return 0;
}