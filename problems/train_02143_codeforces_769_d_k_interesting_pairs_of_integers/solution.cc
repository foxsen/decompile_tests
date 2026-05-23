#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4 + 2;
vector<int> adj[mxN], cnt(mxN);
int main() {
  long long int n, a, b, m, i, j, cn = 0, sm = 0, mx = INT_MIN, mn = INT_MAX, k;
  string s;
  cin >> n >> m;
  for (i = 0; i <= 10000; i++)
    for (j = i; j <= 10000; j++) {
      if (__builtin_popcount(i ^ j) == m) {
        adj[i].push_back(j);
        if (i != j) adj[j].push_back(i);
      }
    }
  for (i = 0; i < n; i++) cin >> a, cnt[a]++;
  for (i = 0; i <= 10000; i++) {
    for (auto j : adj[i]) sm += cnt[i] * (long long int)cnt[j];
  }
  if (!m) sm -= n;
  cout << sm / 2 << "\n";
  return 0;
}
