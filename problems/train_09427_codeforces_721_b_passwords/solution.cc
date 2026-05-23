#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int n, k, p, ans = 0;
  int a[105];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    cin >> str;
    a[i] = str.length();
  }
  cin >> str;
  p = str.length();
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    ans += 1;
    if (i != 0 && i % k == 0) ans += 5;
    if (a[i] == p && (i == 0 || a[i - 1] != p)) printf("%d", ans);
    if (a[i] == p && (i == n || a[i + 1] != p)) printf(" %d", ans);
  }
  return 0;
}
