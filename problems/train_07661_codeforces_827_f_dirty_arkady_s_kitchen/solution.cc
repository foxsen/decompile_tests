#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
struct E {
  int v, l, r;
  E(int v = 0, int l = 0, int r = 0) : v(v), l(l), r(r) {}
  bool operator<(const E &e) const {
    if (l != e.l) return l < e.l;
    return r < e.r;
  }
};
vector<E> adj[1000100];
int cur[1000100];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
               greater<pair<pair<int, int>, int> > >
    q;
void zou(int u, int tl, int tr) {
  if (cur[u] == adj[u].size()) return;
  E &e = adj[u][cur[u]];
  if (e.l > tr) return;
  cur[u]++;
  if (tl <= e.r)
    q.push(pair<pair<int, int>, int>(pair<int, int>(max(tl, e.l) + 1, e.r + 1),
                                     e.v));
  zou(u, tl, tr);
}
int main() {
  int n, m;
  gn(n, m);
  for (int i = 0; i < m; i++) {
    int u, v, l, r;
    gn(u, v);
    gn(l, r);
    r--;
    if (!(l == r && l % 2 == 1)) {
      adj[u].push_back(E(n + v, l + (l & 1), r - (r & 1)));
      adj[v].push_back(E(n + u, l + (l & 1), r - (r & 1)));
    }
    if (!(l == r && l % 2 == 0)) {
      adj[n + u].push_back(E(v, l + (~l & 1), r - (~r & 1)));
      adj[n + v].push_back(E(u, l + (~l & 1), r - (~r & 1)));
    }
  }
  for (int i = 1; i <= n << 1; i++) sort(adj[i].begin(), adj[i].end());
  int ans = -1;
  q.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 1));
  while (!q.empty()) {
    pair<pair<int, int>, int> now = q.top();
    q.pop();
    if ((now.second == n || now.second == n << 1) &&
        (ans == -1 || ans > now.first.first))
      ans = now.first.first;
    zou(now.second, now.first.first, now.first.second);
  }
  printf("%d\n", ans);
  return 0;
}
