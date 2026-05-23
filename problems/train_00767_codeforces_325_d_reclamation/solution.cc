#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int Maxn = 3005, Maxm = 300005, Mo = 1000000007,
          sp[8][2] = {{0, 1}, {0, -1},  {1, 0},  {-1, 0},
                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
const long long oo = INT_MAX >> 2;
struct Tree {
  int l, r, cnt;
};
struct edge {
  int u, v, len;
};
struct point {
  long long x, y, id;
};
typedef int IArr[Maxm * 2];
typedef long long LArr[Maxn];
typedef double DArr[Maxn];
IArr f;
int n, m, c, i, j, x, y, ans;
int mp[Maxn][Maxn * 2];
int gf(int w) {
  if (f[w] == w) return w;
  return f[w] = gf(f[w]);
}
int in(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m * 2); }
void fd(vector<int>& p, int x, int y) {
  p.clear();
  for (int i = 0; i < 8; i++) {
    int cx = x + sp[i][0];
    int cy = y + sp[i][1];
    if (cy < 1) cy = 2 * m;
    if (cy > 2 * m) cy = 1;
    if (!in(cx, cy) || !mp[cx][cy]) continue;
    int a = gf(mp[cx][cy]);
    p.push_back((a));
  }
}
int ck(int x, int y) {
  vector<int> p1, p2;
  fd(p1, x, y);
  fd(p2, x, y + m);
  for (int i = 0; i < p1.size(); i++)
    for (int j = 0; j < p2.size(); j++)
      if (p1[i] == p2[j]) return 0;
  return 1;
}
void alt(int id, int x, int y) {
  mp[x][y] = id;
  for (int i = 0; i < 8; i++) {
    int cx = x + sp[i][0];
    int cy = y + sp[i][1];
    if (cy < 1) cy = 2 * m;
    if (cy > 2 * m) cy = 1;
    if (!in(cx, cy) || !mp[cx][cy]) continue;
    int a = gf(mp[cx][cy]);
    f[a] = id;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> c;
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (i = 1; i <= c; i++) {
    cin >> x >> y;
    if (mp[x][y]) {
      ans++;
      continue;
    }
    f[i] = i;
    f[i + c] = i + c;
    if (ck(x, y)) {
      ans++;
      alt(i, x, y);
      alt(i + c, x, y + m);
    }
  }
  cout << ans << endl;
}
