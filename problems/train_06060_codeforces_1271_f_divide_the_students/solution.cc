#include <bits/stdc++.h>
using namespace std;
int t, p[7], a[2], b[2], c[2], res[7];
inline void solve() {
  for (int i = 0; i <= p[1]; ++i)
    if (i <= a[0] && i <= b[0] && p[1] - i <= a[1] && p[1] - i <= b[1])
      for (int j = 0; j <= p[2]; ++j)
        if (i + j <= a[0] && j <= c[0] && p[1] - i + p[2] - j <= a[1] &&
            p[2] - j <= c[1])
          for (int k = 0; k <= p[4]; ++k)
            if (i + k <= b[0] && j + k <= c[0] && p[1] - i + p[4] - k <= b[1] &&
                p[2] - j + p[4] - k <= c[1]) {
              int a0 = a[0] - i - j;
              int b0 = b[0] - i - k;
              int c0 = c[0] - j - k;
              int a1 = a[1] - p[1] + i - p[2] + j;
              int b1 = b[1] - p[1] + i - p[4] + k;
              int c1 = c[1] - p[2] + j - p[4] + k;
              if (min(a0, min(b0, c0)) + min(a1, min(b1, c1)) < p[0]) continue;
              if (a0 + a1 < p[0] + p[3] || b0 + b1 < p[0] + p[5] ||
                  c0 + c1 < p[0] + p[6])
                continue;
              res[0] = min(p[0], min(a0, min(b0, c0)));
              res[1] = i;
              res[2] = j;
              res[4] = k;
              res[3] = min(p[3], a[0] - res[0] - res[1] - res[2]);
              res[5] = min(p[5], b[0] - res[0] - res[1] - res[4]);
              res[6] = min(p[6], c[0] - res[0] - res[2] - res[4]);
              for (int o = 0; o < 7; ++o)
                printf("%d%c", res[o], o + 1 == 7 ? '\n' : ' ');
              return;
            }
  puts("-1");
}
int main() {
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 2; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < 7; ++i) scanf("%d", &p[i]);
    solve();
  }
  return 0;
}
