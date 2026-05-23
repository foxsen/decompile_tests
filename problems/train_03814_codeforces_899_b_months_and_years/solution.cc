#include <bits/stdc++.h>
int main() {
  int a;
  while (~scanf("%d", &a)) {
    int b[60] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31,
                 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30,
                 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        c[24], ans;
    for (int i = 0; i < a; i++) {
      scanf("%d", &c[i]);
    }
    for (int i = 0; i < 60 - a; i++) {
      if (b[i] == c[0]) {
        ans = 0;
        int z = i;
        for (int j = 0; j < a; j++) {
          if (c[j] == b[z]) ans++;
          z++;
        }
        if (ans == a) break;
      }
    }
    if (ans == a)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
