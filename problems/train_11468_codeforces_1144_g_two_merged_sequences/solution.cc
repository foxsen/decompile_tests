#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 2000000")
using namespace std;
long long power(long long a, long long n) {
  if (n == 1) return a % 1000000007;
  if (n == 0) return 1;
  if (n & 1)
    return ((a % 1000000007) * (power((a * a) % 1000000007, n / 2)) %
            1000000007) %
           1000000007;
  return power((a * a) % 1000000007, n / 2) % 1000000007;
}
const long long inf = (long long)1e18;
const long long md = (long long)1e9 + 21;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, fo = 1;
  cin >> n;
  vector<long long> v(200005), cnt(200005), ans(200005);
  for (long long i = 1; i < n + 1; ++i) {
    cin >> v[i];
    cnt[v[i]]++;
    if (cnt[v[i]] > 2) fo = 0;
  }
  if (!fo) {
    cout << "NO\n";
    return 0;
  }
  long long inc = -1, dec = 1000000007;
  for (long long i = 1; i < n + 1; ++i) {
    bool f1 = 0, f2 = 0;
    if (inc < v[i]) f1 = 1;
    if (dec > v[i]) f2 = 1;
    if (!f1 && !f2) {
      cout << "NO\n";
      return 0;
    }
    if (f1 && f2) {
      if (i < n && v[i + 1] > v[i])
        inc = v[i];
      else
        ans[i] = 1, dec = v[i];
      continue;
    }
    if (f1)
      inc = v[i];
    else
      dec = v[i], ans[i] = 1;
  }
  cout << "YES\n";
  for (long long i = 1; i < n + 1; ++i) cout << ans[i] << " ";
  return 0;
}
