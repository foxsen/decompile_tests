#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res % 1000000007 * a % 1000000007) % 1000000007;
    b /= 2;
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
  }
  return res;
}
long long sieve[1000005];
void pre() {
  sieve[0] = 1;
  sieve[1] = 1;
  for (int i = 2; i < 1000005; i++) {
    if (sieve[i] == 0)
      for (int j = 2 * i; j < 1000005; j += i) {
        sieve[j] = 1;
      }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, p;
  cin >> n >> p;
  long long a[n];
  map<long long, long long> mp;
  vector<pair<long long, long long>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (auto it : mp) v.push_back({it.first, it.second});
  sort(v.begin(), v.end());
  long long k = (8 * p) / n;
  long long ans2 = 1;
  for (int i = 0; i < k; i++) {
    ans2 = ans2 * 2;
    if (ans2 >= mp.size()) {
      break;
    }
  }
  if (ans2 >= mp.size())
    cout << "0";
  else {
    long long ans1 = 0;
    long long mn = 1e18;
    for (int i = 0; i < ans2 && i < v.size(); i++) ans1 += v[i].second;
    mn = min(mn, n - ans1);
    for (int i = ans2; i < v.size(); i++) {
      ans1 -= v[i - ans2].second;
      ans1 += v[i].second;
      mn = min(mn, n - ans1);
    }
    cout << mn << endl;
  }
}
