#include <bits/stdc++.h>
using namespace std;
const int MAXS = 2000 + 5;
const int MAXP = 500 + 5;
const int INF = INT_MAX / 2;
vector<int> ans;
char s[MAXS], p[MAXP];
int nx[MAXS];
int lens, lenp;
bool usd[MAXS][MAXS];
int rec[MAXS][MAXS];
int f(int i, int k) {
  if (k == 0) return 0;
  if (i >= lens) return INF;
  if (usd[i][k]) return rec[i][k];
  rec[i][k] = f(i + 1, k);
  if (nx[i] < INF)
    rec[i][k] = min(rec[i][k], f(i + nx[i], k - 1) + nx[i] - lenp);
  usd[i][k] = 1;
  return rec[i][k];
}
int main() {
  scanf("%s%s", s, p);
  lens = strlen(s);
  lenp = strlen(p);
  for (int i = 0; i < lens; ++i) {
    nx[i] = INF;
    if (s[i] == p[0]) {
      int a = i + 1, b = 1;
      while (a < lens && b < lenp) {
        if (s[a] == p[b]) {
          ++a;
          ++b;
        } else
          ++a;
      }
      if (b == lenp) nx[i] = a - i;
    }
  }
  int cnt = 0;
  int k;
  for (k = 1; k <= lens; ++k) {
    int tmp = f(0, k);
    if (tmp >= INF) break;
    while (cnt < tmp) {
      ans.push_back(k - 1);
      ++cnt;
    }
  }
  --k;
  if (k == 0) {
    for (int i = 0; i <= lens; ++i) ans.push_back(0);
  } else {
    for (int i = 0; i < lens + 1 - cnt - (lenp * k); ++i) ans.push_back(k);
    --k;
    while (k >= 0) {
      for (int i = 0; i < lenp; ++i) ans.push_back(k);
      --k;
    }
  }
  printf("%d", ans[0]);
  for (int i = 1; i < ans.size(); ++i) printf(" %d", ans[i]);
  printf("\n");
  return 0;
}
