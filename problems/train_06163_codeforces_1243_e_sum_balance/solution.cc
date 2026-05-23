#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int M = 5010;
const int inf = 0x3f3f3f3f;
int a[N][M], c[N], two[N << 1], f[1 << N], mix[1 << N];
long long sum[N], tot;
map<long long, int> mp;
pair<int, int> loop[1 << N], ans[N];
void init(void) {
  two[0] = 1;
  for (int i = 1; i <= 20; ++i) {
    two[i] = two[i - 1] << 1;
  }
}
void dfs(int sta) {
  if (mix[sta] != inf) {
    dfs(mix[sta]);
    dfs(sta ^ mix[sta]);
  } else {
    int x = loop[sta].first, y = loop[sta].second;
    int want = tot - sum[x] + y;
    while (want != y) {
      ans[mp[want]].first = want;
      ans[mp[want]].second = x;
      x = mp[want];
      want += tot - sum[mp[want]];
    }
    ans[mp[want]].first = want;
    ans[mp[want]].second = x;
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(0);
  init();
  int k;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; ++j) {
      cin >> a[i][j];
      sum[i] += a[i][j];
      mp[a[i][j]] = i;
    }
    tot += sum[i];
  }
  if (tot % k) {
    cout << "No" << endl;
    return 0;
  }
  tot /= k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= c[i]; ++j) {
      int sta = 0;
      sta |= two[i - 1];
      long long want = tot - sum[i] + a[i][j];
      while (mp.count(want) && !(sta & two[mp[want] - 1])) {
        sta |= two[mp[want] - 1], want += tot - sum[mp[want]];
      }
      if (want == a[i][j]) {
        f[sta] = 1;
        loop[sta].first = i, loop[sta].second = a[i][j];
      }
    }
  }
  memset(mix, inf, sizeof mix);
  for (int msk = 1; msk < two[k]; ++msk) {
    for (int i = msk; i > 0; i = (i - 1) & msk) {
      if (!f[msk] && f[i] && f[msk ^ i]) {
        f[msk] = 1;
        mix[msk] = i;
      }
    }
  }
  if (!f[two[k] - 1]) {
    cout << "No" << endl;
    return 0;
  }
  dfs(two[k] - 1);
  cout << "Yes" << endl;
  for (int i = 1; i <= k; ++i) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
  return 0;
}
