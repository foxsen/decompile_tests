// time-limit: 4000
#include<bits/stdc++.h>
#define int long long

using namespace std;

void testCase();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1, t = 0;
  cin >> T;
  while (t++ < T) {
    testCase();
  }
  return 0;
}

void testCase() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (a > b) {
    a = n - a + 1;
    b = n - b + 1;
  }
  vector<int> crackers(m);
  for (int i = 0; i < m; i++) {
    cin >> crackers[i];
  }
  sort(crackers.begin(), crackers.end());
  m = min(m, b - a - 1);
  while ((int)crackers.size() > m) {
    crackers.pop_back();
  }
  int ans = 0, sec = 0;
  while (!crackers.empty()) {
    int x = crackers.back();
    crackers.pop_back();
    if (x + sec < b - 1) ans += 1, sec += 1;
  }
  cout << ans << '\n';
}

