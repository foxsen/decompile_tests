#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100002;
bool flag;
struct Node {
  int x;
  int p;
  bool operator<(const Node& o) const {
    if (x != o.x) {
      return x < o.x;
    } else if (flag) {
      return p < o.p;
    } else {
      return p > o.p;
    }
  }
} node[MaxN];
int ans[MaxN];
int n;
int a, b;
void solve() {
  int aa = 1, bb = 2;
  if (a > b) {
    flag = true;
    sort(node, node + n);
  } else if (a < b) {
    flag = false;
    sort(node, node + n);
    aa = 2;
    bb = 1;
    a = b;
  }
  int i;
  for (i = 0; i < a; i++) {
    ans[node[i].p] = aa;
  }
  for (; i < n; i++) {
    ans[node[i].p] = bb;
  }
  return;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    scanf("%d%d", &a, &b);
    int i;
    for (i = 0; i < n; i++) {
      scanf("%d", &node[i].x);
      node[i].p = i;
    }
    solve();
    for (i = 0; i < n - 1; i++) {
      printf("%d ", ans[i]);
    }
    printf("%d\n", ans[i]);
  }
  return 0;
}
