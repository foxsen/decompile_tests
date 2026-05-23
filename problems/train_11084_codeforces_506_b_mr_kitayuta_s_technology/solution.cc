#include <bits/stdc++.h>
using namespace std;
int n, m, ans, x, y, nrIN[100005];
vector<int> v[100005], N, ord[100005];
unordered_set<long long> S;
bool viz[100005], viz2[100005];
long long to_ll(int x, int y) { return 1LL * x * 1e6 + y; }
void dfs(int nod) {
  N.push_back(nod);
  viz[nod] = 1;
  for (auto it : v[nod]) {
    if (!viz[it]) dfs(it);
  }
}
int comp(int a, int b) {
  if (S.find(to_ll(b, a)) != S.end()) return 1;
  return 0;
}
void _sort(vector<int> &N) {
  vector<int> ans;
  for (int i = 0; i < N.size(); i++)
    if (nrIN[N[i]] == 0) ans.push_back(N[i]);
  for (int i = 0; i < ans.size(); i++) {
    for (auto it : ord[ans[i]]) {
      nrIN[it]--;
      if (nrIN[it] == 0) ans.push_back(it);
    }
  }
  if (ans.size() != N.size()) return;
  N = ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    ord[x].push_back(y);
    nrIN[y]++;
    S.insert(to_ll(x, y));
  }
  for (int i = 1; i <= n; i++) {
    if (!viz[i]) {
      N.clear();
      dfs(i);
      if (N.size() == 1) continue;
      _sort(N);
      int ok = 0;
      for (int j = 0; j < N.size() && !ok; j++) {
        viz2[N[j]] = 1;
        for (auto it : ord[N[j]]) {
          if (viz2[it]) {
            ok = 1;
            break;
          }
        }
      }
      ans += N.size() - 1 + ok;
    }
  }
  cout << ans << '\n';
  return 0;
}
