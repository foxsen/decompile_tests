#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long x, long long y) {
  long long ans = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, ans;
  long long t;
  cin >> t;
  while (t--) {
    ans = 1;
    cin >> n;
    long long arr[n];
    for (long long i = (long long)(0); i <= (long long)(n - 1); ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    for (long long i = (long long)(n - 1); i >= (long long)(0); --i) {
      if (arr[i] <= i + 1) {
        ans = i + 2;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
