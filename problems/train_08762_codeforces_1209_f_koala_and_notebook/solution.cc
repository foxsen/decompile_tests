#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7, mod = 1e9 + 7, inf = 1e9, MAXN = 1e6 + 7;
const double eps = 1e-9;
mt19937 rnd(time(0));
int n, m;
int ptr = 0;
vector<pair<int, int> > gr[maxn];
int dp[maxn];
void bfs() {
  deque<int> q;
  q.push_back(0);
  for (int i = 0; i < maxn; ++i) dp[i] = inf;
  dp[0] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop_front();
    for (auto v : gr[u]) {
      if (dp[v.first] == inf) {
        dp[v.first] = dp[u] + 1;
        q.push_back(v.first);
      }
    }
  }
}
struct node {
  int u, clas, val;
  node(int u, int clas, int val) : u(u), clas(clas), val(val) {}
  node() : u(0), clas(0), val(0) {}
};
struct state {
  int clas, val, add;
  state(int clas, int val, int add) : clas(clas), val(val), add(add) {}
  state() : clas(0), val(0), add(0) {}
};
vector<state> value[maxn];
bool cmp(state p1, state p2) {
  return (p1.clas < p2.clas) || (p1.clas == p2.clas && p1.add < p2.add);
}
bool cmp1(pair<state, int> p1, pair<state, int> p2) {
  state a = p1.first;
  state b = p2.first;
  return cmp(a, b);
}
int ANS[maxn];
void get() {
  deque<node> q;
  q.emplace_back(0, 0, 0);
  while (q.size()) {
    vector<int> vertex;
    for (auto cur : q) {
      for (auto v : gr[cur.u]) {
        if (dp[v.first] == dp[cur.u] + 1) {
          value[v.first].emplace_back(
              cur.clas, ((long long)cur.val * 10 + v.second) % mod, v.second);
          if (value[v.first].size() == 1) {
            vertex.push_back(v.first);
          }
        }
      }
    }
    q.clear();
    if (vertex.size() == 0) continue;
    vector<pair<state, int> > result;
    for (auto v : vertex) {
      sort(value[v].begin(), value[v].end(), cmp);
      result.emplace_back(value[v][0], v);
      ANS[v] = value[v][0].val;
    }
    sort(result.begin(), result.end(), cmp1);
    int ptr = 0;
    q.emplace_back(result[0].second, ptr, ANS[result[0].second]);
    for (int i = 1; i < (int)result.size(); ++i) {
      state a = result[i - 1].first;
      state b = result[i].first;
      if (a.clas != b.clas || a.add != b.add) {
        ++ptr;
      }
      q.emplace_back(result[i].second, ptr, ANS[result[i].second]);
    }
  }
}
void solve() {
  cin >> n >> m;
  int ptr = n;
  for (int val = 1; val <= m; ++val) {
    int a, b;
    cin >> a >> b, --a, --b;
    vector<int> symb;
    int x = val;
    while (x) {
      symb.push_back(x % 10);
      x /= 10;
    }
    reverse(symb.begin(), symb.end());
    vector<int> vertex;
    vertex.push_back(a);
    for (int i = 0; i < (int)symb.size() - 1; ++i) vertex.push_back(ptr++);
    vertex.push_back(b);
    for (int i = 1; i < (int)vertex.size(); ++i) {
      int u = vertex[i - 1];
      int v = vertex[i];
      gr[u].emplace_back(v, symb[i - 1]);
    }
    vertex.clear();
    vertex.push_back(b);
    for (int i = 0; i < (int)symb.size() - 1; ++i) vertex.push_back(ptr++);
    vertex.push_back(a);
    for (int i = 1; i < (int)vertex.size(); ++i) {
      int u = vertex[i - 1];
      int v = vertex[i];
      gr[u].emplace_back(v, symb[i - 1]);
    }
  }
  bfs();
  get();
  for (int i = 1; i < n; ++i) cout << ANS[i] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
