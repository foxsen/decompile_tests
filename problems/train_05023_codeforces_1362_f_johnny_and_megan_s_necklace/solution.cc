#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e5;
int n, part[MAX_N][2], used[1 << 20];
vector<pair<int, int>> gr[1 << 20];
void dfs(int v) {
  used[v] = 1;
  for (auto e : gr[v])
    if (!used[e.first]) dfs(e.first);
}
bool check(int mask) {
  for (int i = 0; i <= mask; ++i) {
    gr[i].clear();
    used[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int u = part[i - 1][0] & mask;
    int v = part[i - 1][1] & mask;
    gr[u].push_back({v, 2 * i - 1});
    gr[v].push_back({u, 2 * i - 2});
  }
  int comps = 0;
  for (int i = 0; i <= mask; ++i) {
    if (gr[i].size() % 2) return false;
    if (!used[i] && !gr[i].empty()) {
      ++comps;
      dfs(i);
    }
  }
  return comps == 1;
}
vector<int> ans;
void euler_cycle(int v, int prv = -1) {
  while (gr[v].size()) {
    auto e = gr[v].back();
    gr[v].pop_back();
    if (used[e.second / 2]) continue;
    used[e.second / 2] = 1;
    euler_cycle(e.first, e.second);
  }
  if (prv != -1) {
    ans.push_back(prv);
    ans.push_back(prv ^ 1);
  }
}
void restore(int mask) {
  fill(used, used + n + 1, 0);
  for (int i = 0; i <= mask; ++i) {
    if (!gr[i].empty()) {
      euler_cycle(i);
      break;
    }
  }
  for (int i = 0; i < 2 * n; ++i) cout << ans[i] + 1 << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> part[i][0] >> part[i][1];
  for (int i = 20; i >= 0; --i) {
    if (check((1 << i) - 1)) {
      cout << i << '\n';
      restore((1 << i) - 1);
      return 0;
    }
  }
  return 0;
}
