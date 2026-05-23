#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 200;
vector<long long int> gr[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, tc;
  tc = 1;
  while (tc--) {
    long long int n;
    cin >> n;
    long long int a[n];
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != 0) v.push_back(a[i]);
    }
    if (v.size() > 150) {
      cout << 3 << "\n";
      return 0;
    }
    for (i = 0; i < v.size(); i++) {
      for (j = i + 1; j < v.size(); j++) {
        if (v[i] & v[j]) {
          gr[i].push_back(j);
          gr[j].push_back(i);
        }
      }
    }
    long long int ans = n + 1;
    for (i = 0; i < v.size(); i++) {
      vector<long long int> dis(n + 5, 1e9);
      dis[i] = 0;
      vector<long long int> par(n + 5, -1);
      queue<long long int> q;
      q.push(i);
      while (!q.empty()) {
        long long int u = q.front();
        q.pop();
        for (auto child : gr[u]) {
          if (dis[child] == (int)(1e9)) {
            dis[child] = dis[u] + 1;
            q.push(child);
            par[child] = u;
          } else if (par[child] != u && par[u] != child) {
            ans = min(ans, dis[u] + dis[child] + 1);
          }
        }
      }
    }
    if (ans == n + 1) ans = -1;
    cout << ans;
  }
  return 0;
}
