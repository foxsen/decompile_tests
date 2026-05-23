#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

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

const ll INF = 1e+18 + 1;
const ll BASE = 1e+9 + 9;

int n, m;
ll k;
char strs[110][210];
int lens[110];
ll dp[2310];
ll num[2310];
char ans[2310];

inline ll Plus(ll lhs, ll rhs) {
  if (lhs + rhs >= INF) { return INF; }
  return lhs + rhs;
}

inline ll Mul(ll lhs, ll rhs) {
  if (rhs == 0) { return 0; }
  if (lhs * rhs / rhs != lhs || lhs * rhs >= INF) { return INF; }
  return lhs * rhs;
}

ll cnts[300];
void CalcNum1(int l) {
  MEMSET(cnts, 0);
  num[l] = 0;
  REP(i, n) {
    ull powBase = 1;
    ull h1 = 0;
    ull h2 = 0;
    ull prev = 0;
    REP(j, min(lens[i], l)) {
      int rest = m - (l - j - 1 + lens[i]);
      ull next = strs[i][j];
      h1 = h1 * BASE + strs[i][j];
      h2 = h2 - prev + next + ans[l - j - 1] * powBase;
      powBase *= BASE;
      prev = next;
      if (h1 != h2 || rest < 0) { continue; }
      ll cnt1 = dp[rest];
      ll cnt2 = num[l - j - 1];
      cnts[next] = Plus(cnts[next], Mul(cnt1, cnt2));
    }
  }
}

void CalcNum2(int l) {
  num[l] = 0;
  REP(i, n) {
    if (lens[i] > l) { continue; }
    ull powBase = 1;
    ull h1 = 0;
    ull h2 = 0;
    REP(j, min(lens[i], l)) {
      h1 = h1 * BASE + strs[i][j];
      h2 = h2 + ans[l - j - 1] * powBase;
      powBase *= BASE;
    }
    if (h1 != h2) { continue; }
    num[l] = Plus(num[l], num[l - lens[i]]);
  }
}

void calc(int depth, ll need) {
  if (depth == m) { return; }
  CalcNum1(depth + 1);
  FOREQ(c, 'a', 'z') {
    ans[depth] = c;
    ll cnt = cnts[c];
    if (cnt >= need) { break; }
    need -= cnt;
  }
  CalcNum2(depth + 1);
  calc(depth + 1, need);
}

int main() {
  while (scanf("%d %d %lld", &n, &m, &k) > 0) {
    MEMSET(ans, 0);
    MEMSET(dp, 0);
    MEMSET(num, 0);
    dp[0] = 1;
    num[0] = 1;
    REP(i, n) {
      scanf("%s", strs[i]);
      lens[i] = strlen(strs[i]);
    }
    FOR(i, 1, 2010) {
      REP(j, n) {
        if (i - lens[j] < 0) { continue; }
        ll cnt = dp[i - lens[j]];
        dp[i] = Plus(dp[i], cnt);
      }
    }
    if (dp[m] < k) {
      puts("-");
      continue;
    }
    calc(0, k);
    printf("%s\n", ans);
  }
}