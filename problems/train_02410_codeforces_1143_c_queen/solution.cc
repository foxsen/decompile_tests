#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxi = 0;
  cin >> n;
  vector<int> store[n + 1];
  map<int, int> s, s1;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x != -1) store[x].push_back(i + 1);
    s1[i + 1] = y;
    if (y == 1) s[x]++;
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if ((store[i].size() == s[i] && s1[i] == 1)) ans.push_back(i);
  }
  if (ans.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
