#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 7;
const int ALPHA = 40;
const long long INF = 1e16 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
const int BASE[2] = {313, 239};
long long n, d;
bool ns[MAXN], seen[MAXN];
vector<long long> group[MAXN], plast[MAXN];
void solve() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    group[i].clear();
    plast[i].clear();
  }
  for (int i = 0; i < n; i++) cin >> ns[i];
  fill(seen, seen + n, 0);
  long long ptr = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    ptr = i;
    if (seen[ptr]) continue;
    while (!seen[ptr]) {
      seen[ptr] = 1;
      group[cnt].push_back(ns[ptr]);
      ptr = (ptr + d) % n;
    }
    cnt++;
  }
  for (int i = 0; i < cnt; i++) {
    long long k = group[i].size();
    for (int j = 0; j < k; j++) group[i].push_back(group[i][j]);
    long long last = -INF;
    for (int j = 0; j < group[i].size(); j++) {
      if (!group[i][j]) last = j;
      plast[i].push_back(j - last);
    }
  }
  long long maxim = 0;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < group[i].size() / 2; j++) {
      maxim = max(maxim, min(plast[i][j], plast[i][j + (group[i].size() / 2)]));
    }
  }
  if (maxim >= INF)
    cout << -1 << '\n';
  else
    cout << maxim << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
