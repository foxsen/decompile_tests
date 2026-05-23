#include <bits/stdc++.h>
using namespace std;
int num[10000001], det[10000001];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> num[i];
  for (int i = 1; i < n; ++i) det[i] = num[i + 1] - num[i];
  sort(det + 1, det + n);
  int ans = 0;
  for (int i = 1; i <= n - k; ++i) ans += det[i];
  cout << ans << endl;
  return 0;
}
