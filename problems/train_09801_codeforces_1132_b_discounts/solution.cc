#include <bits/stdc++.h>
namespace FASTIO {
char buf[1 << 21];
char *p1, *p2;
template <typename T>
inline void wt(T x, char c = '\n') {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  static char sta[sizeof(T) * 8];
  T top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + '0');
  putchar(c);
}
template <typename T>
inline T rd() {
  T sum = 0, fl = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  for (; ch < '0' || ch > '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-')
      fl = -1;
    else if (ch == EOF)
      exit(0);
  for (; '0' <= ch && ch <= '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    sum = sum * 10 + ch - '0';
  return sum * fl;
}
}  // namespace FASTIO
using namespace FASTIO;
int main() {
  int n = rd<int>(), *a;
  uint64_t sum = 0;
  a = new int[n];
  for (int i = 0; i < n; i++) sum += a[i] = rd<int>();
  std::sort(a, a + n, std::greater<int>());
  for (int m = rd<int>(); m--;) wt(sum - a[rd<int>() - 1]);
  delete a;
  return 0;
}
