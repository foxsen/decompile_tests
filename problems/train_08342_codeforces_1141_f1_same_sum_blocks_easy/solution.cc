#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const long long INF = (long long)1e18 + 7;
const int N = 123456;
const int M = 1010;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, vector<pair<int, int>>> seg;
  for (int r = 1; r <= n; r++) {
    long long sum = 0;
    for (int l = r; l >= 1; l--) {
      sum += a[l];
      seg[sum].push_back({l, r});
    }
  }
  vector<pair<int, int>> best;
  int result = 0;
  for (auto const& p : seg) {
    const vector<pair<int, int>>& pp = p.second;
    int cur = 0;
    int r = -1;
    vector<pair<int, int>> now;
    for (auto x : pp) {
      if (x.first > r) {
        r = x.second;
        cur++;
        now.push_back(x);
      }
    }
    if (cur > result) {
      result = cur;
      best = now;
    }
  }
  cout << result << '\n';
  for (auto x : best) {
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}
