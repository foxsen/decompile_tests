#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10, pi = acos(-1);
const int N = 2e6 + 10, M = 1e6 + 10, ha = 131, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int m, n;
vector<int> G[N];
long long ans;
map<vector<int>, bool> mp;
map<vector<int>, bool> mmp;
vector<int> as;
void solve() {
  scanf("%d", &n);
  vector<int> st;
  for (int i = 0, k, x; i < n; i++) {
    scanf("%d", &k);
    st.push_back(k - 1);
    while (k--) {
      scanf("%d", &x);
      G[i].push_back(x);
    }
  }
  scanf("%d", &m);
  while (m--) {
    vector<int> y;
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      y.push_back(x - 1);
    }
    mp[y] = 1;
  }
  queue<vector<int> > q;
  q.push(st);
  mmp[st] = 1;
  while (!q.empty()) {
    vector<int> x = q.front();
    q.pop();
    if (!mp[x]) {
      long long num = 0;
      for (int i = 0; i < n; i++) {
        num += G[i][x[i]];
      }
      if (num > ans) {
        ans = num;
        as = x;
      }
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (x[i] == 0) continue;
      x[i]--;
      if (!mmp[x]) {
        mmp[x] = 1;
        q.push(x);
      }
      x[i]++;
    }
  }
  for (int x : as) printf("%d ", x + 1);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
