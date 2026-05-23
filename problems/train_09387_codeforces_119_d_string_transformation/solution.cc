#include <bits/stdc++.h>
using namespace std;
const int prime = 37;
const int maxn = 1100000;
char a[maxn], b[maxn];
int ha[maxn], hb[maxn], hc[maxn], pp[maxn];
int ll[maxn], rr[maxn];
int n;
int main() {
  gets(a);
  gets(b);
  n = strlen(a);
  if (n != (int)strlen(b) || n <= 1) {
    puts("-1 -1");
    return 0;
  }
  pp[0] = 1;
  ha[0] = 0;
  hb[0] = 0;
  hc[n] = 0;
  for (int i = 0; i < (n); ++i) {
    pp[i + 1] = pp[i] * prime;
    ha[i + 1] = ha[i] * prime + a[i];
    hb[i + 1] = hb[i] * prime + b[i];
    hc[n - i - 1] = hc[n - i] * prime + a[n - i - 1];
  }
  for (int i = 0; i < (n); ++i) {
    int st = 0, ed = n - i;
    while (st <= ed) {
      int mi = (st + ed) >> 1;
      if (hc[n - mi] == hb[i + mi] - hb[i] * pp[mi])
        st = mi + 1;
      else
        ed = mi - 1;
    }
    rr[i] = ed;
  }
  for (int i = 0, j = 0; i < n; i++) {
    while (j < rr[i] + i) {
      ll[j] = i;
      j++;
    }
  }
  int pi = -1, pj = -1;
  for (int i = 0; i < (n - 1); ++i) {
    if (a[i] != b[n - i - 1]) break;
    int z = ll[n - i - 2];
    if (z > n - i - 2) continue;
    if (ha[i + z + 1] - ha[i + 1] * pp[z] == hb[z]) {
      pi = i;
      pj = i + z + 1;
    }
  }
  printf("%d %d\n", pi, pj);
  return 0;
}
