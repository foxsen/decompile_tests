#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};
struct node {
  long long x, y;
  node() {}
  node(long long x, long long y) : x(x), y(y) {}
  bool operator<(const node& p) const { return x < p.x; }
};
node a[100005];
bool vis[1004][1005];
int main() {
  long long i, j, k, l, x, y, z, t, m, n;
  scanf("%lld %lld", &n, &m);
  scanf("%lld", &k);
  memset(vis, 0, sizeof(vis));
  for (i = 1; i <= n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);
  for (i = 1; i <= m; i++) {
    scanf("%lld %lld %lld", &x, &y, &z);
    for (j = 1; j <= n; j++) {
      t = (((a[j].x - y)) * ((a[j].x - y))) + (((a[j].y - z)) * ((a[j].y - z)));
      if (t <= (x * x)) vis[j][i] = 1;
    }
  }
  for (i = 1; i <= k; i++) {
    scanf("%lld %lld", &x, &y);
    z = 0;
    for (j = 1; j <= m; j++) {
      if (vis[x][j] != vis[y][j]) z++;
    }
    deb(z);
  }
  return 0;
}
