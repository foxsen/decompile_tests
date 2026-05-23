#include <bits/stdc++.h>
using namespace std;
long long sum[101];
multiset<int> s[101];
int main() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    char c[10];
    int x;
    scanf("%s%d", c, &x);
    int i = 0;
    for (; (1 << (i + 1)) <= x; i++)
      ;
    if (c[0] == '+')
      sum[i] += x, s[i].insert(x);
    else
      sum[i] -= x, s[i].erase(s[i].find(x));
    long long S = 0;
    int ans = 0;
    for (i = 0; i <= 30; i++) {
      ans += s[i].size();
      if (!s[i].empty() && *s[i].begin() > 2 * S) ans--;
      S += sum[i];
    }
    printf("%d\n", ans);
  }
}
