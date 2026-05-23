#include <bits/stdc++.h>
using namespace std;
const int GO_MAX = 26;
const int ESP = 1e-9;
const int MAX = 100001;
const int INF = 1e9;
int n, m, k, p, q, t;
bool chk[100];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    bool trig = true;
    memset(chk, 0, sizeof chk);
    for (int i = 0; i < n; ++i) {
      long long num = 0;
      int cnt = 0;
      scanf("%lld", &num);
      while (num && trig) {
        long long bit = num % k;
        num /= k;
        if (bit > 1) {
          trig = false;
        } else if (bit == 1) {
          if (chk[cnt]) trig = false;
          chk[cnt] = true;
        }
        ++cnt;
      }
    }
    if (trig)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
