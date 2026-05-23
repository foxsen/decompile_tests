#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  pair<int, int> point[n];
  for (int i = 0; i < n; i++) {
    cin >> point[i].first >> point[i].second;
  }
  sort(point, point + n,
       [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
  long long ans = 0;
  long long cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (point[i].first == point[i + 1].first) {
      cnt++;
    } else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans += cnt * (cnt - 1) / 2;
  sort(point, point + n,
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (point[i].second == point[i + 1].second) {
      cnt++;
    } else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans += cnt * (cnt - 1) / 2;
  sort(point, point + n);
  cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (point[i] == point[i + 1]) {
      cnt++;
    } else {
      ans -= cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans -= cnt * (cnt - 1) / 2;
  cout << ans << '\n';
  return 0;
}
