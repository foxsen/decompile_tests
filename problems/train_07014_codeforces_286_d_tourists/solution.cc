#include <bits/stdc++.h>
using namespace std;
inline int get() {
  char c;
  while (!isdigit(c = getchar()))
    ;
  int v = c - 48;
  while (isdigit(c = getchar())) v = v * 10 + c - 48;
  return v;
}
int n, m, k, p, i, ll, lt, tt, o[400001], s[400001], v[400001];
map<int, int> Mp;
struct Ar {
  int l;
  bool i;
  const bool operator<(const Ar &h) const {
    return (l << 1) - i < (h.l << 1) - h.i;
  };
} ar[400001];
struct El : Ar {
  int t;
} el[100001 << 1];
int main() {
  m = get();
  n = get();
  for (i = 0; i < n; i++) {
    el[i + i].l = get();
    el[i + i + 1].l = get();
    el[i + i].t = el[i + i + 1].t = get();
    el[i + i].i = 1;
  }
  sort(el, el + n + n);
  lt = (1 << 30);
  Mp[(1 << 30)] = 1;
  for (i = 0; i < n + n; i++) {
    if (el[i].i)
      Mp[el[i].t]++;
    else if ((--Mp[el[i].t]) == 0)
      Mp.erase(el[i].t);
    if ((tt = Mp.begin()->first) != lt && lt != (1 << 30)) {
      ar[k].l = ll - lt;
      ar[k++].i = 1;
      ar[k++].l = (ll = el[i].l) - lt;
    } else if (lt == (1 << 30))
      ll = el[i].l;
    lt = tt;
  }
  sort(ar, ar + k);
  o[0] = 1;
  v[0] = ar[0].l;
  for (i = 1; i < k; i++) {
    v[i] = ar[i].l;
    o[i] = o[i - 1] + (ar[i].i ? 1 : -1);
    s[i] = s[i - 1] + o[i - 1] * (ar[i].l - ar[i - 1].l);
  }
  for (i = 1; i <= m; i++) {
    if ((tt = upper_bound(v, v + k, p = -get()) - v - 1) < 0) {
      printf("%d\n", s[k - 1]);
      continue;
    }
    printf("%d\n", s[k - 1] - s[tt] - o[tt] * (p - v[tt]));
  }
  return 0;
}
