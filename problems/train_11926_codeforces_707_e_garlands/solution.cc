#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-4;
const long long mod = 1e9 + 7;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
long long c[2005][2005];
int n, m;
void add(int x, int y, int w) {
  for (int i = x; i <= n; i += (i & -i)) {
    for (int j = y; j <= m; j += (j & -j)) {
      c[i][j] += w;
    }
  }
}
long long sum(int x, int y) {
  long long ret = 0;
  for (int i = x; i > 0; i -= (i & -i)) {
    for (int j = y; j > 0; j -= (j & -j)) {
      ret += c[i][j];
    }
  }
  return ret;
}
vector<pair<pair<int, int>, int> > v[2005];
int vis[2005];
int last[2005];
int main() {
  int k;
  while (cin >> n >> m >> k) {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= k; i++) {
      v[i].clear();
      int len;
      scanf("%d", &len);
      while (len--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[i].push_back(make_pair(make_pair(a, b), c));
        add(a, b, c);
      }
    }
    int q;
    cin >> q;
    memset(last, 0, sizeof(last));
    memset(vis, 0, sizeof(vis));
    while (q--) {
      char op[10];
      scanf("%s", op);
      if (op[0] == 'S') {
        int a;
        scanf("%d", &a);
        vis[a] ^= 1;
      } else {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = 1; i <= k; i++) {
          if (last[i] != vis[i]) {
            for (int j = 0; j < v[i].size(); j++) {
              if (vis[i])
                add(v[i][j].first.first, v[i][j].first.second, -v[i][j].second);
              else
                add(v[i][j].first.first, v[i][j].first.second, v[i][j].second);
            }
            last[i] = vis[i];
          }
        }
        long long ans = sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +
                        sum(x1 - 1, y1 - 1);
        cout << ans << endl;
      }
    }
  }
  return 0;
}
