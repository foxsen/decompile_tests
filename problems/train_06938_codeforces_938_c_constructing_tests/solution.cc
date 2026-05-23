#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int q;
    scanf("%d", &q);
    if (q == 0) {
      printf("1 1\n");
      continue;
    }
    int n = 0, m = 0, ch = 0, x = 1;
    for (int i = 1; i <= sqrt(q); i++) {
      if (q % i) continue;
      int pp = q / i;
      if ((pp + i) % 2 == 0) {
        n = (pp + i) / 2;
        m = n - i;
        for (int i = 1; i <= n; i++) {
          if (n / i == m) {
            m = i;
            ch = 1;
            break;
          }
          if (n / i < m) break;
        }
      }
      if (ch == 1) break;
    }
    if (ch == 0)
      puts("-1");
    else {
      printf("%d %d\n", n, m);
    }
  }
}
