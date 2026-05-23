#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int t, n, q;
int sum[maxn];
int sum2[maxn];
map<int, vector<int> > a;
void init() { a.clear(); }
int sol(int l, int r) {
  int now = sum[r] + sum[l - 1];
  int tp = lower_bound(a[now].begin(), a[now].end(), l) - a[now].begin();
  return a[now][tp];
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &q);
    init();
    int x, y;
    char s[maxn];
    scanf("%s", s);
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '+')
        x = 1;
      else
        x = -1;
      y = x;
      if (i % 2 == 0) {
        x *= -1;
      } else
        y *= -1;
      sum[i] = 0;
      sum[i] += sum[i - 1] + x;
      a[sum[i] + sum[i - 1]].push_back(i);
    }
    while (q--) {
      cin >> x >> y;
      if ((y - x + 1) % 2 == 1) {
        printf("1\n%d\n", sol(x, y));
        continue;
      }
      if (sum[y] - sum[x - 1] == 0) {
        printf("0\n");
      } else {
        printf("2\n%d %d\n", x, sol(x + 1, y));
      }
    }
  }
  return 0;
}
