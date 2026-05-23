#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    int t, n, i, j, k = 0, x, y, c = 1, s = 1, mn, ma, ms, idx = 0;
    scanf("%d", &n);
    map<int, int> m;
    map<int, int>::iterator it;
    vector<pair<int, int> > v;
    for (i = 0; i < n; i++) {
      scanf("%d", &x);
      m[x]++;
    }
    for (it = m.begin(); it != m.end(); it++)
      v.push_back(make_pair(-(*it).second, (*it).first));
    sort(v.begin(), v.end());
    scanf("%d", &mn);
    int aud[mn], sub[mn];
    for (i = 0; i < mn; i++) scanf("%d", &aud[i]);
    for (i = 0; i < mn; i++) scanf("%d", &sub[i]);
    ma = INT_MAX;
    ms = -v[0].first;
    vector<int> id;
    for (i = 0; i < v.size(); i++) {
      if (id.size()) break;
      if (ma > -v[i].first)
        ma = -v[i].first;
      else
        continue;
      for (j = 0; j < mn; j++)
        if (m[aud[j]] == ma) {
          id.push_back(j);
        }
    }
    if (id.size()) {
      idx = id[0];
      for (j = 1; j < id.size(); j++)
        if (m[sub[id[j]]] > m[sub[idx]]) idx = id[j];
    } else {
      idx = 0;
      for (j = 1; j < mn; j++)
        if (m[sub[j]] > m[sub[idx]]) idx = j;
    }
    printf("%d\n", idx + 1);
  }
  return 0;
}
