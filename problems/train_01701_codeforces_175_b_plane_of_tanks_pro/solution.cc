#include <bits/stdc++.h>
using namespace std;
void mego() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int n, a, b, c, d, x;
  string s;
  a = b = c = d = 0;
  cin >> n;
  map<string, int> ma;
  vector<pair<int, string>> mb;
  vector<int> v;
  set<int> se;
  map<string, string> ans;
  for (int i = 0; i < n; i++) {
    cin >> s >> x;
    if (ma.count(s))
      ma[s] = max(x, ma[s]);
    else
      ma[s] = x;
  }
  for (auto it : ma) {
    mb.push_back({it.second, it.first});
    se.insert(it.second);
  }
  for (auto it : se) {
    v.push_back(it);
  }
  sort(mb.begin(), mb.end());
  x = 0;
  int idx = 0;
  for (int i = 0; i < mb.size(); i++) {
    a = i;
    for (int j = i; j < mb.size(); j++)
      if (mb[j].first == mb[i].first)
        a = j;
      else
        break;
    a = (((a + 1) * 100) / mb.size());
    if (a >= 99)
      ans[mb[i].second] = "pro";
    else if (a >= 90)
      ans[mb[i].second] = "hardcore";
    else if (a >= 80)
      ans[mb[i].second] = "average";
    else if (a >= 50)
      ans[mb[i].second] = "random";
    else
      ans[mb[i].second] = "noob";
    x++;
  }
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it.first << " " << it.second << "\n";
  return 0;
}
