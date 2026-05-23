#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  long long int n, x;
  cin >> n >> x;
  vector<long long int> a(n);
  unordered_map<long long int, long long int> cnt;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]] >= 2) {
      cout << 0 << "\n";
      return 0;
    }
  }
  unordered_map<long long int, long long int> pcnt;
  long long int ans = 1e15;
  for (long long int i = 0; i < n; i++) {
    long long int now = a[i], next = a[i] & x;
    pcnt[next]++;
    if (now != next && cnt.count(next)) ans = 1;
  }
  if (ans > 1e13) {
    for (auto i : pcnt) {
      if (i.second >= 2) ans = 2;
    }
  }
  if (ans > 1e13)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
  return 0;
}
