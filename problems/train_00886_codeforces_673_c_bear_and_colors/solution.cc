#include <bits/stdc++.h>
using namespace std;
int t[5005], n, used[5005], ret[5005];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    memset(used, 0, sizeof used);
    used[t[i]]++;
    int mx = t[i];
    ret[t[i]]++;
    for (int j = i + 1; j < n; ++j) {
      used[t[j]]++;
      if (used[t[j]] > used[mx] || (used[t[j]] == used[mx] && t[j] < mx))
        mx = t[j];
      ret[mx]++;
    }
  }
  for (int i = 1; i <= n; ++i) cout << ret[i] << " ";
  return 0;
}
