#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  solve();
  return 0;
}
template <typename T>
void prv(vector<T> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    if (__ii) cout << ' ';
    cout << v[__ii];
  }
  cout << '\n';
}
template <typename T>
void prm(vector<vector<T>> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    for (int __jj = 0; __jj < v[__ii].size(); __jj++) {
      if (__jj) cout << ' ';
      cout << v[__ii][__jj];
    }
    cout << '\n';
  }
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void pr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void pr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  pr(tail...);
}
template <typename... T>
void err(const T&... cod) {
  pr(cod...);
  exit(0);
}
string cell(int y, int x) {
  y++;
  x++;
  string ys, xs, ans;
  ans.push_back('(');
  while (y > 0) {
    ys.push_back((y % 10) + '0');
    y /= 10;
  }
  reverse(ys.begin(), ys.end());
  ans += ys;
  ans.push_back(',');
  while (x > 0) {
    xs.push_back((x % 10) + '0');
    x /= 10;
  }
  reverse(xs.begin(), xs.end());
  ans += xs;
  ans.push_back(')');
  return ans;
}
vector<string> get(int y, int x) {
  vector<string> ans;
  int cury = 0, curx = 0;
  while (cury < y) {
    ans.push_back(cell(cury, curx));
    cury++;
  }
  while (curx < x) {
    ans.push_back(cell(cury, curx));
    curx++;
  }
  ans.push_back(cell(cury, curx));
  return ans;
}
void solve() {
  int n, m, k;
  sc(n, m, k);
  vector<vector<pair<int, int>>> pos(n + m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) pos[i + j].emplace_back(i, j);
  vector<vector<string>> ans;
  int cost = 0;
  for (int i = 0; i < n + m; i++) {
    int pick = min(k, ((int)pos[i].size()));
    cost += pick * (i + 1);
    for (int j = 0; j < pick; j++)
      ans.push_back(get(pos[i][j].first, pos[i][j].second));
    k -= pick;
  }
  reverse(ans.begin(), ans.end());
  pr(cost);
  for (auto p : ans) prv(p);
}
