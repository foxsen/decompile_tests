#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
int n, k;
int a[300005];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<long long> rk;
  rk.clear();
  long long sum = 0LL;
  for (int i = n; i > 1; --i) {
    sum += a[i];
    rk.push_back(sum);
  }
  sum += a[1];
  long long ans = sum;
  sort(rk.begin(), rk.end());
  reverse(rk.begin(), rk.end());
  for (int i = 0; i < k - 1; ++i) {
    ans += rk[i];
  }
  cout << ans << endl;
  return 0;
}
