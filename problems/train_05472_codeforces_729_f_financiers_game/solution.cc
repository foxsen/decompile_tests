#include <bits/stdc++.h>
using namespace std;
int n, ar[4005], tr[4005];
int dp[2200][90][90];
int func(int, int, int), sub(int, int, int, int, int);
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) scanf("%d", &ar[i]);
  for (int i = 1; i < n + 1; i++) tr[i] += tr[i - 1] + ar[i];
  printf("%d", func(0, 0, 1));
}
int func(int idx, int gain, int k) {
  int l = idx + 1, r = n - (idx + gain);
  if (l > r) return 0;
  if (dp[idx][gain][k] != -1) return dp[idx][gain][k];
  int ans1, ans2;
  {
    int init = sub(l, l + (k)-1, l, r, 0);
    int a = -sub(r - (k) + 1, r, l + (k), r, 0) + func(l + (k)-1, gain, k);
    int b = -sub(r - (k + 1) + 1, r, l + (k), r, 2) +
            func(l + (k)-1, gain + 1, k + 1);
    ans1 = init + min(a, b);
  }
  {
    int init = sub(l, l + (k + 1) - 1, l, r, 1);
    int a = -sub(r - (k + 1) + 1, r, l + (k + 1), r, 0) +
            func(l + (k + 1) - 1, gain, k + 1);
    int b = -sub(r - (k + 2) + 1, r, l + (k + 1), r, 2) +
            func(l + (k + 1) - 1, gain + 1, k + 2);
    ans2 = init + min(a, b);
  }
  return dp[idx][gain][k] = max(ans1, ans2);
}
int sub(int a, int b, int l, int r, int all) {
  if (!(l <= a && b <= r)) {
    if (all == 1)
      return sub(a, b - 1, l, r, 0);
    else if (all == 2)
      return sub(a + 1, b, l, r, 0);
    return 0;
  }
  return tr[b] - tr[a - 1];
}
int sum(int a, int b) { return tr[b] - tr[a - 1]; }
