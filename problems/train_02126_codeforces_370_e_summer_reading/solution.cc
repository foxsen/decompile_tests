#include <bits/stdc++.h>
using namespace std;
pair<int, int> upper[200010], lower[200010];
int a[200010], c[200010];
void work(int n) {
  if (a[1] > 1) {
    puts("-1");
    return;
  }
  upper[1] = lower[1] = make_pair(1, 1);
  for (int i = 2; i <= n; i++) {
    upper[i] = upper[i - 1].second >= 2
                   ? make_pair(upper[i - 1].first + 1, 1)
                   : make_pair(upper[i - 1].first, upper[i - 1].second + 1);
    lower[i] = lower[i - 1].second == 5
                   ? make_pair(lower[i - 1].first + 1, 1)
                   : make_pair(lower[i - 1].first, lower[i - 1].second + 1);
    if (a[i]) {
      if (a[i] > upper[i].first || a[i] < lower[i].first) {
        puts("-1");
        return;
      }
      upper[i] = min(upper[i], make_pair(a[i], 5));
      lower[i] = max(lower[i], make_pair(a[i], 1));
    }
  }
  pair<int, int> ans = upper[n];
  if (ans.second == 1) ans = make_pair(upper[n].first - 1, 5);
  if (ans < lower[n]) {
    puts("-1");
    return;
  }
  printf("%d\n", ans.first);
  a[n] = ans.first;
  c[a[n]] = 1;
  for (int i = n - 1; i; i--) {
    a[i] = min(a[i + 1], upper[i].first);
    if (c[a[i]] == 5) a[i]--;
    c[a[i]]++;
  }
  for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? 10 : ' ');
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  work(n);
  return 0;
}
