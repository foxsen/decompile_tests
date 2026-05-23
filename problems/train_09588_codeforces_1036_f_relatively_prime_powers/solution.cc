#include <bits/stdc++.h>
using namespace std;
const int N = 303, M = 18;
mt19937 gen(time(NULL));
template <typename T = int>
inline T read() {
  T val = 0, sign = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') sign = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) val = val * 10 + ch - '0';
  return sign * val;
}
vector<long long> cand;
long long root(long long x) {
  long long l = 0, r = 1e9 + 1;
  while (l < r - 1) {
    long long m = (l + r) / 2;
    if (m * m > x)
      r = m;
    else
      l = m;
  }
  return l;
}
void solve() {
  long long l = 2;
  long long r;
  cin >> r;
  long long ans = upper_bound((cand).begin(), (cand).end(), r) -
                  lower_bound((cand).begin(), (cand).end(), l);
  ans += root(r) - root(l - 1);
  printf("%lld\n", r - 1 - ans);
}
void precalc() {
  long long U = 1e18;
  vector<long long> _cand = {1};
  for (long long i = 2; i <= 1e6; i++)
    for (long long curr = i * i * i; curr <= U; curr *= i) {
      _cand.push_back(curr);
      if (curr > U / i) break;
    }
  sort((_cand).begin(), (_cand).end());
  _cand.erase(unique((_cand).begin(), (_cand).end()), _cand.end());
  for (const long long &u : _cand) {
    long long x = root(u);
    if (x * x == u) continue;
    cand.push_back(u);
  }
  fprintf(stderr, "Precalc: %.3f\n", (double)(clock()) / CLOCKS_PER_SEC),
      fflush(stderr);
}
signed main() {
  precalc();
  int t = read();
  clock_t tot = clock();
  while (t--) {
    clock_t z = clock();
    solve();
  }
  fprintf(stderr, "Total Time: %.3f\n",
          (double)(clock() - tot) / CLOCKS_PER_SEC),
      fflush(stderr);
}
