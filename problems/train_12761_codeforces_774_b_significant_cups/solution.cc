#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int MAXN = 1e5 + 10;
long long n, m, ad[MAXN], ac[MAXN], bd[MAXN], bc[MAXN], indsa[MAXN],
    indsb[MAXN], pr[MAXN], d, prc[MAXN];
bool keya(int x, int y) {
  if (ac[x] == ac[y]) return ad[x] < ad[y];
  return ac[x] > ac[y];
}
bool keyb(int x, int y) {
  if (bc[x] == bc[y]) return bd[x] < bd[y];
  return bc[x] > bc[y];
}
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < n; i++) {
    cin >> ac[i] >> ad[i];
    indsa[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> bc[i] >> bd[i];
    indsb[i] = i;
  }
  sort(indsa, indsa + n, keya);
  sort(indsb, indsb + m, keyb);
  for (int i = 0; i < m; i++) {
    pr[i] = ((i > 0) ? pr[i - 1] : 0) + bd[indsb[i]];
    prc[i] = ((i > 0) ? prc[i - 1] : 0) + bc[indsb[i]];
  }
  long long kol = 0;
  long long ans = 0;
  long long koks = 0;
  for (int i = 0; i < n; i++) {
    kol += ad[indsa[i]];
    koks += ac[indsa[i]];
    int l = -1;
    int r = m;
    while (r - l > 1) {
      int mid = r + l >> 1;
      if (pr[mid] + kol <= d) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (l != -1) {
      ans = max(ans, koks + prc[l]);
    }
  }
  cout << ans;
  return 0;
}
