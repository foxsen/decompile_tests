#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, t, s, mm;
  vector<pair<int, int>> a;
  cin >> n >> m;
  mm = 1000000000;
  for (int i = 0; i < m; i++) {
    cin >> k >> t;
    mm = min(mm, t - k + 1);
  }
  cout << mm << "\n";
  for (int i = 0; i < n; i++) {
    cout << i % mm << ' ';
  }
  return 0;
}
