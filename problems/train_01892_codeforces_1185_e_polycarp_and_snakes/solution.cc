#include <bits/stdc++.h>
using namespace std;
int n, m;
int T;
char a[4000][4000];
vector<pair<int, int> > v[30];
int ans[30][4], x = 0;
bool res = 1;
void work(int x) {
  if (v[x].size() == 0) return;
  if (v[x].size() == 1) {
    ans[x][0] = ans[x][2] = v[x][0].first,
    ans[x][1] = ans[x][3] = v[x][0].second;
    return;
  }
  bool p1 = true, p2 = true;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i].first != v[x][0].first) p1 = false;
    if (v[x][i].second != v[x][0].second) p2 = false;
  }
  if (!p1 && !p2) {
    res = 0;
    return;
  }
  int minn = 19260817, maxx = -6291;
  if (p1) {
    for (int i = 0; i < v[x].size(); i++)
      minn = min(minn, v[x][i].second), maxx = max(maxx, v[x][i].second);
    for (int i = minn; i <= maxx; i++)
      if (a[v[x][0].first][i] < (x + 'a')) {
        res = 0;
        return;
      }
    ans[x][0] = ans[x][2] = v[x][0].first, ans[x][1] = minn, ans[x][3] = maxx;
  } else {
    for (int i = 0; i < v[x].size(); i++)
      minn = min(minn, v[x][i].first), maxx = max(maxx, v[x][i].first);
    for (int i = minn; i <= maxx; i++)
      if (a[i][v[x][0].second] < (x + 'a')) {
        res = 0;
        return;
      }
    ans[x][1] = ans[x][3] = v[x][0].second, ans[x][0] = minn, ans[x][2] = maxx;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    int u = -1;
    res = 1;
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < 29; i++) v[i].clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int r = 1; r <= m; r++) {
        cin >> a[i][r];
        if (a[i][r] >= 'a' && a[i][r] <= 'z')
          u = max(u, a[i][r] - 'a'),
          v[a[i][r] - 'a'].push_back(make_pair(i, r));
      }
    for (int i = 0; i < 26; i++) work(i);
    if (!res) {
      puts("NO");
      continue;
    }
    puts("YES");
    cout << u + 1 << endl;
    for (int i = u; i >= 0; i--)
      if (v[i].size() == 0)
        for (int r = 0; r < 4; r++) ans[i][r] = ans[i + 1][r];
    for (int i = 0; i <= u; i++) {
      for (int r = 0; r < 4; r++) printf("%d ", ans[i][r]);
      putchar('\n');
    }
  }
}
