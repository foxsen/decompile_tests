#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a = {0};
    int x = 0;
    for (int i = 0; i < n; i++) {
      int c = 1;
      if (s[i] == '-') {
        c = -1;
      }
      if (i % 2 == 0) {
        x += c;
      } else {
        x -= c;
      }
      a.push_back(x);
    }
    for (int i = 0, l, r; i < q; i++) {
      cin >> l >> r;
      if ((r - l + 1) % 2) {
        cout << "1\n";
      } else {
        cout << ((a[r] == a[l - 1]) ? (0) : (2)) << "\n";
      }
    }
  }
}
