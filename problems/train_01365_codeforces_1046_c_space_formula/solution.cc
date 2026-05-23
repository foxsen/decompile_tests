#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, d;
  cin >> n >> d;
  d--;
  multiset<long long> s;
  vector<long long> v(n);
  vector<long long> vals(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long i = 0; i < n; i++) cin >> vals[i];
  long long chk = vals[0] + v[d];
  long long idx = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (i == d || (v[i] > chk)) {
      ans++;
      idx++;
      continue;
    } else {
      s.insert(v[i]);
    }
  }
  for (; idx < n; idx++) {
    if (s.size() + idx != n) {
      cout << "Da la beng ba";
      return 0;
    }
    auto it = s.lower_bound(chk - vals[idx] + 1);
    if (it == s.begin()) {
      ans++;
      s.erase(--s.end());
    } else {
      it--;
      s.erase(it);
    }
  }
  cout << ans;
  return 0;
}
