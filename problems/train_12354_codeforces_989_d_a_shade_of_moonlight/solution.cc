#include <bits/stdc++.h>
using namespace std;
long long n, l, w, res;
vector<pair<long long, int> > v;
vector<long long> x, wx, wwx;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> l >> w;
  v.resize(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i].second == 1) {
      x.push_back(v[i].first);
      wx.push_back(v[i].first * (w - 1));
      wwx.push_back(v[i].first * (w + 1));
      continue;
    }
    long long b = v[i].first + l;
    if (b <= 0) {
      if (w > 1) {
        res += (long long)(upper_bound(wx.begin(), wx.end(), (w + 1) * b - 1) -
                           wx.begin());
      }
    } else {
      if (w == 1) {
        res += (long long)(upper_bound(x.begin(), x.end(), -1) - x.begin());
      } else {
        res +=
            (long long)(upper_bound(wwx.begin(), wwx.end(), (w - 1) * b - 1) -
                        wwx.begin());
      }
    }
  }
  cout << res << endl;
  return 0;
}
