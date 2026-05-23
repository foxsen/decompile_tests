#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f;
int main() {
  long long n, m, a[N];
  cin >> n >> m;
  long long sum = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < n) {
    printf("-1\n");
    return 0;
  }
  int tmp = 1, ans[N], cnt = 0, flag = 1;
  ans[++cnt] = tmp;
  sum -= n;
  for (int i = 1; i <= m; i++) {
    if (tmp + a[i] - 1 > n) {
      flag = 0;
      break;
    }
    if (sum == 0) {
      tmp += a[i];
    } else {
      if (sum >= a[i]) {
        tmp += 1;
        sum -= a[i] - 1;
      } else {
        tmp += a[i] - sum;
        sum = 0;
      }
    }
    ans[++cnt] = tmp;
  }
  if (flag) {
    for (int i = 1; i < cnt; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
