#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a, b;
  int one = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a == 1) one++;
  }
  int pone = n - one;
  while (m--) {
    scanf("%d%d", &a, &b);
    int tmp = b - a + 1;
    if (tmp & 1)
      puts("0");
    else {
      if (tmp / 2 <= one && tmp / 2 <= pone)
        puts("1");
      else
        puts("0");
    }
  }
  return 0;
}
