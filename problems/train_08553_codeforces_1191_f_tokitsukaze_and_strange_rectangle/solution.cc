#include <bits/stdc++.h>
using namespace std;
int n, k, p[(int)2e5 + 5], tree[(int)8e5 + 5];
pair<int, int> inp[(int)2e5 + 5];
long long ans;
int f(int x) { return lower_bound(p + 1, p + 1 + k, x) - p; }
int update(int i, int t, int nl, int nr) {
  if (i < nl || nr < i) return tree[t];
  if (nl == nr) return tree[t] = 1;
  int m = nl + nr >> 1;
  return tree[t] = update(i, t * 2, nl, m) + update(i, t * 2 + 1, m + 1, nr);
}
long long get(int ql, int qr, int t, int nl, int nr) {
  if (qr < ql) return 0;
  if (nr < ql || qr < nl) return 0;
  if (ql <= nl && nr <= qr) return tree[t];
  int m = nl + nr >> 1;
  return get(ql, qr, t * 2, nl, m) + get(ql, qr, t * 2 + 1, m + 1, nr);
}
long long calc(long long x) { return x * (x + 1) >> 1; }
int main(void) {
  scanf("%d", &n);
  for (int i = 1, a, b; i <= n; i++) {
    scanf("%d %d", &a, &b);
    inp[i] = {-b, a};
    p[i] = a;
  }
  sort(p + 1, p + 1 + n);
  sort(inp + 1, inp + 1 + n);
  k = unique(p + 1, p + 1 + n) - (p + 1);
  for (int i = 1; i <= n; i++) {
    update(f(inp[i].second), 1, 1, k);
    if (inp[i].first != inp[i + 1].first) {
      ans -= calc(get(f(inp[i].second) + 1, k, 1, 1, k));
      ans += calc(get(1, k, 1, 1, k));
    }
    int st;
    if (inp[i - 1].first != inp[i].first)
      st = 0;
    else
      st = f(inp[i - 1].second);
    ans -= calc(get(st + 1, f(inp[i].second) - 1, 1, 1, k));
  }
  printf("%lld\n", ans);
}
