#include <bits/stdc++.h>
using namespace std;
int f(const vector<int>& a, int v, int cur_max) {
  return max(cur_max, max(abs(a[0] - v), abs(a.back() - v)));
}
int main() {
  srand(chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count());
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) {
      cin >> e;
    }
    int cur_max = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] == -1 || a[i] == -1) {
        continue;
      }
      cur_max = max(cur_max, abs(a[i] - a[i - 1]));
    }
    vector<int> z;
    for (int i = 0; i < n; ++i) {
      if (a[i] != -1) {
        continue;
      }
      if (i > 0 && a[i - 1] != -1) {
        z.push_back(a[i - 1]);
      }
      if (i + 1 < n && a[i + 1] != -1) {
        z.push_back(a[i + 1]);
      }
    }
    if (z.empty()) {
      cout << "0 0\n";
      continue;
    }
    sort(z.begin(), z.end());
    int q = (z[0] + (long long)z.back()) / 2;
    cout << f(z, q, cur_max) << ' ' << q << '\n';
  }
  return 0;
}
