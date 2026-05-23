#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, a, b, ansi, ansj;
int l[N], r[N], c[N];
double ans = mod;
double fisdis(double i1, double j1, double i2, double j2) {
  double dis = (i2 - i1) * (i2 - i1) + (j2 - j1) * (j2 - j1);
  dis = sqrt(dis);
  return dis;
}
double check(int x, int y) {
  double dis = c[x];
  dis += fisdis(0, 0, a, l[y]);
  dis += fisdis(a, l[y], b, r[x]);
  return dis;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 1; i <= m; i++) cin >> r[i];
  for (int i = 1; i <= m; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) {
    int p1 = 1, p2 = n;
    while (p1 < p2 - 5) {
      int m1 = (p2 - p1) / 3;
      int m2 = 2 * m1;
      m1 += p1;
      m2 += p1;
      if (check(i, m1) < check(i, m2))
        p2 = m2;
      else
        p1 = m1;
    }
    for (int j = p1; j <= p2; j++) {
      if (check(i, j) < ans) {
        ans = check(i, j);
        ansi = i;
        ansj = j;
      }
    }
  }
  cout << ansj << " " << ansi;
}
