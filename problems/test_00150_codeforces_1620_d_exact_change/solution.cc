#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int answer = 1e9;
  for (int x = 0; x <= 2; x++) {
    for (int y = 0; y <= 2; y++) {
      int result = 0;
      for (int i = 0; i < n; i++) {
        int tmp = 1e9;
        for (int sx = 0; sx <= x; sx++) {
          for (int sy = 0; sy <= y; sy++) {
            int v = a[i] - sx - 2 * sy;
            if (v >= 0 && v % 3 == 0) {
              tmp = min(tmp, v / 3);
            }
          }
        }
        result = max(result, tmp);
      }
      answer = min(answer, result + x + y);
    }
  }
  cout << answer << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
