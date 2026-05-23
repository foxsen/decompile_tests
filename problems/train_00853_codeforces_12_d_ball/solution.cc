#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 5;
struct Titem {
  int a, b, c;
} p[MAXN];
int n, cmax[MAXN], tmp[MAXN], ans = 0;
bool cmpb(Titem p, Titem q) { return p.b > q.b; }
void modify(int i, int v) {
  for (; i <= n; cmax[i] = max(cmax[i], v), i += i & -i)
    ;
}
int getmax(int i) {
  int res = -1;
  for (; i; res = max(res, cmax[i]), i -= i & -i)
    ;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].a), tmp[i] = p[i].a;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].c);
  sort(tmp + 1, tmp + n + 1);
  int last = unique(tmp + 1, tmp + n + 1) - tmp;
  for (int i = 1; i <= n; i++)
    p[i].a = n - (lower_bound(tmp + 1, tmp + last, p[i].a) - tmp) + 1;
  sort(p + 1, p + n + 1, cmpb);
  memset(cmax, -1, sizeof(cmax));
  for (int i = 1, j = 1; i <= n; i++) {
    for (; p[j].b > p[i].b; modify(p[j].a, p[j].c), j++)
      ;
    ans += getmax(p[i].a - 1) > p[i].c;
  }
  printf("%d\n", ans);
  return 0;
}
