#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 322;
const long long LINF = 2e18 + 474;
const long long MAXN = 1e3 + 5;
const long long MOD = 1e9 + 7;
const double eps = 1e-10;
int n, s;
int a[MAXN], b[MAXN];
string ans = "NO";
void solve() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  if (a[1] == 1) {
    if (a[s] == 1) {
      ans = "YES";
    }
    for (int i = s; i <= n; i++) {
      if (a[i] && b[i] && b[s]) {
        ans = "YES";
      }
    }
  }
  cout << ans;
}
int main() {
  if (!1) {
    freopen(
        "474"
        ".in",
        "r", stdin);
    freopen(
        "474"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  setlocale(LC_ALL, "Russian");
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
