#include <bits/stdc++.h>
using namespace std;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector<int> ans;
int main() {
  int n, k;
  cin >> n;
  k = 2 * n * n;
  ans.push_back(1);
  for (int i = 0; ans.size() < n; ++i) {
    for (int j = 0; j < ans.size(); ++j) {
      if (p[i] * ans[j] <= k) {
        ans.push_back(p[i] * ans[j]);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
