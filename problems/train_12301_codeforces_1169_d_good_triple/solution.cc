#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int N = 3 * 1e5 + 10;
ll res;
ll a[N], wow[N];
vector<ll> v[2];
vector<pair<ll, ll> > vv;
void solve() {
  string s;
  cin >> s;
  ll n = s.size();
  for (int i = 0; i < s.size(); ++i) {
    v[(s[i] == '1')].push_back(i);
  }
  for (int i = 0; i < v[0].size(); ++i) {
    ll l = i - 1, r = i + 1;
    while (l >= 0 && r < v[0].size()) {
      if ((v[0][i] - v[0][l]) == (v[0][r] - v[0][i])) {
        vv.push_back({v[0][l], v[0][r]});
        break;
      }
      if ((v[0][i] - v[0][l]) < (v[0][r] - v[0][i]))
        --l;
      else
        ++r;
    }
  }
  for (int i = 0; i < v[1].size(); ++i) {
    ll l = i - 1, r = i + 1;
    while (l >= 0 && r < v[1].size()) {
      if ((v[1][i] - v[1][l]) == (v[1][r] - v[1][i])) {
        vv.push_back({v[1][l], v[1][r]});
        break;
      }
      if ((v[1][i] - v[1][l]) < (v[1][r] - v[1][i]))
        --l;
      else
        ++r;
    }
  }
  sort(vv.begin(), vv.end());
  wow[vv.size()] = inf;
  for (int i = vv.size() - 1; i >= 0; --i) {
    wow[i] = min(wow[i + 1], vv[i].second);
  }
  ll st = 0, prev = -1, rt = n;
  for (int i = 0; i < vv.size(); ++i) {
    res += (vv[i].first - st + 1) * (rt - wow[i]);
    prev = vv[i].first;
    st = vv[i].first + 1;
  }
  cout << res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solve();
  }
}
