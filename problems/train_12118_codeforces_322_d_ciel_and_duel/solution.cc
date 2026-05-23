#include <bits/stdc++.h>
using namespace std;
vector<int> ja, jd, ca;
int main() {
  int n, m, v;
  string t;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> t >> v;
    if (t[0] == 'A')
      ja.push_back(v);
    else
      jd.push_back(v);
  }
  for (int i = 0; i < m; i++) {
    cin >> v;
    ca.push_back(v);
  }
  sort(ja.begin(), ja.end());
  sort(jd.begin(), jd.end());
  sort(ca.begin(), ca.end());
  int ans = 0;
  for (int a = 1; a < 1 + min(ja.size(), ca.size()); a++) {
    int a2 = 0;
    for (int i = 0; i < a; i++) {
      v = ca[ca.size() - 1 - i] - ja[a - 1 - i];
      if (v < 0) {
        a2 = 0;
        break;
      }
      a2 += v;
    }
    ans = max(ans, a2);
  }
  if (m >= n) {
    bool ok = true;
    for (int i = 0; i < jd.size(); i++) {
      vector<int>::iterator it = lower_bound(ca.begin(), ca.end(), jd[i] + 1);
      if (it == ca.end()) {
        ok = false;
        break;
      }
      ca.erase(it);
    }
    if (ok) {
      int a2 = 0;
      while (ca.size() > 0) {
        if (ja.size() == 0) {
          a2 += ca[ca.size() - 1];
          ca.erase(ca.begin() + ca.size() - 1);
          continue;
        }
        if (ja[ja.size() - 1] <= ca[ca.size() - 1]) {
          a2 += (-ja[ja.size() - 1] + ca[ca.size() - 1]);
          ca.erase(ca.begin() + ca.size() - 1);
          ja.erase(ja.begin() + ja.size() - 1);
        } else {
          a2 = 0;
          break;
        }
      }
      ans = max(ans, a2);
    }
  }
  cout << ans << endl;
}
