#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;
const double PI = acos(-1);
const int MAXN = 200005;
int n, k, counts[26], cur = 1, best = 0;
char str[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  scanf(" %s", str);
  for (int i = 1; i < n; i++) {
    if (cur == k) {
      counts[str[i - 1] - 'a']++;
      best = max(best, counts[str[i - 1] - 'a']);
      cur = 1;
      continue;
    }
    if (str[i] == str[i - 1]) {
      cur++;
    } else {
      cur = 1;
    }
  }
  if (cur == k) {
    counts[str[n - 1] - 'a']++;
    best = max(best, counts[str[n - 1] - 'a']);
  }
  printf("%d\n", best);
  return 0;
}
