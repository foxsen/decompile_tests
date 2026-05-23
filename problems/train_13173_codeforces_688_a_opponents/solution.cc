#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, d, ans, hahaha[maxn];
char s[maxn];
bool pd[maxn];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= d; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++)
      if (s[j] == '0') pd[i] = 1;
  }
  for (int i = 1; i <= d; i++) {
    if (pd[i] && pd[i - 1])
      hahaha[i] = hahaha[i - 1] + 1;
    else if (pd[i] && !pd[i - 1])
      hahaha[i] = 1;
    else if (!pd[i])
      hahaha[i] = 0;
  }
  for (int i = 1; i <= d; i++) ans = max(hahaha[i], ans);
  cout << ans << endl;
  return 0;
}
