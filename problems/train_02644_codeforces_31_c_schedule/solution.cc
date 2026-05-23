#include <bits/stdc++.h>
using namespace std;
long long fast_power(long long val, long long deg, long long mod = 1000000007) {
  if (!deg) return 1 % mod;
  if (deg & 1) return fast_power(val, deg - 1, mod) * val % mod;
  long long res = fast_power(val, deg >> 1, mod);
  return (res * res) % mod;
}
long long MMI(long long a, long long mm = 1000000007) {
  return fast_power(a % mm, mm - 2, mm) % mm;
}
long long n, m[5011];
vector<pair<long long, pair<long long, long long> > > v;
vector<long long> ans;
bool check() {
  long long i = 0;
  while (m[i] == 1) i++;
  long long end = v[i].second.first;
  i++;
  for (; i < n; i++) {
    if (!m[i]) {
      if (end > v[i].first) return false;
      end = v[i].second.first;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, make_pair(b, i + 1)));
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    m[i] = 1;
    if (check()) ans.push_back(v[i].second.second);
    m[i] = 0;
  }
  sort(ans.begin(), ans.end());
  cout << (long long)ans.size() << "\n";
  for (auto &i : ans) cout << i << " ";
  return 0;
}
