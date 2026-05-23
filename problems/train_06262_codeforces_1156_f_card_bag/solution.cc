#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 5014;
long long fac[SIZE], inv[SIZE];
long long mypow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return res;
}
long long C(int x, int y) {
  if (y < 0 || y > x) return 0;
  return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void build() {
  assert(MOD >= SIZE);
  fac[0] = 1;
  for (int i = (1); i < (SIZE); ++i) fac[i] = fac[i - 1] * i % MOD;
  inv[SIZE - 1] = mypow(fac[SIZE - 1], MOD - 2);
  for (int i = SIZE - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}
long long dp[SIZE];
void solve(vector<int> &AA) {
  sort((AA).begin(), (AA).end());
  int n = ((int)(AA).size());
  bool same = 0;
  for (int i = (1); i < (n); ++i) {
    if (AA[i] == AA[i - 1]) same = 1;
  }
  if (!same) {
    W(0);
    return;
  }
  dp[0] = 1;
  vector<int> d;
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && AA[j] == AA[i]; j++)
      ;
    d.push_back(j - i);
  }
  long long an = 0;
  for (int i = 0; i < (((int)(d).size())); ++i) {
    for (int j = (0); j <= (min(i, n - 2)); ++j) {
      ADD(an, dp[j] * d[i] % MOD * (d[i] - 1) % MOD * fac[n - j - 2]);
    }
    for (int j = i; j >= 0; j--) {
      ADD(dp[j + 1], dp[j] * d[i]);
    }
  }
  W(an * inv[n] % MOD);
}
int main() {
  MOD = 998244353;
  build();
  int n;
  R(n);
  vector<int> AA(n);
  for (int i = 0; i < (n); ++i) R(AA[i]);
  solve(AA);
  return 0;
}
