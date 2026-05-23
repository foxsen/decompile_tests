#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void process(vector<int> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
int cc(vector<int> v, int l, int r) {
  v.insert(v.begin(), l);
  v.push_back(r);
  assert(v.size() >= 2);
  int len = r - l;
  int mx = 0;
  for (int i = 1; i < v.size(); i++) mx = max(mx, v[i] - v[i - 1]);
  return len - mx;
}
int solve(int l, int r, vector<int> rr, vector<int> bb) {
  if (l == 0 && r == INF) {
    int ans = 0;
    if (rr.size()) ans += rr.back() - rr[0];
    if (bb.size()) ans += bb.back() - bb[0];
    return ans;
  } else if (l == 0) {
    int ans = 0;
    if (rr.size()) ans += r - rr[0];
    if (bb.size()) ans += r - bb[0];
    return ans;
  } else if (r == INF) {
    int ans = 0;
    if (rr.size()) ans += rr.back() - l;
    if (bb.size()) ans += bb.back() - l;
    return ans;
  } else {
    int ans1 = 2 * (r - l);
    int rcost = cc(rr, l, r);
    int bcost = cc(bb, l, r);
    int cc = r - l + rcost + bcost;
    int ans = min(ans1, cc);
    return ans;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> red, green, blue;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    char c;
    cin >> x >> c;
    if (c == 'R') red.push_back(x);
    if (c == 'G') green.push_back(x);
    if (c == 'B') blue.push_back(x);
  }
  process(red);
  process(blue);
  process(green);
  green.insert(green.begin(), 0);
  green.push_back(INF);
  int ans = 0;
  for (int i = 1; i < green.size(); i++) {
    int l = green[i - 1], r = green[i];
    vector<int> rr, bb;
    auto st = upper_bound(red.begin(), red.end(), l);
    auto en = lower_bound(red.begin(), red.end(), r);
    for (auto it = st; it != en; it++) rr.push_back(*it);
    st = upper_bound(blue.begin(), blue.end(), l);
    en = lower_bound(blue.begin(), blue.end(), r);
    for (auto it = st; it != en; it++) bb.push_back(*it);
    ans += solve(l, r, rr, bb);
  }
  cout << ans << endl;
}
