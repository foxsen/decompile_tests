#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int fenw[N];
void add(int pos, int what) {
  for (int i = pos; i < N; i += i & (-i)) fenw[i] += what;
}
int pref(int r) {
  int ans = 0;
  for (int i = r; i > 0; i -= i & (-i)) ans += fenw[i];
  return ans;
}
int segm(int l, int r) { return pref(r) - pref(l - 1); }
void reset() { memset(fenw, 0, sizeof fenw); }
void solve(int n) {
  int m;
  cin >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    assert((int)(grid[i]).size() == m);
  }
  vector<vector<int>> to_r(n, vector<int>(m)), to_d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
      if (j == m - 1)
        to_r[i][j] = (grid[i][j] == 'z' ? 1 : 0);
      else
        to_r[i][j] = (grid[i][j] == 'z' ? to_r[i][j + 1] + 1 : 0);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == m)
        to_d[i][j] = (grid[i][j] == 'z' ? 1 : 0);
      else
        to_d[i][j] = (grid[i][j] == 'z' ? to_d[i - 1][j + 1] + 1 : 0);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) to_d[i][j] = min(to_d[i][j], to_r[i][j]);
  long long ans = 0;
  for (int j = 0; j < m; j++) {
    vector<pair<int, int>> evs;
    for (int i = 0; i < n; i++)
      if (grid[i][j] == 'z')
        evs.push_back(make_pair(i - to_d[i][j], -(i + 1))),
            evs.push_back(make_pair(i, +(i + 1)));
    sort((evs).begin(), evs.end());
    reset();
    int k = (int)(evs).size() - 1;
    for (int i = n - 1; i >= 0; i--) {
      while (k >= 0 && evs[k].first >= i) {
        int x = (evs[k].second > 0 ? 1 : -1);
        add(abs(evs[k].second), x);
        k--;
      }
      if (grid[i][j] == 'z') ans += segm(i + 1, min(i + to_r[i][j], N - 3));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) solve(n);
}
