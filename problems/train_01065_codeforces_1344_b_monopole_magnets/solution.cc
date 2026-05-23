#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int m1[maxn][maxn], m2[maxn][maxn];
bool hang[maxn], lie[maxn], have;
int ans, n, m;
int dxy[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> p;
char ch;
inline bool ju1() {
  bool b1 = 0, b2 = 0;
  for (int i = 1; i <= n; i++)
    if (!hang[i]) {
      b1 = 1;
      break;
    }
  for (int i = 1; i <= m; i++)
    if (!lie[i]) {
      b2 = 1;
      break;
    }
  if (b1 && b2) return 1;
  if (!b1 && !b2) return 1;
  return 0;
}
inline bool ju2(int xx, int yy) {
  queue<pair<int, int> > q;
  q.push({xx, yy});
  int a = inf, b = -inf, c = inf, d = -inf;
  while (q.size()) {
    p = q.front();
    q.pop();
    int x = p.first, y = p.second;
    if (x < 1 || x > n || y < 1 || y > m || m1[x][y] || m2[x][y]) continue;
    m2[x][y] = 1;
    m1[x][y] = 1;
    for (int _ = 0; _ < 3; _++) {
      if (!m1[x + dxy[_][0]][y + dxy[_][1]])
        q.push({x + dxy[_][0], y + dxy[_][1]});
    }
  }
  a = 1, b = n, c = 1, d = m;
  for (int i = a; i <= b; i++) {
    int tmp = -1;
    for (int j = c; j <= d; j++) {
      if (m2[i][j]) {
        if (tmp == -1 || j == tmp + 1) {
          tmp = j;
        } else {
          return 0;
        }
      }
    }
  }
  for (int i = c; i <= d; i++) {
    int tmp = -1;
    for (int j = a; j <= b; j++) {
      if (m2[j][i]) {
        if (tmp == -1 || j == tmp + 1) {
          tmp = j;
        } else {
          return 0;
        }
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == '.') {
        m1[i][j] = 1;
      } else {
        have = 1;
        hang[i] = 1;
        lie[j] = 1;
      }
    }
  }
  if (!ju1())
    cout << "-1"
         << "\n";
  else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!m1[i][j]) {
          if (ju2(i, j))
            ans++;
          else {
            ans = -1;
            break;
          }
        }
      }
      if (ans == -1) break;
    }
    cout << ans << "\n";
  }
  return 0;
}
