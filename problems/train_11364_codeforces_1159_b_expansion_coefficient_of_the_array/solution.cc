#include <bits/stdc++.h>
using namespace std;
long long diff[10000006];
long long same[10000006];
long long fastexpo(long long x, long long n) {
  if (n == 0) return 1;
  long long temp = fastexpo(x, n / 2) % 1000000007;
  if (n & 1) return (temp * temp * x) % 1000000007;
  return (temp * temp) % 1000000007;
}
int main() {
  long long n, i, j;
  cin >> n;
  vector<pair<long long, long long> > vec;
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    vec.push_back(make_pair(x, i + 1));
  }
  sort(vec.begin(), vec.end());
  long long s = 0, e = 1000000007;
  long long ans = 0;
  while (s <= e) {
    long long mid = (s + e) / 2;
    for (i = 0; i < n; i++) {
      if (mid * max(n - vec[i].second, vec[i].second - 1) > vec[i].first) break;
    }
    if (i < n)
      e = mid - 1;
    else {
      ans = mid;
      s = mid + 1;
    }
  }
  cout << ans << endl;
}
