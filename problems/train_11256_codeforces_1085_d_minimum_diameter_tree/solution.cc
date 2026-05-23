#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  long long s;
  scanf("%lli %lli", &n, &s);
  if (n == 2) {
    printf("%lli\n", s);
    exit(0);
  }
  vector<vector<long long> > vv(n);
  for (long long i = 0; i < n - 1; ++i) {
    long long a, b;
    scanf("%lli %lli", &a, &b);
    --a, --b;
    vv[a].push_back(b);
    vv[b].push_back(a);
  }
  vector<long long> lists(n);
  int kkk = 0;
  for (long long i = 0; i < n; ++i) {
    if (vv[i].size() == 1) {
      lists[i] = 0;
      ++kkk;
    } else {
      for (long long j = 0; j < vv[i].size(); ++j)
        if (vv[vv[i][j]].size() == 1) ++lists[i];
    }
  }
  printf("%.10Lf", (long double)2 * s / kkk);
  exit(0);
  long long mx_n = 0;
  for (long long i = 0; i < n; ++i) {
    long long val = 0;
    for (long long j = 0; j < vv[i].size(); ++j) {
      val += vv[vv[i][j]].size();
    }
    val += lists[i];
    val -= vv[i].size();
    mx_n = max(mx_n, val);
  }
  printf("%.10Lf\n", (long double)(2 * s) / mx_n);
}
int main() {
  solve();
  return 0;
}
