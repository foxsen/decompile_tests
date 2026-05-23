#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
      cout << 0 << '\n';
      continue;
    }
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > x) {
        swap(a[i], x);
        cnt += 1;
      }
      if (is_sorted(a.begin(), a.end())) {
        cout << cnt << '\n';
        ok = true;
        break;
      }
    }
    if (ok) {
      continue;
    }
    cout << -1 << '\n';
  }
  return 0;
}
