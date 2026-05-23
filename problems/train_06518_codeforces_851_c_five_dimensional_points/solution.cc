#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 1, -1, 0, 0, -1, -1, 1, 1};
const int dy[9] = {0, 0, 0, -1, 1, -1, 1, -1, 1};
const double pi = acos(-1.0);
const int N = 1e3;
struct abc {
  int d[6];
};
int n;
long long b[N + 10][6];
abc temp1, temp2;
vector<long long> v;
long long cal(abc temp1, abc temp2) {
  long long ju = 0;
  for (int i = 1; i <= 5; i++) ju += temp1.d[i] * temp2.d[i];
  return ju;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) scanf("%lld", &b[i][j]);
  if (n > 250) {
    puts("0");
  } else {
    for (int i = 1; i <= n; i++) {
      bool ok = true;
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (!ok) break;
        for (int l = 1; l <= 5; l++) temp1.d[l] = b[j][l] - b[i][l];
        for (int k = 1; k <= n; k++) {
          if (j == k || i == k) continue;
          for (int l = 1; l <= 5; l++) {
            temp2.d[l] = b[k][l] - b[i][l];
          }
          if (cal(temp1, temp2) > 0) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        v.emplace_back(i);
      }
    }
    printf("%d", ((int)v.size()));
    puts("");
    for (int i = 0; i <= ((int)v.size()) - 1; i++) {
      printf("%d", v[i]), puts("");
    }
  }
  return 0;
}
