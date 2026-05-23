#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  if (0) return;
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  if (0) return;
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void get_it_done() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a < b) return gcd(b, a);
  return gcd(b, a % b);
}
const long long N = 1e5 + 5;
vector<long long> adjList[N];
long long color[N];
bool flag = 0;
void dfs(long long node, long long par, long long col) {
  if (color[node] != col) {
    flag = 0;
    return;
  }
  for (auto x : adjList[node]) {
    if (x != par) {
      dfs(x, node, col);
    }
  }
}
bool solve(long long node) {
  for (auto x : adjList[node]) {
    flag = 1;
    dfs(x, node, color[x]);
    if (!flag) return 0;
  }
  return 1;
}
int32_t main() {
  get_it_done();
  long long q = 1;
  while (q--) {
    long long n;
    cin >> n;
    for (long long i = 1; i < n; ++i) {
      long long u, v;
      cin >> u >> v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    for (long long i = 1; i < n + 1; ++i) cin >> color[i];
    long long node1 = -1;
    long long node2 = -1;
    for (long long i = 1; i < n + 1; ++i) {
      for (auto x : adjList[i]) {
        if (color[i] != color[x]) {
          node1 = i;
          node2 = x;
          break;
        }
      }
      if (node1 != -1) break;
    }
    if (node1 == -1) {
      cout << "YES"
           << "\n";
      cout << 1 << "\n";
      continue;
    }
    bool ans1 = solve(node1);
    bool ans2 = solve(node2);
    if (ans1) {
      cout << "YES"
           << "\n";
      cout << node1 << "\n";
    } else if (ans2) {
      cout << "YES"
           << "\n";
      cout << node2 << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
