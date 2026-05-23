#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long int MOD = 1e9 + 7;
const int N = 1e6 + 6;
int baad[N];
int getLIS(vector<int>& vec, int frm, int to) {
  int ret = 0;
  vector<int> dp(to - frm + 5, INF);
  dp[0] = -INF;
  for (int i = frm; i <= to; i++) {
    if (baad[i]) continue;
    int x = vec[i];
    int id = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
    dp[id] = x;
    ret = max(ret, id);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> vec(n), lo(n), hi(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  if (k == 0) {
    for (int i = 0; i < n; i++) vec[i] -= i;
    int len = getLIS(vec, 0, n - 1);
    cout << n - len << '\n';
    return 0;
  }
  vector<int> ban(k);
  for (int i = 0; i < k; i++) cin >> ban[i], ban[i]--;
  for (int i = 1; i < k; i++) {
    if (vec[ban[i]] <= vec[ban[i - 1]]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i < k; i++) {
    int id1 = ban[i - 1];
    int id2 = ban[i];
    if (id2 == id1 + 1) continue;
    for (int j = id1 + 1, tmp = vec[id1] + 1; j < id2; j++, tmp++) {
      lo[j] = tmp;
    }
    for (int j = id2 - 1, tmp = vec[id2] - 1; j > id1; j--, tmp--) {
      hi[j] = tmp;
    }
    for (int j = id1 + 1; j < id2; j++) {
      if (lo[j] > hi[j]) {
        cout << -1 << '\n';
        return 0;
      }
      if (vec[j] < lo[j] || vec[j] > hi[j])
        baad[j] = 1;
      else
        vec[j] -= j;
    }
    int ret = getLIS(vec, id1 + 1, id2 - 1);
    int tot = id2 - id1 - 1 - ret;
    ans += tot;
  }
  if (ban[0] > 0) {
    int id = ban[0];
    for (int j = id - 1, tmp = vec[id] - 1; j >= 0; j--, tmp--) {
      hi[j] = tmp;
      if (vec[j] > hi[j])
        baad[j] = 1;
      else
        vec[j] -= j;
    }
    int tot = id - getLIS(vec, 0, id - 1);
    ans += tot;
  }
  if (ban.back() < n - 1) {
    int id = ban.back();
    for (int j = id + 1, tmp = vec[id] + 1; j < n; j++, tmp++) {
      lo[j] = tmp;
      if (vec[j] < lo[j])
        baad[j] = 1;
      else
        vec[j] -= j;
    }
    ans += n - id - 1 - getLIS(vec, id + 1, n - 1);
  }
  cout << ans << '\n';
  return 0;
}
