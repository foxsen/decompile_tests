#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int an[310000];
char sn[310000];
int main() {
  int z;
  int n, m;
  int i, j, k;
  cin >> z;
  while (z--) {
    scanf("%d%d", &n, &k);
    scanf("%s", sn);
    bool flag = 1;
    int first, last;
    for (i = 0; i < n; i++) {
      if (sn[i] == 'W' && flag) {
        flag = 0;
        first = i;
      }
      if (sn[i] == 'W') last = i;
    }
    int ans;
    if (flag) {
      ans = max(k * 2 - 1, 0);
    } else {
      int l;
      bool bl = 0;
      int num = 0;
      ans = 1;
      for (i = first + 1; i <= last; i++) {
        if (bl == 0 && sn[i] == 'L') {
          l = 1;
          bl = 1;
        } else if (bl == 0 && sn[i] == 'W') {
          ans += 2;
        } else if (bl == 1 && sn[i] == 'L') {
          l++;
        } else {
          bl = 0;
          an[num++] = l;
          ans += 1;
        }
      }
      sort(an, an + num);
      for (i = 0; i < num; i++) {
        if (k >= an[i]) {
          ans += an[i] * 2 + 1;
          k -= an[i];
        } else {
          ans += k * 2;
          k = 0;
          break;
        }
      }
      if (k > 0) {
        ans += min(k, n - (last - first + 1)) * 2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
