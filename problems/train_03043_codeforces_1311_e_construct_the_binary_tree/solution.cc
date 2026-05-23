#include <bits/stdc++.h>
using namespace std;
const int maxn = 5009;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
int f[10000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(f, 0, sizeof(f));
    int n, d, dmin = 0, dmax;
    scanf("%d%d", &n, &d);
    dmax = (n - 1) * n / 2;
    int k = 1, tem = 1;
    while (tem < n) {
      tem += (1 << k);
      dmin += k * (1 << k);
      k++;
    }
    dmin = dmin - (((1 << (k - 1)) - (n - (tem - (1 << (k - 1))))) * (k - 1));
    if (d > dmax || d < dmin)
      printf("NO\n");
    else {
      printf("YES\n");
      if (d == dmax) {
        for (int i = 1; i <= n - 1; i++) printf("%d ", i);
        printf("\n");
        continue;
      }
      k--;
      int down = (n - 1), up = 1;
      for (int i = 1; i <= n - 1; i++) f[i] = 1;
      int flag = 0;
      for (int i = (n - 1); i >= k; i--) {
        int z = i;
        while (1) {
          if (dmax == d) {
            flag = 1;
            break;
          }
          if (z == up) break;
          if (f[up] == (1 << up)) up++;
          dmax--;
          f[z]--;
          f[z - 1]++;
          z--;
        }
        if (flag) break;
      }
      int op;
      for (int i = 1; i <= n - 1; i++) {
        if (f[i] == 0) {
          op = i;
          break;
        }
      }
      op--;
      int p = 1, np = 1, cnt;
      for (int i = 1; i <= op; i++) {
        int t = p;
        cnt = 0;
        for (int j = 1; j <= f[i]; j++) {
          p++;
          cnt++;
          if (cnt >= 3) {
            np++;
            cnt = 1;
          }
          printf("%d ", np);
        }
        np = t + 1;
      }
      printf("\n");
    }
  }
  return 0;
}
