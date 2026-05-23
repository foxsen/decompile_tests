#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 1000000004, q = 0, c = 0, p = 0;
  cin >> n;
  bool o = true;
  vector<int> v(n);
  vector<int> v2(n + 1);
  vector<int> v3(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (q < v[i]) {
      q = v[i];
    }
    v3[i] = q;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (v[i] < s) {
      s = v[i];
    }
    v2[i] = s;
  }
  v2[n] = 1000000004;
  for (int i = 0; i < n; ++i) {
    o = true;
    if (v[i] <= v2[i] and p <= v2[i + 1]) {
      o = false;
    } else {
      if (v[i] > p) {
        p = v[i];
      }
    }
    if (!o) {
      ++c;
      p = 0;
    }
  }
  cout << c << endl;
}
