#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1), w(n);
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  v.back() = v[0];
  for (int i = 0; i < n; i++) {
    w[i].first = v[i + 1].first - v[i].first;
    w[i].second = v[i + 1].second - v[i].second;
  }
  if (n % 2) {
    cout << "NO";
  } else {
    int k = n / 2;
    for (int i = 0; i < k; i++) {
      if (w[i].first + w[i + k].first != 0 or
          w[i].second + w[i + k].second != 0) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  }
}
