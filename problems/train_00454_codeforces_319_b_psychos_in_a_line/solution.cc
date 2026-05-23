#include <bits/stdc++.h>
using namespace std;
int n, m[100005], x, k[100005], res, last;
stack<int> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (s.empty() || x > s.top()) {
      s.push(x);
    } else {
      if (last > x) {
        m[x] = 1;
        k[x] = last;
      } else {
        int lastVic = last;
        while (k[lastVic] < x || m[k[lastVic]] == m[lastVic]) {
          lastVic = k[lastVic];
        }
        m[x] = m[lastVic] + 1;
        k[x] = k[lastVic];
      }
    }
    res = max(res, m[x]);
    last = x;
  }
  cout << res << endl;
  return 0;
}
