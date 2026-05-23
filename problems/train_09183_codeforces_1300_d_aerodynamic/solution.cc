#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, k, t, T;
double x, y;
pair<int, int> p[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  if (n % 2) {
    printf("NO\n");
    return;
  }
  x = (double)(p[1].first + p[n / 2 + 1].first) / 2,
  y = (double)(p[1].second + p[n / 2 + 1].second) / 2;
  for (int i = 2; i <= n / 2; i++) {
    if ((double)(p[i].first + p[n / 2 + i].first) / 2 != x ||
        (double)(p[i].second + p[n / 2 + i].second) / 2 != y) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
int main() {
  solve();
  return 0;
}
