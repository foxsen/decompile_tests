#include <bits/stdc++.h>
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cout.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
using namespace std;
long long n, m, s;
vector<vector<long long>> adj;
vector<bool> visited;
vector<long long> times;
void dfs(long long from) {
  visited[from] = true;
  for (long long i = 0; i < adj[from].size(); i++) {
    long long to = adj[from][i];
    if (!visited[to]) {
      dfs(to);
    }
  }
}
void time_dfs(long long from) {
  visited[from] = true;
  for (long long i = 0; i < adj[from].size(); i++) {
    long long to = adj[from][i];
    if (!visited[to]) {
      time_dfs(to);
    }
  }
  times.push_back(from);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  s--;
  adj.resize(n);
  visited.resize(n, false);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
  }
  dfs(s);
  for (long long f = 0; f < n; f++) {
    if (!visited[f]) time_dfs(f);
  }
  visited.assign(n, false);
  long long comps = 0;
  for (long long i = (long long)times.size() - 1; i >= 0; i--) {
    if (!visited[times[i]]) {
      dfs(times[i]);
      comps++;
    }
  }
  cout << comps << endl;
  return 0;
}
