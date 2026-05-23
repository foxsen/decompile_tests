#include <bits/stdc++.h>
using namespace std;
struct T_ {
  long long w, h, c;
};
const int maxn = 2e5 + 1;
int n;
T_ a[maxn];
vector<vector<T_> > s;
long long gcd_row[maxn];
long long FastIn() {
  long long res = 0;
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  while ('0' <= c && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
  }
  return res;
}
void Enter() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].h >> a[i].c;
}
void Init() {
  sort(a + 1, a + n + 1,
       [](T_ a, T_ b) { return a.w < b.w || (a.w == b.w && a.h < b.h); });
  for (int i = 1; i <= n; ++i)
    if (a[i].w != a[i - 1].w)
      s.push_back(vector<T_>{a[i]});
    else
      s.back().push_back(a[i]);
}
long long GCD(long long m, long long n) {
  while (n > 0) {
    long long r = m % n;
    m = n;
    n = r;
  }
  return m;
}
bool Check(long long x) {
  for (int i = 0; i < s[0].size(); ++i) gcd_row[i] = s[0][i].c / x;
  for (auto v : s) {
    long long y = v[0].c / gcd_row[0];
    for (int i = 0; i < v.size(); ++i)
      if (v[i].c % gcd_row[i] != 0 || v[i].c / gcd_row[i] != y) return 0;
  }
  return 1;
}
void Solve() {
  int n = s[0].size();
  int m = s.size();
  for (int i = 0; i < m; ++i) {
    gcd_row[i] = 0;
    if (s[i].size() != n) {
      cout << 0;
      return;
    }
    for (int j = 0; j < n; ++j)
      if (s[i][j].h != s[0][j].h) {
        cout << 0;
        return;
      } else
        gcd_row[i] = GCD(gcd_row[i], s[i][j].c);
  }
  for (int i = 1; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (s[i][j].c / gcd_row[i] != s[i - 1][j].c / gcd_row[i - 1]) {
        cout << 0;
        return;
      }
  long long S = 0;
  int res = 0;
  for (int i = 0; i < m; ++i) S = GCD(S, gcd_row[i]);
  for (int i = 1; 1ll * i * i <= S; ++i)
    if (S % i == 0) {
      ++res;
      if (1ll * i * i != S) ++res;
    }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Enter();
  Init();
  Solve();
}
