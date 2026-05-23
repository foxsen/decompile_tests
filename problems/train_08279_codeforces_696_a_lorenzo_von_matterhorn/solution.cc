#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
template <class T>
inline void read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> q;
  map<long long, long long> dp;
  while (q--) {
    long long op, u, v;
    cin >> op >> u >> v;
    if (op == 1) {
      long long w;
      cin >> w;
      while (u ^ v) {
        if (u < v) swap(u, v);
        dp[u] += w, u /= 2;
      }
    } else {
      long long ans = 0;
      while (u ^ v) {
        if (u < v) swap(u, v);
        ans += dp[u], u /= 2;
      }
      cout << ans << endl;
    }
  }
}
