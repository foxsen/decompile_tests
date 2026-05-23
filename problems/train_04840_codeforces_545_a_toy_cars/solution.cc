#include <bits/stdc++.h>
using namespace std;
int a[107][107];
int n;
int b[107];
vector<int> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 3) {
        b[i]++;
        b[j]++;
      }
      if (a[i][j] == 2) {
        b[j]++;
      }
      if (a[i][j] == 1) {
        b[i]++;
      }
    }
  for (int i = 1; i <= n; i++)
    if (b[i] == 0) ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto t : ans) cout << t << " ";
  return 0;
}
