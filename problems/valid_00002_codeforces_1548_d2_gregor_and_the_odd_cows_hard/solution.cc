#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
const int maxn = 6050;
int n, x[maxn], y[maxn];
int cn[maxn][4][4][4];
long long sum2, sum6;
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline int calc(int i1, int j1, int i2, int j2, int i3, int j3) {
  return i1 * (j2 - j3) + i2 * (j3 - j1) + i3 * (j1 - j2);
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      cn[i][x[j] % 4][y[j] % 4][gcd(abs(x[j] - x[i]), abs(y[j] - y[i])) % 4]++;
    }
  }
  for (int p = 1; p <= n; p++) {
    for (int i1 = 0; i1 < 4; i1++)
      for (int j1 = 0; j1 < 4; j1++)
        for (int z1 = 0; z1 < 4; z1++) {
          if (cn[p][i1][j1][z1] == 0) continue;
          int rec = cn[p][i1][j1][z1];
          cn[p][i1][j1][z1]--;
          for (int i2 = i1 & 1; i2 < 4; i2 += 2)
            for (int j2 = j1 & 1; j2 < 4; j2 += 2)
              for (int z2 = z1 & 1; z2 < 4; z2 += 2) {
                int S = calc(x[p] % 4, y[p] % 4, i1, j1, i2, j2) / 2,
                    z3 = gcd(abs(i1 - i2), abs(j1 - j2));
                if ((S - (z1 + z2 + z3) / 2 + 1) & 1) {
                  if (z1 % 2 == 0)
                    sum6 += rec * cn[p][i2][j2][z2];
                  else
                    sum2 += rec * cn[p][i2][j2][z2];
                }
              }
          cn[p][i1][j1][z1]++;
        }
  }
  long long ans = sum6 / 6 + sum2 / 2;
  cout << ans << endl;
  return 0;
}
