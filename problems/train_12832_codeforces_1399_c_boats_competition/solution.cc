#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e6;
bool col2(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second > p2.second;
}
struct comp {
  bool operator()(long long const& x, long long const& y) { return x > y; }
};
struct compare {
  bool operator()(const pair<int, int>& value, const int& key) {
    return (value.first < key);
  }
  bool operator()(const int& key, const pair<int, int>& value) {
    return (key < value.first);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long ans = 0;
    for (long long i = 1; i < 2 * n + 1; i++) {
      map<long long, long long> mp;
      vector<long long> temp = v;
      long long loc = 0;
      for (long long j = 0; j < n; j++) mp[temp[j]]++;
      for (long long j = 0; j < n; j++) {
        long long x = temp[j];
        long long y = i - temp[j];
        if (mp.count(x) && mp.count(y)) {
          if (x == y) {
            if (mp[x] == 2)
              mp.erase(x), loc++;
            else if (mp[x] > 2)
              mp[x] -= 2, loc++;
            else {
              mp.erase(x);
            }
          } else {
            if (mp[x] == 1)
              mp.erase(x);
            else
              mp[x]--;
            if (mp[y] == 1)
              mp.erase(y);
            else
              mp[y]--;
            loc++;
          }
        }
      }
      ans = max(ans, loc);
    }
    cout << ans << "\n";
  }
}
