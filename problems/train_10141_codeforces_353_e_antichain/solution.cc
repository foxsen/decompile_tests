#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
inline long long read() {
  long long t = 0, dp = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') dp = -1;
    c = getchar();
  }
  while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
  return t * dp;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void write_p(long long x) {
  write(x);
  putchar(' ');
}
const int N = 1e6 + 5;
int n, top, q[N], ans;
char s[N];
int main() {
  scanf("\n%s", s + 1);
  n = strlen(s + 1);
  top = 1;
  q[top] = 1;
  for (int i = 2; i <= n; ++i) {
    if (s[i] != s[i - 1])
      q[++top] = 1;
    else
      q[top] = 0;
  }
  if (s[n] == s[1]) top--, q[1] = 0;
  int lx = 0;
  for (int i = 1; i <= top; ++i)
    if (q[i] == 1)
      lx++;
    else
      ans += lx / 2 + 1, lx = 0;
  ans += lx / 2;
  writeln(ans);
}
