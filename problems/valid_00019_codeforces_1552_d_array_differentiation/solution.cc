#include <bits/stdc++.h>
using namespace std;
vector<bool> isprime(1e6 + 6, true);
struct node {
  long long int val;
  long long int index;
};
void Sieve(long long int maxn) {
  long long int j;
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < sqrt(maxn) + 1; i++) {
    if (isprime[i]) {
      for (j = i * i; j <= maxn; j += i) {
        isprime[j] = false;
      }
    }
  }
}
bool sortbysec(const pair<long long int, long long int> &c,
               const pair<long long int, long long int> &d) {
  if (c.second < d.second)
    return c.second < d.second;
  else
    return c.first < d.first;
}
vector<vector<long long int> > adj(3e6);
vector<bool> visited(1e6 + 1, false);
long long int modpow(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void dfs(long long int par, long long int v) {
  for (auto u : adj[v]) {
    if (u == par) continue;
    dfs(v, u);
  }
}
vector<bool> vis(1e6 + 1, false);
void bfs(long long int v, long long int par) {
  queue<int> q;
  q.push(v);
  vis[v] = true;
  while (!q.empty()) {
    long long int s = q.front();
    q.pop();
    for (auto x : adj[s]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push(x);
      }
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    long long int b;
    cin >> b;
    a[i] = abs(b);
  }
  if (n == 1) {
    if (!a[0])
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  map<long long int, long long int> f;
  for (long long int i = 0; i < n; i++) {
    if (f[a[i]]) {
      cout << "YES\n";
      return;
    }
    f[a[i]] = 1;
  }
  map<long long int, long long int> sum;
  set<long long int> universal;
  universal.insert(0);
  sort(a.begin(), a.end());
  long long int prev = 0;
  for (long long int i = 0; i < n; i++) {
    if (universal.find(a[i]) != universal.end()) {
      cout << "YES\n";
      return;
    }
    vector<long long int> temp;
    for (auto x : universal) {
      temp.push_back(a[i] + x);
      temp.push_back(abs(x - a[i]));
    }
    for (auto x : temp) universal.insert(x);
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
