#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const int Z = 1 + 10 + 26 + 26;
int P1 = 45221983, P2 = 99997867, P3 = 100001651;
char s[N], ans[N];
int lans;
int xf[N], xs[N], xt[N];
int pwr(int x, int a, int P) {
  int s = 1;
  for (; a; a >>= 1, x = 1ll * x * x % P)
    if (a & 1) s = 1ll * s * x % P;
  return s;
}
int gt(int x[], int l, int r, int P) {
  return (x[r] + P - 1ll * x[l - 1] * pwr(Z, r - l + 1, P) % P) % P;
}
int b[128];
int main() {
  int n, i, j, sm = 0;
  scanf("%d", &n);
  for (i = 'a'; i <= 'z'; i++) b[i] = ++sm;
  for (i = '0'; i <= '9'; i++) b[i] = ++sm;
  for (i = 'A'; i <= 'Z'; i++) b[i] = ++sm;
  for (i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int l = strlen(s + 1), cr = 0;
    int yf = 0, ys = 0, yt = 0;
    for (j = 1; j <= l && j <= lans; j++) {
      yf = (1ll * yf * Z + b[s[j]]) % P1, ys = (1ll * ys * Z + b[s[j]]) % P2,
      yt = (1ll * yt * Z + b[s[j]]) % P3;
      if (yf == gt(xf, lans - j + 1, lans, P1) &&
          ys == gt(xs, lans - j + 1, lans, P2) &&
          yt == gt(xt, lans - j + 1, lans, P3))
        cr = j;
    }
    for (j = cr + 1; j <= l; j++)
      ans[++lans] = s[j], xf[lans] = (1ll * xf[lans - 1] * Z + b[s[j]]) % P1,
      xs[lans] = (1ll * xs[lans - 1] * Z + b[s[j]]) % P2,
      xt[lans] = (1ll * xt[lans - 1] * Z + b[s[j]]) % P3;
  }
  for (i = 1; i <= lans; i++) printf("%c", ans[i]);
  return 0;
}
