#include <bits/stdc++.h>
using namespace std;
const double PI = atan(1.0) * 4;
const int64_t INF = 100000000000000003;
const int32_t LOG = 21;
const long long int BIG = pow(2, 20);
const long long int N = 100005;
long long int a[100005];
long long int cnt[100005];
long long int power(long long int x, long long int n) {
  if (n == 1) return x;
  if (n == 0) return 1;
  long long int temp = power(x, n / 2);
  temp = (temp * temp) % 1000000007;
  if (n & 1)
    return (temp * x) % 1000000007;
  else
    return temp;
}
long long int calc(long long int n, long long int x) {
  long long int i = 0;
  long long int pow = 0;
  while (cnt[i] % x == 0 && cnt[i] > 0) {
    cnt[i + 1] += cnt[i] / x;
    cnt[i] = 0;
    i++;
    pow++;
  }
  return min(pow, a[n - 1]);
}
int32_t main() {
  long long int n, x;
  cin >> n >> x;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int max1 = a[n - 1];
  for (long long int i = 0; i < n; i++) {
    if (max1 - a[i] < 100004) cnt[max1 - a[i]]++;
  }
  long long int added_power = calc(n, x);
  long long int sum = accumulate(a, a + n, 0LL) - a[n - 1];
  sum += added_power;
  cout << power(x, sum) << '\n';
  return 0;
}
