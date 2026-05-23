#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mxn = 201, w = 3;
long long n, m, k;
long long a[mxn][mxn], first[mxn][mxn], tr[mxn][w];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m;
  string second;
  for (int i = 1; i <= m; i++)
    for (int c = 0; c < w; c++) {
      int x = tr[i - 1][c];
      tr[i - 1][c] = i;
      memcpy(tr[i], tr[x], sizeof(tr[i]));
      for (int j = 0; j <= n; j++)
        for (int l = 0; l <= i; l++) {
          if (!j) {
            a[j][l] = tr[l][1];
            first[j][l] = a[j][l] == i;
          } else if (!~-j) {
            a[j][l] = tr[l][2];
            first[j][l] = a[j][l] == i;
          } else {
            a[j][l] = a[j - 1][a[j - 2][l]];
            first[j][l] = min(inf, first[j - 1][a[j - 2][l]] + first[j - 2][l]);
          }
        }
      long long y = first[n][0] + (tr[a[n][0]][0] == i);
      if (y > k) {
        if (!c) goto hell;
        second += char('0' + c - 1);
        break;
      }
      tr[i - 1][c] = x, k -= y;
    }
hell:
  cout << second << '\n';
  return 0;
}
