#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
const int mod = 1e9 + 7;
inline int read() {
  int ret = 0, op = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * op;
}
inline long long readll() {
  long long ret = 0, op = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * op;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline int Max(const int e, const int f) { return e > f ? e : f; }
int xr[N];
int main() {
  for (register int i = 1; i <= 3e5; i++) xr[i] = xr[i - 1] ^ i;
  int t = read();
  while (t--) {
    int a = read();
    int b = read();
    if (xr[a - 1] == b)
      printf("%d\n", a);
    else {
      if ((xr[a - 1] ^ b) == a) {
        printf("%d\n", a + 2);
      } else
        printf("%d\n", a + 1);
    }
  }
  return 0;
}
