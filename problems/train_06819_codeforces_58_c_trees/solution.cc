#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> save(1e5 + 1);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int x = a - min(i, n - 1 - i);
    assert(x < (int)save.size());
    if (x > 0) ++save[x];
  }
  int ans = 1e9;
  for (int i = 1; i < save.size(); ++i) {
    ans = min(ans, n - save[i]);
  }
  cout << ans << '\n';
  return 0;
}
