#include <bits/stdc++.h>
using namespace std;
int arr[110000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    int t = arr[i];
    long long p = 1LL;
    while (t > 0) {
      long long now = t % 10;
      ans += n * (11 * p * now);
      ans %= 998244353;
      p *= 100LL;
      p %= 998244353;
      t /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}
