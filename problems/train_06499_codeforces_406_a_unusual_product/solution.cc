#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, n, m, k;
bool mas[1002];
char res[1000002];
int main() {
  scanf("%d", &n);
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n((n)-1), j(0); j <= _n; j++) {
      scanf("%d", &a);
      if (i == j) mas[i] = a;
    }
  }
  int ans = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    ans ^= mas[i];
  }
  scanf("%d", &m);
  for (int _n((m)-1), i(0); i <= _n; i++) {
    scanf("%d", &a);
    if (a == 1 || a == 2) {
      scanf("%d", &b);
      --b;
      ans ^= mas[b];
      mas[b] ^= 1;
      ans ^= mas[b];
    } else
      res[k++] = (char)(ans + '0');
  }
  printf("%s\n", res);
}
