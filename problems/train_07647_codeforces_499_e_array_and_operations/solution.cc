#include <bits/stdc++.h>
using namespace std;
const int MAXI = numeric_limits<int>::max() / 2;
const int MINI = numeric_limits<int>::min() / 2;
const long long MAXL = numeric_limits<long long>::max() / 2;
const long long MINL = numeric_limits<long long>::min() / 2;
static const int N = 110;
struct edge {
  edge(int a, int b, int c) : to(a), cap(b), res(c) {}
  int to, cap, res;
};
int A[N], S;
bool used[N];
vector<edge> G[1000 * N];
map<int, pair<int, int> > f[N];
void pf(int index) {
  int n = A[index];
  for (int i = 2; i * i <= n; ++i) {
    int s = 0;
    while (n % i == 0) {
      ++s;
      n /= i;
    }
    if (s > 0) {
      f[index][i].first = s;
      S += 1;
    }
  }
  if (n != 1) {
    f[index][n].first = 1;
    S += 1;
  }
}
int dfs(int v, int t, int f) {
  if (v == t) return f;
  used[v] = true;
  for (int i = 0; i != G[v].size(); ++i) {
    edge& e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.res].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int ans = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    ;
    int f = dfs(s, t, MAXI);
    if (f == 0) break;
    ans += f;
  }
  return ans;
}
int main(int argc, char* argv[]) {
  int i;
  int n, m, a, b;
  cin >> n >> m;
  for ((i) = (1); (i) < (n + 1); ++(i)) {
    cin >> A[i];
    pf(i);
  }
  int cnt = 0;
  for ((i) = (1); (i) < (n + 1); ++(i)) {
    if ((i & 1) == 1) {
      for (map<int, pair<int, int> >::iterator itr = f[i].begin();
           itr != f[i].end(); ++itr) {
        f[i][itr->first].second = ++cnt;
        G[0].push_back(edge(cnt, itr->second.first, G[cnt].size()));
        G[cnt].push_back(edge(0, 0, G[0].size() - 1));
      }
    } else {
      for (map<int, pair<int, int> >::iterator itr = f[i].begin();
           itr != f[i].end(); ++itr) {
        f[i][itr->first].second = ++cnt;
        G[cnt].push_back(edge(S + 1, itr->second.first, G[S + 1].size()));
        G[S + 1].push_back(edge(cnt, 0, G[cnt].size() - 1));
      }
    }
  }
  for ((i) = (0); (i) < (m); ++(i)) {
    cin >> a >> b;
    if ((a & 1) == 0) swap(a, b);
    for (map<int, pair<int, int> >::iterator itr = f[a].begin();
         itr != f[a].end(); ++itr) {
      int val = itr->first;
      map<int, pair<int, int> >::iterator pos = f[b].lower_bound(val);
      if (pos != f[b].end() && pos->first == val) {
        int cap = min(itr->second.first, pos->second.first);
        if (cap > 0) {
          int u = itr->second.second, v = pos->second.second;
          G[u].push_back(edge(v, cap, G[v].size()));
          G[v].push_back(edge(u, 0, G[u].size() - 1));
        }
      }
    }
  }
  cout << max_flow(0, S + 1) << endl;
  return 0;
}
