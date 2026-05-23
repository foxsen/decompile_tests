#include <bits/stdc++.h>
using namespace std;
int n, cnt, p[100001], b[100001];
vector<int> v;
void dfs(int x) {
  if (!b[x]) {
    b[x] = 1;
    ++cnt;
    dfs(p[x]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (long long i = 1; i <= n; ++i) {
    if (!b[i]) {
      cnt = 0;
      dfs(i);
      v.push_back(cnt);
    }
  }
  sort(v.rbegin(), v.rend());
  long long ans = 0;
  if (v.size() > 1) {
    ans += 1LL * (v[0] + v[1]) * (v[0] + v[1]);
  } else
    ans = 1LL * v[0] * v[0];
  for (int i = 2; i < v.size(); ++i) {
    ans += 1LL * v[i] * v[i];
  }
  cout << ans;
}
