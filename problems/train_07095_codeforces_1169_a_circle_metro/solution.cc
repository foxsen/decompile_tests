#include <bits/stdc++.h>
using namespace std;
int n, a, x, b, y, t1[110], t2[110];
int main() {
  scanf("%d%d%d%d%d", &n, &a, &x, &b, &y);
  int k1 = 0, k2 = 0;
  for (int i = 1; i < n; i++) {
    if (k1 == 0) {
      t1[i] = (a + i - 1 + n) % n + 1;
    }
    if (k1 != 0) {
      t1[i] = 0;
    }
    if (t1[i] == x) {
      k1 = 1;
    }
    if (k2 == 0) {
      t2[i] = (b - i - 1 + n) % n + 1;
    }
    if (k2 != 0) {
      t2[i] = -1;
    }
    if (t2[i] == y) {
      k2 = 1;
    }
    if (t1[i] == t2[i]) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
