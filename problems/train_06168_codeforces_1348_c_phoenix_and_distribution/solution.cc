#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ++ti) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int z[26]{};
    for (char c : s) {
      z[c - 'a']++;
    }
    vector<pair<char, int>> r;
    for (int i = 0; i < 26; ++i) {
      if (z[i]) r.emplace_back('a' + i, z[i]);
    }
    if (r[0].second < k) {
      int s = 0;
      for (auto [c, a] : r) {
        s += a;
        if (s >= k) {
          cout << c << '\n';
          break;
        }
      }
      continue;
    }
    if (r.size() == 1) {
      for (int rep = 0; rep < n / k + !!(n % k); ++rep) {
        cout << r[0].first;
      }
      cout << '\n';
      continue;
    }
    if (r[0].second == k && r.size() == 2) {
      n -= k;
      cout << r[0].first;
      for (int rep = 0; rep < n / k + !!(n % k); ++rep) {
        cout << r[1].first;
      }
      cout << '\n';
      continue;
    }
    r[0].second -= k;
    cout << r[0].first;
    for (auto [c, a] : r) {
      for (int rep = 0; rep < a; ++rep) cout << c;
    }
    cout << '\n';
  }
}
