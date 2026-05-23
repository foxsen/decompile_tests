#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
set<vector<int>> cnt;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int dn = 0, dm = 0, cn = n, cm = m;
  --cn, --cm;
  while (cn) cn /= 7, ++dn;
  dn = max(1, dn);
  while (cm) cm /= 7, ++dm;
  dm = max(1, dm);
  if (dn + dm > 7) return cout << 0, 0;
  int i, j, ans = 0;
  vector<int> v;
  for (i = 0; i < 7; ++i) v.push_back(i);
  do {
    cn = 0, cm = 0;
    vector<int> temp;
    for (i = 0; i < dn + dm; ++i) temp.push_back(v[i]);
    for (i = dn + dm - 1, j = 1; i >= dn; --i, j *= 7) cm += j * temp[i];
    for (j = 1; i >= 0; --i, j *= 7) cn += j * temp[i];
    if (cn < n and cm < m) cnt.insert(temp);
  } while (next_permutation(v.begin(), v.end()));
  cout << cnt.size();
  return 0;
}
