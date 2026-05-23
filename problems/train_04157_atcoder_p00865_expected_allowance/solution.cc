#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

double dp[2][1000000];

int main() {
  int n, m, k;
  while (scanf("%d %d %d", &n, &m, &k), n|m|k) {
    //MEMSET(dp, 0);
    dp[0][0] = 1.0;
    REP(iter, n) {
      int prev = iter & 1;
      int next = (iter + 1) & 1;
      memset(dp[next], 0, sizeof(double) * (iter * m + m + 1));
      FOREQ(i, 0, iter * m) {
        FOREQ(j, 1, m) {
          dp[next][i + j] += dp[prev][i] / m;
        }
      }
    }
    double ans = 0;
    FOREQ(i, 1, n * m) {
      ans += max(i - k, 1) * dp[n & 1][i];
    }
    printf("%.7lf\n", ans);
  }
}