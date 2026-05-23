#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
void solve() {
  ll n, T, a, b;
  cin >> n >> T >> a >> b;
  using P = pair<ll, ll>;
  vector<P> v(n);
  for (int i = 0; i < (int)(n); i++) cin >> v[i].second;
  for (int i = 0; i < (int)(n); i++) cin >> v[i].first;
  sort((v).begin(), (v).end());
  ll e_cnt = 0, d_cnt = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (v[i].second == 0)
      e_cnt++;
    else
      d_cnt++;
  }
  ll ans = 0;
  ll tmp = min(e_cnt, (v[0].first - 1) / a);
  tmp += min(d_cnt, (v[0].first - 1 - a * tmp) / b);
  ans = max(0LL, tmp);
  ll now_time = 0;
  for (int i = 1; i < n; i++) {
    if (v[i - 1].second == 0) {
      e_cnt--;
      now_time += a;
    } else {
      d_cnt--;
      now_time += b;
    }
    if (v[i - 1].first == v[i].first) continue;
    if (now_time > T) break;
    ll rest_time = (v[i].first - 1) - now_time;
    if (rest_time < 0) continue;
    ll tmp = min(e_cnt, rest_time / a);
    rest_time -= a * tmp;
    tmp += min(d_cnt, rest_time / b);
    tmp += i;
    chmax(ans, tmp);
  }
  if (v[n - 1].second == 0)
    now_time += a;
  else
    now_time += b;
  if (now_time <= T) ans = n;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < (int)(t); i++) solve();
}
