#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  for (int t = 0; t < 4; t++) {
    vector<int> ans;
    ans.push_back(t);
    for (int i = 1; i < n; i++) {
      for (int x = 0; x < 4; x++)
        if ((ans.back() & x) == b[i - 1] && (ans.back() | x) == a[i - 1]) {
          ans.push_back(x);
          break;
        }
      if (ans.size() == i) break;
    }
    if (ans.size() == n) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << ans[i] << ' ';
      return 0;
    }
  }
  cout << "NO";
}
