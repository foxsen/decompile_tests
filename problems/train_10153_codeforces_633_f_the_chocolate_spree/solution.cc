#include <bits/stdc++.h>
static void dfs_down(const std::vector<std::vector<long> > &g,
                     const std::vector<long> &a, long s, long p,
                     std::vector<long long> &down) {
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    dfs_down(g, a, t, s, down);
    down[s] = std::max(down[s], down[t]);
  }
  down[s] += a[s];
}
static void dfs_up(const std::vector<std::vector<long> > &g,
                   const std::vector<long> &a,
                   const std::vector<long long> &down, long s, long p,
                   std::vector<long long> &up) {
  std::set<std::pair<long long, long> > path;
  path.insert(std::make_pair(up[s], p));
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    path.insert(std::make_pair(down[t], t));
  }
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    path.erase(std::make_pair(down[t], t));
    up[t] = a[s] + path.rbegin()->first;
    dfs_up(g, a, down, t, s, up);
    path.insert(std::make_pair(down[t], t));
  }
}
static void dfs_path(const std::vector<std::vector<long> > &g,
                     const std::vector<long> &a,
                     const std::vector<long long> &down, long s, long p,
                     std::vector<long long> &path) {
  std::vector<long long> cost(2);
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    cost.push_back(down[t]);
    dfs_path(g, a, down, t, s, path);
  }
  std::sort(cost.begin(), cost.end(), std::greater<long long>());
  path[s] = cost[0] + cost[1] + a[s];
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    path[s] = std::max(path[s], path[t]);
  }
}
static long long dfs(const std::vector<std::vector<long> > &g,
                     const std::vector<long> &a,
                     const std::vector<long long> &down,
                     const std::vector<long long> &up,
                     const std::vector<long long> &path, long s, long p,
                     long long best) {
  std::set<std::pair<long long, long> > mx;
  std::set<std::pair<long long, long> > bs;
  mx.insert(std::make_pair(up[s], p));
  mx.insert(std::make_pair(0ll, -2l));
  bs.insert(std::make_pair(best, p));
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    mx.insert(std::make_pair(down[t], t));
    bs.insert(std::make_pair(path[t], t));
  }
  long long ans = best + path[s];
  for (long i = 0; i != (long)g[s].size(); ++i) {
    const long t = g[s][i];
    if (t == p) continue;
    mx.erase(std::make_pair(down[t], t));
    bs.erase(std::make_pair(path[t], t));
    const long long new_best = bs.rbegin()->first;
    long long size = a[s];
    std::set<std::pair<long long, long> >::reverse_iterator it = mx.rbegin();
    size += it->first;
    ++it;
    size += it->first;
    ans = std::max(std::max(ans, size + path[t]),
                   dfs(g, a, down, up, path, t, s, std::max(new_best, size)));
    bs.insert(std::make_pair(path[t], t));
    mx.insert(std::make_pair(down[t], t));
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long n;
  std::cin >> n;
  std::vector<long> a(n);
  for (long i = 0; i != n; ++i) std::cin >> a[i];
  std::vector<std::vector<long> > g(n);
  for (long i = 0; i != n - 1; ++i) {
    long u, v;
    std::cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  std::vector<long long> up(n), down(n), path(n);
  dfs_down(g, a, 0, -1, down);
  dfs_up(g, a, down, 0, -1, up);
  dfs_path(g, a, down, 0, -1, path);
  std::cout << dfs(g, a, down, up, path, 0, -1, 0ll) << "\n";
  return 0;
}
