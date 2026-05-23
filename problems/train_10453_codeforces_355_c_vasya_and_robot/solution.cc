#include <bits/stdc++.h>
using namespace std;
vector<long long int> fact(1000007);
inline long long int mdpower(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res % 1000000007 * a % 1000000007) % 1000000007;
    b /= 2;
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
  }
  return res;
}
inline long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    b /= 2;
    a = a * a;
  }
  return res;
}
inline void factorial() {
  fact[0] = 1;
  for (long long int i = 1; i < 1000007; i++)
    fact[i] = (fact[i - 1] % 1000000007 * i % 1000000007) % 1000000007;
}
inline long long int inverse(long long int a) {
  return mdpower(a, 1000000007 - 2);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  long long int arr[n];
  long long int tot = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    tot += arr[i];
  }
  long long int ans = 1000000007;
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    long long int x = sum * l + (tot - sum) * r;
    if (i > n - i) {
      x += (2 * i - n - 1) * ql;
    } else if (i < n - i) {
      x += (n - 2 * i - 1) * qr;
    }
    sum += arr[i];
    ans = min(ans, x);
  }
  long long int x = sum * l + (tot - sum) * r;
  x += (n - 1) * ql;
  ans = min(ans, x);
  if (n == 1) {
    ans = min(ans, arr[0] * l);
  }
  cout << ans << "\n";
}
