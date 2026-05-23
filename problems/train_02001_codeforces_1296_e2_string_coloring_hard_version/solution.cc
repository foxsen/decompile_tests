#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1000000007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<int, vector<int>> lis(vector<int> v) {
  vector<int> ans(v.size());
  int color = 0;
  set<pair<int, int>> best;
  for (int i = 0; i < v.size(); ++i) {
    auto it = best.lower_bound({v[i], 0});
    if (it == best.begin() && (*it).first != v[i]) {
      color++;
      ans[i] = color;
      best.insert({v[i], i});
    } else if ((*it).first != v[i]) {
      it--;
      ans[i] = ans[(*it).second];
      best.insert({v[i], i});
      best.erase(it);
    } else {
      ans[i] = ans[(*it).second];
      best.insert({v[i], i});
      best.erase(it);
    }
  }
  return {color, ans};
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  for (int i = 0; i < (int)s.size(); i++) {
    v.push_back(s[i]);
  }
  pair<int, vector<int>> aux = lis(v);
  int color = aux.first;
  vector<int> ans = aux.second;
  cout << color << "\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ;
  solve();
  return 0;
}
