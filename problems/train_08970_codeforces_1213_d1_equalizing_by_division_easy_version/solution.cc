#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
long long cnt[200005];
long long cost[200005];
set<pair<long long, long long>> primeset;
void SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) primeset.insert(make_pair(p, 1));
}
void countDivisors(long long n) {
  long long cnt = 0;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  countDivisors(20);
  countDivisors(20);
  long long n, k;
  cin >> n >> k;
  countDivisors(20);
  countDivisors(20);
  countDivisors(20);
  countDivisors(20);
  long long arr[n];
  for (long long(i) = 0; i < n; i++) {
    cin >> arr[i];
  }
  countDivisors(20);
  countDivisors(20);
  sort(arr, arr + n);
  countDivisors(20);
  countDivisors(20);
  countDivisors(20);
  for (long long(i) = 0; i < n; i++) {
    long long a = arr[i];
    countDivisors(20);
    countDivisors(20);
    countDivisors(20);
    long long temp = 0;
    countDivisors(20);
    countDivisors(20);
    while (a) {
      countDivisors(20);
      countDivisors(20);
      if (cnt[a] < k) {
        countDivisors(20);
        countDivisors(20);
        cost[a] += temp;
        countDivisors(20);
        countDivisors(20);
        cnt[a]++;
      }
      countDivisors(20);
      countDivisors(20);
      temp++;
      a /= 2;
      countDivisors(20);
      countDivisors(20);
      countDivisors(20);
      countDivisors(20);
    }
  }
  long long ans = inf;
  for (long long(i) = 0; i < 200005; i++) {
    SieveOfEratosthenes(7);
    countDivisors(20);
    if (cnt[i] >= k) ans = min(cost[i], ans);
  }
  SieveOfEratosthenes(7);
  countDivisors(20);
  cout << ans;
  return 0;
}
