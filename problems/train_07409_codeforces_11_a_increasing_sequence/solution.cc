#include <bits/stdc++.h>
int main() {
  int n, d;
  while (~scanf("%d%d", &n, &d)) {
    int time = 0, fir, sec, temp;
    scanf("%d", &fir);
    for (int i = 2; i <= n; i++) {
      scanf("%d", &sec);
      if (fir > sec) {
        temp = (fir - sec) / d + 1;
        time += temp;
        sec += temp * d;
      } else if (fir == sec)
        time++, sec += d;
      fir = sec;
    }
    printf("%d\n", time);
  }
  return 0;
}
