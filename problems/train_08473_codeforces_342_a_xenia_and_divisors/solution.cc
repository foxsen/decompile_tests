#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int hav[N];
int main() {
  int n, i, j, a;
  while (scanf("%d", &n) != EOF) {
    memset(hav, 0, sizeof(hav));
    for (i = 0; i < n; i++) {
      scanf("%d", &a);
      hav[a]++;
    }
    if (hav[5] || hav[7])
      puts("-1");
    else {
      if (hav[1] != (hav[2] + hav[3]) || hav[1] != hav[4] + hav[6])
        puts("-1");
      else {
        if (hav[6] < hav[3])
          puts("-1");
        else {
          for (i = 0; i < min(hav[2], hav[4]); i++) puts("1 2 4");
          if (hav[2] >= hav[4]) {
            for (i = 0; i < hav[2] - hav[4]; i++) puts("1 2 6");
          }
          for (i = 0; i < hav[3]; i++) puts("1 3 6");
        }
      }
    }
  }
}
