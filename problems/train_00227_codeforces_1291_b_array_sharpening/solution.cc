#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int inf = 2147483647 - 1;
const int maxn = 3e5 + 10;
int a[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    int l, r;
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= i - 1)
        l = i;
      else
        break;
    }
    for (int i = n; i; --i) {
      if (a[i] >= n - i)
        r = i;
      else
        break;
    }
    if (l >= r)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
