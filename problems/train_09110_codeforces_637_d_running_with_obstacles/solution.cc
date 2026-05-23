#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)1e6 + 10;
const int INF = (int)1e9 + 7;
const long long LINF = (long long)1e18 + 10;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);
int a[MXN];
int n, m, s, d;
vector<pair<int, int> > v;
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &d);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  v.push_back(make_pair(a[1], a[1]));
  for (int i = 2; i <= n; ++i) {
    if (a[i] - v.back().second - 2 < s) {
      v[(int)v.size() - 1].second = a[i];
    } else {
      v.push_back(make_pair(a[i], a[i]));
    }
  }
  for (auto it : v) {
    if (d < it.second - it.first + 2) {
      printf("IMPOSSIBLE");
      return 0;
    }
  }
  int cur = 0;
  for (auto it : v) {
    if (it.first - 1 - cur < s) {
      printf("IMPOSSIBLE");
      return 0;
    } else {
      cur = it.second + 1;
    }
  }
  cur = 0;
  for (auto it : v) {
    if (it.first - 1 - cur > 0) printf("RUN %d\n", it.first - 1 - cur);
    if (it.second + 2 - it.first > 0)
      printf("JUMP %d\n", it.second + 1 - it.first + 1);
    cur = it.second + 1;
  }
  if (cur != m) {
    printf("RUN %d", m - cur);
  }
  return 0;
}
