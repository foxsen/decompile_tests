#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > noo, n, y;
int main() {
  ios_base::sync_with_stdio(false);
  int h, q, yon;
  cin >> h >> q;
  int level;
  long long L, R;
  while (q--) {
    cin >> level >> L >> R >> yon;
    for (int i = level + 1; i <= h; i++) {
      L *= 2;
      R = R * 2 + 1;
    }
    if (yon)
      y.push_back(make_pair(L, R));
    else
      n.push_back(make_pair(L, R));
  }
  long long mr = 1, ml = 1;
  for (int i = 2; i <= h; i++) {
    ml *= 2ll;
    mr = mr * 2ll + 1ll;
  }
  long long nnr = mr, nnl = ml;
  for (int i = 0; i < y.size(); i++) {
    if (y[i].first > nnr || y[i].second < nnl) {
      cout << "Game cheated!";
      return 0;
    }
    nnr = min(nnr, y[i].second);
    nnl = max(nnl, y[i].first);
  }
  sort(n.begin(), n.end());
  long long cur = ml - 1;
  for (int i = 0; i < n.size(); i++) {
    if (n[i].second <= cur) continue;
    if (n[i].first >= cur + 2)
      noo.push_back(make_pair(cur + 1, n[i].first - 1));
    cur = max(cur, n[i].second);
  }
  if (cur < mr) noo.push_back(make_pair(cur + 1, mr));
  long long sum = 0, ans;
  for (int i = 0; i < noo.size(); i++) {
    if (noo[i].first > nnr || noo[i].second < nnl) continue;
    long long aa = max(nnl, noo[i].first);
    long long bb = min(nnr, noo[i].second);
    sum += bb - aa + 1;
    ans = aa;
  }
  if (sum == 0) {
    cout << "Game cheated!";
    return 0;
  }
  if (sum == 1) {
    cout << ans;
    return 0;
  }
  cout << "Data not sufficient!";
  return 0;
}
