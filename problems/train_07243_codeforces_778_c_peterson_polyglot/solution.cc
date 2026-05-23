#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
template <class T>
void dbs(string str, T t) {
  cout << str << " : " << t << "\n";
}
template <class T, class... second>
void dbs(string str, T t, second... s) {
  int idx = str.find(',');
  cout << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class second, class T>
ostream& operator<<(ostream& os, const pair<second, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class second, class T>
ostream& operator<<(ostream& os, const map<second, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cout << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cout << ", ";
    cout << *i;
  }
  cout << "]\n";
}
const int N = 1e6;
int n;
map<int, vector<int> > g[N];
int ans[N], sub[N];
void dfs(int u, int d) {
  sub[u] = 1;
  for (auto it : g[u]) {
    g[it.second[0]][it.first].erase(find((g[it.second[0]][it.first]).begin(),
                                         (g[it.second[0]][it.first]).end(), u));
    if (g[it.second[0]][it.first].empty()) g[it.second[0]].erase(it.first);
    dfs(it.second[0], d + 1);
    sub[u] += sub[it.second[0]];
  }
  if (sub[u] > 1) ans[d] -= sub[u];
}
int ctr;
vector<pair<int, int> > toErase;
int insert(int to, int from) {
  int ans = 0;
  for (auto it : g[from]) {
    if (g[to].count(it.first)) {
      ans += insert(g[to][it.first][0], it.second[0]);
    } else {
      g[to][it.first].push_back(++ctr);
      if (to <= n) toErase.emplace_back(to, it.first);
      ++ans;
      ans += insert(ctr, it.second[0]);
    }
  }
  return ans;
}
void test(int u, int d) {
  if (g[u].empty()) return;
  for (auto it : g[u]) {
    test(it.second[0], d + 1);
  }
  pair<int, int> mx;
  for (auto it : g[u]) {
    mx = max(mx, pair<int, int>(sub[it.second[0]], it.first));
  }
  ctr = n;
  ans[d] += mx.first;
  for (auto it : g[u]) {
    if (it.first == mx.second) continue;
    ans[d] += insert(g[u][mx.second][0], it.second[0]);
  }
  for (int it = (n + 1); it <= (ctr); ++it) g[it].clear();
  for (pair<int, int> it : toErase) {
    g[it.first].erase(it.second);
  }
  toErase.clear();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int _ = (1); _ <= (n - 1); ++_) {
    int u, v;
    char x;
    cin >> u >> v >> x;
    g[u][x - 'a'].push_back(v);
    g[v][x - 'a'].push_back(u);
  }
  for (int i = (1); i <= (n); ++i) ans[i] = n;
  dfs(1, 1);
  test(1, 1);
  int yo = n;
  for (int i = (1); i <= (n); ++i) yo = min(yo, ans[i]);
  cout << yo << "\n";
  for (int i = (1); i <= (n); ++i)
    if (ans[i] == yo) {
      cout << i << "\n";
      return 0;
    }
}
