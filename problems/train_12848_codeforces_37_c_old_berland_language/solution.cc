#include <bits/stdc++.h>
using namespace std;
void add(string &s) {
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') {
      s[i] = '1';
      return;
    } else {
      s[i] = '0';
    }
  }
  s = "";
}
int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, int> > vp;
    string ans[1000];
    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;
      vp.push_back(make_pair(l, i));
    }
    bool ok = true;
    string cur = "0";
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++) {
      if (cur.size() == 0) {
        ok = false;
        break;
      }
      while (cur.size() != vp[i].first) cur += "0";
      ans[vp[i].second] = cur;
      add(cur);
    }
    puts(ok ? "YES" : "NO");
    if (ok) {
      for (int i = 0; i < n; i++) cout << ans[i] << endl;
    }
  }
}
