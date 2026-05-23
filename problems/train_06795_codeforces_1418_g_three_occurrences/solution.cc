#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
using namespace std;
const int maxn = 5e5 + 5;
int n, pr[maxn], id[maxn];
long long a[maxn];
map<long long, int> cnt;
vector<int> pos[maxn];
long long Rand(long long l, long long h) {
  return l +
         ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
          (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
          (long long)rand() * (RAND_MAX + 1) + rand()) %
             (h - l + 1);
}
void readf() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    pr[i] = id[a[i]];
    id[a[i]] = i;
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) pos[a[i]].emplace_back(i);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < pos[i].size(); ++j)
      if (j < 2)
        a[pos[i][j]] = Rand(0, 1000000000000000000);
      else
        a[pos[i][j]] = a[pos[i][j - 1]] ^ a[pos[i][j - 2]];
  for (int i = 1; i <= n; ++i) a[i] ^= a[i - 1];
  int sub_pos = 0, maintain = 0;
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    sub_pos = max(sub_pos, pr[pr[pr[i]]]);
    while (maintain < sub_pos) cnt[a[maintain++]]--;
    ans += cnt[a[i]];
    cnt[a[i]]++;
  }
  cout << ans << '\n';
}
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readf();
  solve();
}
