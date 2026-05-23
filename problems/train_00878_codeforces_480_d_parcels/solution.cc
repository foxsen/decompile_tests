#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
struct node {
  int in, out, w, s, v;
  void input() { cin >> in >> out >> w >> s >> v; }
} ar[555];
bool operator<(node a, node b) {
  if (a.in < b.in || (a.in == b.in && a.out > b.out)) return true;
  return false;
}
int dp[555][1111], dp1[555][1111];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b = 0, c, d = 0, e, f = 0, g, h = 0, x, y, z = 0;
  cin >> a >> b;
  ar[0].in = 0, ar[0].out = 2 * a, ar[0].w = 0, ar[0].s = b;
  ar[0].v = 0;
  for (int i = (1); i < (a + 1); ++i) ar[i].input();
  sort(ar, ar + a + 1);
  for (int i = a; i >= 0; i--) {
    for (int j = 0; j <= ar[i].s; j++) {
      c = ar[i].out;
      for (int k = ar[i].in; k <= ar[i].out; k++) dp1[i][k] = 0;
      for (int k = a; k > i; k--) {
        if (ar[k].out > ar[i].out || ar[k].w > j) continue;
        while (c > ar[k].in) {
          dp1[i][c] = max(dp1[i][c], dp1[i][c + 1]);
          c--;
        }
        dp1[i][c] = max(dp1[i][c], dp1[i][c + 1]);
        dp1[i][c] = max(dp1[i][c],
                        dp[k][min(j - ar[k].w, ar[k].s)] + dp1[i][ar[k].out]);
      }
      dp[i][j] = dp1[i][c] + ar[i].v;
    }
  }
  cout << dp[0][b] << endl;
}
