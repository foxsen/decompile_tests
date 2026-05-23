#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
long long fac[MAXN], ft[8];
long long C[1000][1000];
int num[8];
void Init() {
  for (int i = 1; i < MAXN; i++)
    for (int j = i; j < MAXN; j += i) fac[j]++;
  memset(C, 0, sizeof(C));
  for (int i = 0; i < 1000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
bool check(int a, int b, int c) {
  if ((a & 1) && ((b >> 1) & 1) && ((c >> 2) & 1)) return true;
  if ((a & 1) && ((c >> 1) & 1) && ((b >> 2) & 1)) return true;
  if ((b & 1) && ((a >> 1) & 1) && ((c >> 2) & 1)) return true;
  if ((b & 1) && ((c >> 1) & 1) && ((a >> 2) & 1)) return true;
  if ((c & 1) && ((a >> 1) & 1) && ((b >> 2) & 1)) return true;
  if ((c & 1) && ((b >> 1) & 1) && ((a >> 2) & 1)) return true;
  return false;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  Init();
  int T;
  scanf("%d", &T);
  int a, b, c, gcdab, gcdac, gcdbc, gcdabc;
  while (T--) {
    scanf("%d%d%d", &a, &b, &c);
    gcdab = gcd(a, b);
    gcdac = gcd(a, c);
    gcdbc = gcd(b, c);
    gcdabc = gcd(gcdab, c);
    ft[1] = fac[a] - fac[gcdab] - fac[gcdac] + fac[gcdabc];
    ft[2] = fac[b] - fac[gcdab] - fac[gcdbc] + fac[gcdabc];
    ft[4] = fac[c] - fac[gcdac] - fac[gcdbc] + fac[gcdabc];
    ft[3] = fac[gcdab] - fac[gcdabc];
    ft[5] = fac[gcdac] - fac[gcdabc];
    ft[6] = fac[gcdbc] - fac[gcdabc];
    ft[7] = fac[gcdabc];
    long long ans = 0;
    for (int i = 1; i < 8; i++)
      for (int j = i; j < 8; j++)
        for (int k = j; k < 8; k++) {
          if (check(i, j, k)) {
            memset(num, 0, sizeof(num));
            num[i]++;
            num[j]++;
            num[k]++;
            long long temp = 1;
            bool flag = 0;
            for (int l = 1; l < 8; l++) {
              if (num[l]) {
                if (ft[l] + num[l] - 1 > 0)
                  temp *= C[ft[l] + num[l] - 1][num[l]];
                else
                  flag = 1;
              }
            }
            if (!flag) ans += temp;
          }
        }
    printf("%lld\n", ans);
  }
  return 0;
}
