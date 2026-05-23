#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long g, h, l;
const long long N = 10005, inf = 1e9 + 5;
long long ans = 0;
long long add(long long a, long long b);
long long mul(long long a, long long b);
long long binpo(long long a, long long b);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long arr[n];
  long long cnt[63] = {};
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    g = arr[i];
    long long temp = 0;
    while (arr[i] > 0) {
      if (arr[i] % 2) {
        cnt[temp]++;
      }
      temp++;
      arr[i] /= 2;
    }
    arr[i] = g;
  }
  bool vis[63] = {false};
  for (long long i = 0; i < 63; i++) {
    if (cnt[i] > 2) {
      cout << 3;
      return 0;
    }
  }
  vector<long long> nodes;
  for (long long i = 0; i < n; i++) {
    if (arr[i]) {
      nodes.push_back(arr[i]);
    }
  }
  n = (long long)nodes.size();
  vector<long long> adj[n];
  for (long long i = 0; i < (long long)nodes.size(); i++) {
    for (long long j = 0; j < (long long)nodes.size(); j++) {
      if (i == j) continue;
      if ((nodes[i] & nodes[j]) != 0) {
        adj[i].push_back(j);
      }
    }
  }
  long long ans = 1e18;
  for (long long i = 0; i < (long long)nodes.size(); i++) {
    vector<long long> dis(n, 1e9);
    vector<long long> par(n, -1);
    dis[i] = 0;
    queue<pair<long long, long long>> q;
    q.push({i, -1});
    while (!q.empty()) {
      auto top = q.front().first;
      auto pappa = q.front().second;
      q.pop();
      for (auto c : adj[top]) {
        if (c == pappa) continue;
        if (dis[c] == 1e9) {
          dis[c] = dis[top] + 1;
          par[c] = top;
          q.push({c, top});
        } else {
          ans = min(ans, dis[top] + dis[c] + 1);
        }
      }
    }
  }
  if (ans < 1e8) {
    cout << ans;
  } else {
    cout << -1;
  }
}
long long add(long long a, long long b) { return (a % MOD + b % MOD) % MOD; }
long long mul(long long a, long long b) { return (a * 1ll * b) % MOD; }
long long binpo(long long a, long long b) {
  int ans = 1;
  while (b) {
    if (b % 2 != 0) {
      ans = mul(ans, a);
    }
    a = mul(a, a);
    b = b / 2;
  }
  return ans;
}
