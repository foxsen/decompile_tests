#include <bits/stdc++.h>
using namespace std;
const int nmax = 2009;
int a[2009][2009];
int ui[nmax], uj[nmax];
int n;
void inc(int &a) {
  ++a;
  a = a & 1;
}
int main() {
  int ans = 0;
  scanf("%d\n", &n);
  char s[nmax];
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 1; j <= n; j++) a[i][j] = s[j - 1] - '0';
  }
  for (int k = n; k >= 1; k--) {
    int p = 0;
    for (int i = 1; i < k; i++) {
      if ((p & 1) == 1) inc(a[i][k]);
      if ((ui[i] & 1) == 1) inc(a[i][k]);
      if (a[i][k] != 0) {
        inc(p);
        inc(ui[i]);
        inc(a[i][k]);
        ans++;
      }
    }
    if ((p & 1) == 1) inc(a[k][k]);
    if ((ui[k] & 1) == 1) inc(a[k][k]);
    p = 0;
    for (int j = 1; j < k; j++) {
      if ((p & 1) == 1) inc(a[k][j]);
      if ((uj[j] & 1) == 1) inc(a[k][j]);
      if (a[k][j] != 0) {
        inc(p);
        inc(uj[j]);
        inc(a[k][j]);
        ans++;
      }
    }
    if ((p & 1) == 1) inc(a[k][k]);
    if ((uj[k] & 1) == 1) inc(a[k][k]);
    if (a[k][k] != 0) {
      ans++;
      inc(a[k][k]);
    }
  }
  cout << ans << endl;
  return 0;
}
