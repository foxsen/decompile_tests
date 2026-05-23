#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[100000 + 11];
  int ant[3][100000 + 11];
  int m;
  int l, r;
  scanf("%s", str + 1);
  ant[0][0] = ant[1][0] = ant[2][0] = 0;
  for (int i = 1; str[i]; i++) {
    if (str[i] == 'x') {
      ant[0][i] = ant[0][i - 1] + 1;
      ant[1][i] = ant[1][i - 1];
      ant[2][i] = ant[2][i - 1];
    } else if (str[i] == 'y') {
      ant[0][i] = ant[0][i - 1];
      ant[1][i] = ant[1][i - 1] + 1;
      ant[2][i] = ant[2][i - 1];
    } else {
      ant[0][i] = ant[0][i - 1];
      ant[1][i] = ant[1][i - 1];
      ant[2][i] = ant[2][i - 1] + 1;
    }
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &l, &r);
    int n = r - l + 1;
    if (n < 3) {
      puts("YES");
      continue;
    }
    int a[4];
    a[0] = ant[0][r] - ant[0][l - 1];
    a[1] = ant[1][r] - ant[1][l - 1];
    a[2] = ant[2][r] - ant[2][l - 1];
    sort(a, a + 3);
    if (n % 3) {
      if (a[2] == n / 3 + 1 && a[0] == n / 3)
        puts("YES");
      else
        puts("NO");
    } else {
      if (a[0] == a[2])
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
