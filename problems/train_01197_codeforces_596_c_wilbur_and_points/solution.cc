#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int MAXNUM = 100000;
int n;
int max_x[MAXNUM + 1];
int max_y;
int w[MAXN];
int res[MAXN][2];
int lookup(int t) {
  int p = 0, q = max_y;
  while (p < q) {
    int y = (p + q) / 2;
    if (y - max_x[y] < t)
      p = y + 1;
    else
      q = y;
  }
  if (p > q) return -1;
  if (p - max_x[p] != t) return -1;
  if (p < max_y && max_x[p] == max_x[p + 1]) return -1;
  return p;
}
int main() {
  for (int i = 0; i <= MAXNUM; i++) max_x[i] = -1;
  max_y = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > max_x[y]) max_x[y] = x;
    if (y > max_y) max_y = y;
  }
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = n - 1; i >= 0; i--) {
    int y = lookup(w[i]);
    if (y == -1) {
      cout << "NO" << endl;
      return 0;
    }
    res[i][0] = max_x[y]--;
    res[i][1] = y;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << res[i][0] << " " << res[i][1] << endl;
  return 0;
}
