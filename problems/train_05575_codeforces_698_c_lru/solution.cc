#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x);
template <typename T>
void write(T x);
template <typename T>
void writesp(T x);
template <typename T>
void writeln(T x);
const int N = 1ull << 21, M = 22;
double f[N];
int n, s, k;
double P[M], sum[N], p[M];
inline int pop_count(int x) {
  int res = 0;
  while (x) {
    if (x & 1) ++res;
    x >>= 1;
  }
  return res;
}
double res[M];
int cnt, pos[M];
int main() {
  read(n);
  read(k);
  for (register int i = 1; i <= n; i++) scanf("%lf", &P[i]);
  for (register int i = 1; i <= n; i++) {
    if (P[i] > .0) p[++cnt] = P[i], pos[cnt] = i;
  }
  (k = min(k, cnt));
  s = (1ll << cnt);
  for (register int i = 1; i < s; i++)
    for (register int j = 0; j < cnt; j++)
      if (i >> j & 1) sum[i] += p[j + 1];
  f[0] = 1.0;
  for (register int i = 1; i < s; i++) {
    for (register int j = 0; j < cnt; j++) {
      if ((i >> j & 1))
        f[i] += f[i ^ (1 << j)] * p[j + 1] / (1.0 - sum[i ^ (1 << j)]);
    }
  }
  for (register int i = 1; i < s; i++) {
    if (pop_count(i) == k) {
      for (register int j = 0; j < cnt; j++) {
        if (i >> j & 1) res[pos[j + 1]] += f[i];
      }
    }
  }
  for (register int i = 1; i <= n; i++) printf("%.6f ", res[i]);
  putchar('\n');
}
template <typename T>
void read(T &x) {
  x = 0;
  int t = 1;
  char wn = getchar();
  while (wn < '0' || wn > '9') {
    if (wn == '-') t = -1;
    wn = getchar();
  }
  while (wn >= '0' && wn <= '9') {
    x = x * 10 + wn - '0';
    wn = getchar();
  }
  x *= t;
}
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x <= 9) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writesp(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
