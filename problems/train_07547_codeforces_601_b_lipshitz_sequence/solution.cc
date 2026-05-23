#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int, int>;
constexpr int MAX = 100010;
constexpr int INF = 0x3F3F3F3F;
unordered_map<int, int> mp;
int a[MAX], b[MAX], ll[MAX], rr[MAX], pre[MAX], stk[MAX], top;
i64 Solve(int l, int r) {
  int n = 0;
  for (int i = l; i < r; ++i) {
    b[++n] = abs(a[i] - a[i + 1]);
  }
  fill(pre, pre + n + 2, -1);
  b[0] = INF;
  b[n + 1] = INF;
  ll[0] = 0;
  top = 0;
  stk[++top] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    for (; top && b[stk[top]] < b[i]; --top) {
      rr[stk[top]] = i;
    }
    if (b[stk[top]] == b[i]) {
      ll[i] = ll[stk[top]];
      pre[i] = stk[top];
    } else {
      ll[i] = stk[top];
    }
    stk[++top] = i;
  }
  i64 ret = 0;
  for (int i = 1; i <= n; ++i) {
    i64 lw = (i64)(i - max(ll[i], pre[i]));
    i64 rw = (i64)(rr[i] - i);
    ret += lw * rw * (i64)b[i];
  }
  return ret;
}
int main() {
  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      cout << Solve(l - 1, r - 1) << endl;
    }
  }
  return 0;
}
