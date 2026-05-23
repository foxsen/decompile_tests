#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, MOD;
pair<int, int> s[MAXN];
int main() {
  scanf("%d", &n);
  int m = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d", &a);
    s[++m] = make_pair(a, i);
  }
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d", &a);
    s[++m] = make_pair(a, i);
  }
  sort(s + 1, s + m + 1);
  scanf("%d", &MOD);
  long long res = 1;
  for (int i = 1, j = 1; i <= m; i = j) {
    while (j <= m && s[i].first == s[j].first) j++;
    int l = j - i;
    int t = 0;
    for (int k = i + 1; k < j; k++)
      if (s[k] == s[k - 1]) t++;
    for (int k = 1; k <= l; k++) {
      int tk = k;
      while (t > 0 && tk % 2 == 0) tk /= 2, t--;
      res = (res * tk) % MOD;
    }
  }
  printf("%I64d\n", res);
  return 0;
}
