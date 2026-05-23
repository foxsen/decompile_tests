#include <bits/stdc++.h>
using namespace std;
int n, q, a = 1, b = 2, ans[1000001];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      if (x < 0) {
        b += x;
        if (b <= 0) {
          b += n;
        }
        a += x;
        if (a <= 0) {
          a += n;
        }
      } else {
        b += x;
        if (b > n) {
          b -= n;
        }
        a += x;
        if (a > n) {
          a -= n;
        }
      }
    } else {
      if (a & 1) {
        a++;
      } else {
        a--;
      }
      if (b & 1) {
        b++;
      } else {
        b--;
      }
    }
  }
  int cnt = 1;
  for (int i = a; cnt <= n; i = (i + 1) % n + 1, cnt += 2) {
    ans[i] = cnt;
  }
  cnt = 2;
  for (int i = b; cnt <= n; i = (i + 1) % n + 1, cnt += 2) {
    ans[i] = cnt;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
