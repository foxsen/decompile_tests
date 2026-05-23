#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  long long c = 0, x = 0, y = 0, yd = 0, xd = 0, ans = 0;
  map<int, vector<int> > oc;
  vector<int> a;
  scanf("%d %d", &n, &m);
  scanf("%d", &x);
  a.push_back(x);
  for (int i = 1; i < m; ++i) {
    scanf("%d", &x);
    a.push_back(x);
    c += abs(a[i] - a[i - 1]);
    if (a[i] != a[i - 1]) {
      oc[a[i]].push_back(a[i - 1]);
      oc[a[i - 1]].push_back(a[i]);
    }
  }
  ans = c;
  map<int, vector<int> >::iterator it;
  for (it = oc.begin(); it != oc.end(); it++) {
    x = it->first;
    sort(it->second.begin(), it->second.end());
    if (it->second.size() & 1)
      y = it->second.at(it->second.size() / 2);
    else if (it->second.empty())
      y = 0;
    else
      y = it->second.at(it->second.size() / 2 - 1);
    xd = yd = 0;
    for (int j = 0; j < it->second.size(); ++j) {
      xd += abs(it->second.at(j) - x);
      yd += abs(it->second.at(j) - y);
    }
    long long tmp = (c - xd + yd);
    ans = min(ans, tmp);
  }
  printf("%I64d", ans);
}
