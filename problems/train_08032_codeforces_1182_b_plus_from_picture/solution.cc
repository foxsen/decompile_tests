#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long T, t;
bool safe(int a, int b, int c, int d) {
  if (a >= 0 && a < c && b >= 0 && b < d) return true;
  return false;
}
void solve() {
  long long int i, n, m, ans = 0, l, ln, a, d, sum = 0, j, p1, p2, q1, q2,
                         cnt = 0;
  cin >> n >> m;
  char v[n][m];
  vector<pair<int, int>> v1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] != '.') {
        cnt++;
        v1.push_back(make_pair(i, j));
      }
    }
  }
  for (auto z : v1) {
    int x = z.first + 1;
    int y = z.second;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    while (safe(x, y, n, m) && v[x][y] != '.') {
      cnt1++;
      x++;
    }
    x = z.first - 1;
    y = z.second;
    while (safe(x, y, n, m) && v[x][y] != '.') {
      cnt2++;
      x--;
    }
    x = z.first;
    y = z.second - 1;
    while (safe(x, y, n, m) && v[x][y] != '.') {
      cnt3++;
      y--;
    }
    x = z.first;
    y = z.second + 1;
    while (safe(x, y, n, m) && v[x][y] != '.') {
      cnt4++;
      y++;
    }
    if (cnt1 != 0 && cnt2 != 0 && cnt3 != 0 && cnt4 != 0 &&
        cnt1 + cnt2 + cnt3 + cnt4 + 1 == cnt) {
      cout << "YES";
      return;
    }
    if (cnt1 != 0 && cnt2 != 0 && cnt3 != 0 && cnt4 != 0 &&
        cnt1 + cnt2 + cnt3 + cnt4 + 1 != cnt) {
      cout << "NO";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) solve();
  return 0;
}
