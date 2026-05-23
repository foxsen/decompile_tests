#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (auto &x : a) cin >> x;
    ;
    a.push_back(0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (!mp[a[i]]) {
        ans[i] = a[i];
        mp[a[i]]++;
      }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      while (mp[cnt] > 0) cnt++;
      if (ans[i] == 0) {
        ans[i] = cnt;
        cnt++;
      }
    }
    int flg = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] > a[i]) flg = 1;
    }
    if (flg)
      cout << "-1\n";
    else {
      for (auto x : ans) cout << x << " ";
      ;
      cout << "\n";
    }
  }
}
