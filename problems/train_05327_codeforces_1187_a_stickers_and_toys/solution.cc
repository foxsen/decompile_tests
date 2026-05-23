#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * f;
}
int main() {
  int T = read();
  while (T--) {
    int N = read(), S = read(), T = read();
    printf("%d\n", max(N - S, N - T) + 1);
  }
}
