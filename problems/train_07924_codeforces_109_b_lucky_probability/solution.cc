#include <bits/stdc++.h>
using namespace std;
int pl, pr, vl, vr, k, tot, a[1050];
void dfs(int num) {
  if (num) a[++tot] = num;
  if (num * 10ll + 4 <= max(pr, vr)) dfs(num * 10 + 4);
  if (num * 10ll + 7 <= max(pr, vr)) dfs(num * 10 + 7);
}
int main() {
  cin >> pl >> pr >> vl >> vr >> k;
  dfs(0);
  sort(a + 1, a + 1 + tot);
  if (k > tot) return puts("0"), 0;
  int64_t sum = (pr - pl + 1) * (vr - vl + 1ll), now = 0;
  auto gao = [](int a, int b, int c, int d) {
    int l = max(a, c), r = min(b, d);
    if (l <= r) return r - l + 1;
    return 0;
  };
  for (int l = 1, r = k; r <= tot; ++l, ++r) {
    int l1 = l == 1 ? 1 : a[l - 1] + 1, r1 = a[l];
    int l2 = a[r], r2 = r == tot ? max(pr, vr) : a[r + 1] - 1;
    now += gao(l1, r1, pl, pr) * (int64_t)gao(l2, r2, vl, vr);
    now += gao(l1, r1, vl, vr) * (int64_t)gao(l2, r2, pl, pr);
    if (k == 1 && pl <= a[l] && a[l] <= pr && vl <= a[l] && a[l] <= vr) --now;
  }
  printf("%.15lf\n", now / (double)sum);
}
