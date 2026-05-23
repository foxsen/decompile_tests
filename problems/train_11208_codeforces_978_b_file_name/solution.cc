#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 1e-6;
int n, m;
int a[maxn];
char s[maxn];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int ans = 0;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x')
      tmp++;
    else {
      if (tmp) {
        if (tmp >= 3) ans += (tmp - 2);
        tmp = 0;
      }
    }
  }
  if (tmp >= 3) ans += (tmp - 2);
  printf("%d\n", ans);
}
