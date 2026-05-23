#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-12;
int n, m;
struct NODE {
  int v, p;
} node[6000];
bool cmp(NODE a, NODE b) {
  if (a.v == b.v) return a.p < b.p;
  return a.v < b.v;
}
int a[6000];
int dp[5100];
int main() {
  scanf("%d%d", &n, &m);
  double tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d%lf", &node[i].v, &tmp);
    node[i].p = i;
  }
  sort(node, node + n, cmp);
  for (int i = 0; i < n; i++) {
    a[node[i].p] = i;
  }
  int maxval = 1;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] < a[i]) {
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
    maxval = max(maxval, dp[i]);
  }
  printf("%d\n", n - maxval);
  return 0;
}
