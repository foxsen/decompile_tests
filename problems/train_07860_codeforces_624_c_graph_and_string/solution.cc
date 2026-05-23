#include <bits/stdc++.h>
using namespace std;
const int N = 2e6, MOD = 1e9 + 7;
const long double EPS = 0.000000001;
long long n, m;
map<long long, char> color;
vector<long long> g[N];
bool ok = false, used[N];
void dfs(long long v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) dfs(to);
  }
  set<char> s;
  for (auto to : g[v]) {
    s.insert(color[to]);
  }
  if (color[v] == 'a') {
    if (s.find('c') != s.end()) {
      cout << "No";
      exit(0);
    }
  }
  if (color[v] == 'c') {
    if (s.find('a') != s.end()) {
      cout << "No";
      exit(0);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) color[i] = 'z';
  for (long long i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    g[l].push_back(r);
    g[r].push_back(l);
  }
  for (long long i = 1; i <= n; i++) {
    if (g[i].size() + 1 == n) {
      color[i] = 'b';
    }
  }
  set<long long> s, s2;
  for (long long i = 1; i <= n; i++) {
    if (color[i] == 'z') {
      color[i] = 'a';
      s2.insert(i);
      for (auto to : g[i]) {
        if (color[to] == 'z') color[to] = 'a', s2.insert(to);
      }
      break;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (color[i] == 'z') color[i] = 'c', s.insert(i);
  }
  if (!s.empty()) {
    for (auto o : s) {
      set<long long> s1 = s;
      for (auto to : g[o]) {
        if (s1.find(to) != s1.end()) {
          s1.erase(to);
        }
      }
      if (s1.size() > 1) {
        cout << "No";
        return 0;
      }
    }
  }
  if (!s2.empty()) {
    for (auto o : s2) {
      set<long long> s1 = s2;
      for (auto to : g[o]) {
        if (s1.find(to) != s1.end()) {
          s1.erase(to);
        }
      }
      if (s1.size() > 1) {
        cout << "No";
        return 0;
      }
    }
  }
  dfs(1);
  cout << "Yes\n";
  for (long long i = 1; i <= n; i++) {
    cout << color[i];
  }
}
