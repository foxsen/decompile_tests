#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
const double eps = 1e-9;
struct node {
  int x, y;
  node operator+(const node &q) const { return node{x + q.x, y + q.y}; }
  node operator-(const node &q) const { return node{x - q.x, y - q.y}; }
  bool operator==(const node &q) const { return x == q.x && y == q.y; }
  long long len_2() { return x * x + y * y; }
  void print() {
    printf("%d %d\n", x, y);
    return;
  }
} a[N], b[N], p[N];
int dj(node x, node y) { return x.x * y.x + x.y * y.y; }
int cj(node x, node y) { return x.x * y.y - x.y * y.x; }
int n, m;
bool cal(node x, node y) {
  double l = -1e9, r = 1e9;
  for (int i = 1; i <= n; i++) {
    node op1 = x - a[i], op2 = y - a[i];
    if (cj(op1, op2) == 0) continue;
    double op = 1.0 * dj(op1, op2) / cj(op1, op2);
    if (cj((a[i] - x), (y - x)) < 0)
      l = max(l, op);
    else
      r = min(r, op);
  }
  for (int i = 1; i <= m; i++) {
    node op1 = x - b[i], op2 = y - b[i];
    if (cj(op1, op2) == 0) {
      if (b[i].x >= min(x.x, y.x) && b[i].x <= max(x.x, y.x) &&
          b[i].y >= min(x.y, y.y) && b[i].y <= max(x.y, y.y))
        return 0;
      continue;
    }
    double op = 1.0 * dj(op1, op2) / cj(op1, op2);
    if (cj((b[i] - x), (y - x)) > 0)
      l = max(l, op);
    else
      r = min(r, op);
  }
  return l + eps < r;
}
bool dfs(int l, int r) {
  if (l == r - 1) return 0;
  int mid;
  double op = 1e9;
  for (int i = l + 1; i <= r - 1; i++) {
    node op1 = p[i] - p[l], op2 = p[i] - p[r];
    double x = 1.0 * dj(op1, op2) / cj(op1, op2);
    if (x < op) op = x, mid = i;
  }
  return cal(p[l], p[mid]) || cal(p[r], p[mid]) || dfs(l, mid) || dfs(mid, r);
}
bool cmp1(node x, node y) { return x.x == y.x ? x.y < y.y : x.x < y.x; }
bool cmp2(node x, node y) {
  node op1 = x - a[1], op2 = y - a[1];
  int op = cj(op1, op2);
  return op == 0 ? op1.len_2() < op2.len_2() : op > 0;
}
bool check() {
  sort(a + 1, a + n + 1, cmp1);
  sort(a + 2, a + n + 1, cmp2);
  int top = 0;
  p[++top] = a[1], p[++top] = a[2];
  for (int i = 3; i <= n; i++) {
    while (top >= 2 && cj((a[i] - p[top - 1]), (p[top] - p[top - 1])) >= 0)
      top--;
    p[++top] = a[i];
  }
  return cal(p[1], p[top]) || dfs(1, top);
}
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 || m == 1) return puts("YES"), 0;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].x, &b[i].y);
  bool flag = check();
  swap(a, b);
  swap(n, m);
  flag |= check();
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
