#include <bits/stdc++.h>
using namespace std;
int n, a[1005], dp[1005][2];
int rec(int i, int f) {
  int ret = 0;
  if (i == n) {
    if (f == 1) {
      return -1;
    }
    return 0;
  }
  if (dp[i][f] != -1) {
    return dp[i][f];
  }
  if (f == 0) {
    if (a[i] == 1) {
      ret = min(2 + rec(i + 1, 1), 2 + rec(i + 1, 0));
    } else {
      ret = rec(i + 1, 0);
    }
  } else {
    if (a[i] == 1) {
      ret = min(1 + rec(i + 1, 0), 1 + rec(i + 1, 1));
    } else {
      ret = min(1 + rec(i + 1, 0), 1 + rec(i + 1, 1));
    }
  }
  return (dp[i][f] = ret);
}
int main() {
  int i, j, k = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
    cin >> a[i];
    if (a[i] == 1) {
      k = max(k, i + 1);
    }
  }
  n = k;
  cout << rec(0, 0);
  return 0;
}
