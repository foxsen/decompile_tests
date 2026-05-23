#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> h;
void solve() {
  cin >> n;
  h.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    h[i].erase(h[i].begin());
  }
  for (int i = n - 2; i >= 0; --i) {
    if (h[i] > h[i + 1]) {
      for (int j = 0; j < h[i].size(); ++j) {
        if (h[i][j] > h[i + 1][j]) {
          h[i].resize(j);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << '#' << h[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
