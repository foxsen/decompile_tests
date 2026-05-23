#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  int n = s.size();
  long long ans = 0, num = 0;
  vector<int> pref(n + 1);
  pref[0] = (s[0] == 'b');
  for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + (s[i] == 'b');
  for (int j = n - 1; j >= 0; j--) {
    if (s[j] == 'a') num++;
    ans = max(ans, pref[j] + num);
  }
  num = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      num++;
      int k = 0;
      ans = max(ans, num + pref[n - 1] - pref[i]);
      for (int j = n - 1; j > i; j--) {
        if (s[j] == 'a') k++;
        ans = max(ans, num + k + pref[j] - pref[i]);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    Solve();
  }
  return 0;
}
