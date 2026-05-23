#include <bits/stdc++.h>
using namespace std;
char s[35];
long long mx = -1, x, y, z, Lim = 1000000;
long long toS(int f, int l) {
  long long ln = 0;
  for (int i = f; i <= l; i++) {
    ln *= 10;
    ln += s[i] - '0';
  }
  return ln;
}
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < i + 8; j++) {
      for (int k = j + 1; k < j + 8; k++) {
        if (k == len - 1 && (s[0] != '0' || i == 0) &&
            (s[i + 1] != '0' || j == i + 1) &&
            (s[j + 1] != '0' || k == j + 1)) {
          x = toS(0, i);
          y = toS(i + 1, j);
          z = toS(j + 1, k);
          if (x <= Lim && y <= Lim && z <= Lim) mx = max(mx, x + y + z);
        }
      }
    }
  }
  printf("%lld\n", mx);
  return 0;
}
