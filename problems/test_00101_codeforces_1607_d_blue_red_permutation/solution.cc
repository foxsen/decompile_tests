#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
pair<int, int> a[N];
char c[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].first);
    scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) {
      if (c[i] == 'R')
        a[i].second = 1;
      else
        a[i].second = -1;
    }
    sort(a + 1, a + 1 + n);
    int flag = 0;
    int num = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i].second == 1) {
        num++;
        if (a[i].first > n) flag = 1;
        if (num > n - a[i].first + 1) flag = 1;
      }
      if (flag) break;
    }
    num = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].second == -1) {
        num++;
        if (a[i].first < 1) flag = 1;
        if (num > a[i].first) flag = 1;
      }
      if (flag) break;
    }
    if (flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
