#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
char can[2][300];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string sa, sb;
  cin >> sa >> sb;
  string a;
  cin >> a;
  int dir = 1;
  if (sb[0] == 'h') dir = -1;
  m--;
  k--;
  can[0][m] = 1;
  if (m == k) {
    puts("Controller 1");
    return 0;
  }
  int fr = 0;
  int ba = 1;
  for (int i = 0; i < a.size(); i++) {
    int oldk = k;
    k += dir;
    if (k == n) {
      k = n - 2;
      dir = -dir;
    } else if (k == -1) {
      k = 1;
      dir = -dir;
    }
    swap(fr, ba);
    memset(can[fr], 0, sizeof(can[fr]));
    bool any = false;
    if (a[i] == '0') {
      for (int j = 0; j < n; j++)
        if (can[ba][j]) {
          for (int q = -1; q <= 1; q++) {
            int z = j + q;
            if (z < 0 || z >= n) continue;
            if (z == k || z == oldk) continue;
            can[fr][z] = 1;
            any = true;
          }
        }
    } else {
      for (int j = 0; j < n; j++)
        if (j != k) {
          can[fr][j] = 1;
          any = true;
        }
    }
    if (!any) {
      printf("Controller %d\n", i + 1);
      return 0;
    }
  }
  puts("Stowaway");
  return 0;
}
