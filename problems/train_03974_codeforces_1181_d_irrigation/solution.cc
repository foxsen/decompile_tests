#include <bits/stdc++.h>
using pii = std::pair<long long, long long>;
using namespace std;
const long long maxn = 5e5 + 5, maxbit = 18;
long long n, m, q, k, a[maxn], cnt[maxn], pref[maxn], ans[maxn],
    bit[maxn] = {0};
long long sum(long long idx) {
  long long ans = 0;
  for (++idx; idx > 0; idx -= idx & -idx) ans += bit[idx];
  return ans;
}
void add(long long idx, long long val) {
  for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += val;
}
long long find(long long val) {
  long long sum = 0;
  long long pos = 0;
  for (long long i = maxbit; i >= 0; i--)
    if (pos + (1 << i) < maxn && sum + bit[pos + (1 << i)] < val) {
      sum += bit[pos + (1 << i)];
      pos += (1 << i);
    }
  return pos;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }
  vector<pii> order;
  for (long long i = 0; i < m; i++) order.push_back({cnt[i], i});
  sort(order.begin(), order.end());
  pref[0] = order[0].first;
  for (long long i = 1; i < m; i++) pref[i] = pref[i - 1] + order[i].first;
  vector<pii> queries;
  for (long long i = 0; i < q; i++) {
    cin >> k;
    k -= n + 1;
    queries.push_back({k, i});
  }
  sort(queries.begin(), queries.end());
  long long cur = -1;
  for (long long i = 0; i < q; i++) {
    while (cur < m - 1 && queries[i].first >= (cur + 2) * order[cur + 1].first -
                                                  pref[cur + 1]) {
      cur++;
      add(order[cur].second, 1);
    }
    queries[i].first -= (cur + 1) * order[cur].first - pref[cur];
    ans[queries[i].second] = find((queries[i].first % (cur + 1)) + 1);
  }
  for (long long i = 0; i < q; i++) cout << ans[i] + 1 << "\n";
  return 0;
}
