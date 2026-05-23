#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
string a, b;
pair<char, int> x[maxn];
void solve() {
  cin >> a >> b;
  int n = a.size(), m = b.size();
  for (int i = 0; i < n; i++) {
    x[i] = make_pair(a[i], i);
  }
  sort(x, x + n);
  int d, poc;
  for (int i = 0; i < n; i++) {
    if (x[i].first != a[i]) {
      poc = i;
      d = i;
      while (d < n - 1 && x[d].first == x[d + 1].first) {
        d++;
      }
      d = x[d].second;
      swap(a[poc], a[d]);
      break;
    }
  }
  int sol = -1;
  for (int i = 0; i < min(n, m); i++) {
    if (a[i] < b[i]) {
      sol = 1;
      break;
    } else if (b[i] < a[i]) {
      sol = 0;
      break;
    }
  }
  if (sol == -1) {
    if (n < m) {
      sol = 1;
    } else {
      sol = 0;
    }
  }
  if (sol) {
    cout << a << '\n';
  } else {
    cout << "---" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
