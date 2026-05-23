#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  char c;
  int f = 1;
  while ((c = getchar()) != '-' && (c > '9' || c < '0'))
    ;
  if (c == '-') f = -1, c = getchar();
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ '0');
  return x * f;
}
inline long long readll() {
  long long x;
  char c;
  int f = 1;
  while ((c = getchar()) != '-' && (c > '9' || c < '0'))
    ;
  if (c == '-') f = -1, c = getchar();
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1ll) + (x << 3ll) + (c ^ '0');
  return x * f;
}
const int maxn = 4e6 + 10;
int s1[maxn], s2[maxn], t1, t2, tmp;
long long b[maxn], a[maxn];
int main() {
  int n = read(), k = read();
  for (register int i = 1, iend = n; i <= iend; ++i) a[i] = readll();
  for (int i = 1, j = 1; i < n; ++j, i = j) {
    while (j <= n && a[j + 1] >= a[j]) ++j;
    if (i == j) continue;
    while (t1 && a[s1[t1]] >= a[i])
      b[++tmp] = a[s1[t1]] - a[s2[t2]], --t1, --t2;
    s1[++t1] = i;
    while (t2 && a[s2[t2]] <= a[j])
      b[++tmp] = a[s1[t1]] - a[s2[t2]], --t1, --t2;
    s2[++t2] = j;
  }
  while (t1) b[++tmp] = a[s1[t1]] - a[s2[t2]], --t1, --t2;
  k = min(k, tmp);
  nth_element(b + 1, b + k, b + tmp + 1);
  long long ans = 0;
  for (register int i = 1, iend = k; i <= iend; ++i) ans -= b[i];
  printf("%lld\n", ans);
  return 0;
}
