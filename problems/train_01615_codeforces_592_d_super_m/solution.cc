#include <bits/stdc++.h>
using namespace std;
const int maxn = 124000;
bool tag[maxn];
vector<int> v1[maxn], v2[maxn];
int a[maxn];
bool check[maxn];
int d;
bool Go(int x, int fa) {
  for (int i = 0; i < v1[x].size(); i++) {
    if (fa == v1[x][i]) continue;
    if (Go(v1[x][i], x)) {
      v2[x].push_back(v1[x][i]);
      v2[v1[x][i]].push_back(x);
    }
  }
  if (tag[x] || v2[x].size()) return true;
  return false;
}
void print(int x, int fa) {
  printf("%d ", x);
  for (int i = 0; i < v2[x].size(); i++) {
    if (v2[x][i] == fa) continue;
    print(v2[x][i], x);
  }
  return;
}
struct point {
  int x;
  int t;
  friend bool operator<(point a, point b) {
    if (a.t != b.t) return a.t > b.t;
    return a.x < b.x;
  }
  point(int _x = 0, int _t = 0) : x(_x), t(_t) {}
};
priority_queue<point> q;
int bfs(int x) {
  while (!q.empty()) q.pop();
  memset(check, 0, sizeof(check));
  q.push(point(x, 0));
  check[x] = 1;
  point p;
  int t;
  while (!q.empty()) {
    p = q.top();
    q.pop();
    x = p.x;
    t = p.t;
    for (int i = 0; i < v2[x].size(); i++) {
      if (!check[v2[x][i]]) {
        check[v2[x][i]] = 1;
        q.push(point(v2[x][i], t + 1));
      }
    }
  }
  d = t;
  return x;
}
int getson(int x, int fa) {
  int ans = 0;
  for (int i = 0; i < v2[x].size(); i++) {
    if (v2[x][i] == fa) continue;
    ans += getson(v2[x][i], x);
  }
  return ans + 1;
}
int main() {
  int n, m;
  int l, r;
  int ansnum;
  while (~scanf("%d%d", &n, &m)) {
    memset(tag, 0, sizeof(tag));
    for (int i = 1; i <= n; i++) {
      v1[i].clear();
      v2[i].clear();
    }
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &l, &r);
      v1[l].push_back(r);
      v1[r].push_back(l);
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
      tag[a[i]] = 1;
    }
    sort(a + 1, a + m + 1);
    Go(a[1], -1);
    l = bfs(a[1]);
    r = bfs(l);
    ansnum = (getson(a[1], -1) - 1) * 2 - d;
    printf("%d\n%d\n", min(l, r), ansnum);
  }
  return 0;
}
