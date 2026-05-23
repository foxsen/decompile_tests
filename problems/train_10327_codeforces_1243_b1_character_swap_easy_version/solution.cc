#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> diff;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      diff.push_back(i);
    }
  }
  if (diff.size() > 2) {
    cout << "NO" << endl;
    return;
  }
  if (diff.size() == 1) {
    cout << "NO" << endl;
    return;
  }
  if (diff.size() == 0) {
    set<char> lr;
    for (int i = 0; i < n; i++) lr.insert(a[i]);
    if (lr.size() == a.size()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return;
  }
  int p1 = diff[0], p2 = diff[1];
  if (a[p1] == a[p2] && b[p2] == b[p1]) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
