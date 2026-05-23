#include <bits/stdc++.h>
using namespace std;
const int imax = 1e9 + 7;
const long long lmax = 1e18;
vector<int> v1, v2, v3, v, f;
int calc() {
  int i, j, k1, k2, k3, ans = 0, start = 0, n;
  v.clear();
  cin >> k1 >> k2 >> k3;
  n = k1 + k2 + k3;
  v1.resize(k1);
  v2.resize(k2);
  v3.resize(k3);
  for (i = 0; i < ((int)v1.size()); ++i) cin >> v1[i];
  sort(v1.begin(), v1.end());
  for (i = 0; i < ((int)v1.size()); ++i) v.push_back(v1[i]);
  for (i = 0; i < ((int)v2.size()); ++i) cin >> v2[i];
  sort(v2.begin(), v2.end());
  for (i = 0; i < ((int)v2.size()); ++i) v.push_back(v2[i]);
  for (i = 0; i < ((int)v3.size()); ++i) cin >> v3[i];
  sort(v3.begin(), v3.end());
  for (i = 0; i < ((int)v3.size()); ++i) v.push_back(v3[i]);
  f.clear();
  for (i = 0; i < ((int)v.size()); ++i) {
    j = lower_bound(f.begin(), f.end(), v[i]) - f.begin();
    if (j == f.size()) f.push_back(0);
    f[j] = v[i];
  }
  return ((int)v.size()) - ((int)f.size());
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << calc() << endl;
  return 0;
}
