#include <bits/stdc++.h>
using namespace std;
int r;
int n, m;
int dh[2][210];
int dt[2][210];
int h0, t0;
void read() {
  scanf("%d %d %d", &h0, &t0, &r);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &dh[0][i], &dt[0][i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d %d", &dh[1][i], &dt[1][i]);
}
int d[410][410];
int result[410][410];
int dest[410][410];
const int MAXDELT = 201;
queue<pair<int, int> > q;
const string outcomes[3] = {"Ivan", "Zmey", "Draw"};
void solve() {
  memset(d, 0, sizeof(d));
  for (int i = 0; i <= MAXDELT + r + 1; i++)
    for (int j = 0; j <= MAXDELT + r + 1; j++) {
      if (i + j == 0) {
        q.push(make_pair(i, j));
        result[i][j] = 0;
        dest[i][j] = 0;
        continue;
      }
      if (i + j > r) {
        q.push(make_pair(i, j));
        result[i][j] = 1;
        dest[i][j] = 0;
        continue;
      }
      result[i][j] = 2;
      d[i][j] = min(i, n) + min(j, m);
    }
  for (; !q.empty();) {
    int h = q.front().first;
    int t = q.front().second;
    q.pop();
    if (h == h0 && t == t0) {
      cout << outcomes[result[h][t]] << endl;
      cout << dest[h][t] << endl;
      return;
    }
    for (int i = 1; i <= n; i++) {
      int nh = h - dh[0][i] + i;
      int nt = t - dt[0][i];
      if (nh < i || nt < 0) continue;
      if (nh > MAXDELT + r + 1 || nt > MAXDELT + r + 1) continue;
      if (result[nh][nt] != 2) continue;
      d[nh][nt]--;
      if (result[h][t] == 0 || d[nh][nt] == 0) {
        dest[nh][nt] = dest[h][t] + 1;
        result[nh][nt] = result[h][t];
        q.push(make_pair(nh, nt));
      }
    }
    for (int i = 1; i <= m; i++) {
      int nh = h - dh[1][i];
      int nt = t - dt[1][i] + i;
      if (nh < 0 || nt < i) continue;
      if (nh > MAXDELT + r + 1 || nt > MAXDELT + r + 1) continue;
      if (result[nh][nt] != 2) continue;
      d[nh][nt]--;
      if (result[h][t] == 0 || d[nh][nt] == 0) {
        dest[nh][nt] = dest[h][t] + 1;
        result[nh][nt] = result[h][t];
        q.push(make_pair(nh, nt));
      }
    }
  }
  cout << outcomes[2] << endl;
}
int main() {
  read();
  solve();
  return 0;
}
