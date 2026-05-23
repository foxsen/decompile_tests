#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  long long v1[51], vb[51];
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", &v1[i]);
  for (int i = 0; i < m; i++) scanf("%lld", &vb[i]);
  vector<pair<long long, int> > r;
  vector<long long> r2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      r.push_back(pair<long long, int>(v1[i] * vb[j], i));
  sort(r.rbegin(), r.rend());
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i != r[0].second) r2.push_back(v1[i] * vb[j]);
    }
  sort(r2.rbegin(), r2.rend());
  cout << r2[0] << endl;
}
