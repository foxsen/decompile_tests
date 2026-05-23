#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node a) const {
    if (y == a.y)
      return x < a.x;
    else
      return y > a.y;
  }
} a[200005];
int n, m, xx[200005], yy[200005];
long long ans, tree[200005];
bool vis[200005];
int lowbit(int x) { return x & (-x); }
void update(int x) {
  for (int i = x; i <= n; i += lowbit(i)) tree[i]++;
}
long long find(int x) {
  long long ans = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) ans += tree[i];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    xx[i] = a[i].x;
    yy[i] = a[i].y;
  }
  sort(xx + 1, xx + 1 + n);
  sort(yy + 1, yy + 1 + n);
  int cntx = unique(xx + 1, xx + 1 + n) - xx - 1;
  int cnty = unique(yy + 1, yy + 1 + n) - yy - 1;
  for (int i = 1; i <= n; i++) {
    a[i].x = lower_bound(xx + 1, xx + 1 + cntx, a[i].x) - xx;
    a[i].y = lower_bound(yy + 1, yy + 1 + cnty, a[i].y) - yy;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (i < n && a[i].y == a[i + 1].y) {
      if (!vis[a[i].x]) {
        update(a[i].x);
        vis[a[i].x] = 1;
      }
      continue;
    }
    if (!vis[a[i].x]) {
      update(a[i].x);
      vis[a[i].x] = 1;
    }
    int t = i;
    while (a[t - 1].y == a[t].y && t > 1) t--;
    int ind = 0;
    for (int j = t; j <= i; j++) {
      ans += (find(n) - find(a[j].x - 1)) * (find(a[j].x) - find(ind));
      ind = a[j].x;
    }
  }
  printf("%lld", ans);
}
