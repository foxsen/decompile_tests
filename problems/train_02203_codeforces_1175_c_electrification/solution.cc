#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> v;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    int lo = 1;
    int hi = 1000000000;
    while (lo < hi) {
      int me = (lo + hi) / 2;
      bool can = 0;
      for (int i = 0; i + k - 1 < n; i++) {
        if (v[i + k - 1] - v[i] <= me) can = 1;
      }
      if (!can)
        lo = me + 1;
      else
        hi = me;
    }
    int x = -10;
    for (int i = 0; i + k - 1 < n; i++) {
      if (v[i + k - 1] - v[i] <= lo) x = (v[i] + v[i + k - 1]) / 2;
    }
    cout << x << "\n";
  }
  return 0;
}
