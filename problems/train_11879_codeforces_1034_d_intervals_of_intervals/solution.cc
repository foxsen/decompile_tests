#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;
vector<pair<int, int> > vec[300020];
int n, k, sum[300020], f[300020];
long long num, ans, csum;
inline void add(int x, int len, int id) {
  if (!len || !x) return;
  vec[x].push_back(make_pair(id, len));
  sum[x] += len;
}
void init() {
  for (int i = 1; i <= n; ++i) {
    vec[i].push_back(make_pair(i + 1, -sum[i]));
  }
}
void check(int mid) {
  num = csum = 0;
  memset(f, 0, sizeof(f));
  int l = 1, len = 0;
  long long lens = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (int)vec[i].size(); ++j) {
      if (vec[i][j].first < l)
        len += vec[i][j].second,
            lens += (long long)vec[i][j].second * (l - vec[i][j].first);
      else
        f[vec[i][j].first] += vec[i][j].second;
    }
    while (l <= i && len + f[l] >= mid) len += f[l++], lens += len;
    num += l - 1, csum += lens;
  }
  if (num > k) {
    csum -= (long long)mid * (num - k);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  s.insert(make_pair(1, 0)), s.insert(make_pair(1e9 + 10, 0));
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    int cur = -1, lst = l;
    while (1) {
      it = s.lower_bound(make_pair(l, 0));
      if (cur == -1) cur = (*it).second;
      if ((*it).first <= r) {
        add(i, (*it).first - lst, (*it).second + 1);
        lst = (*it).first;
        s.erase(it);
      } else {
        add(i, r - lst, (*it).second + 1);
        s.insert(make_pair(r, i));
        break;
      }
    }
    s.insert(make_pair(l, cur));
  }
  init();
  int l = 1, r = 1e9;
  while (l <= r) {
    int mid = (l + r) >> 1;
    check(mid);
    if (num >= k)
      l = mid + 1, ans = csum;
    else
      r = mid - 1;
  }
  cout << ans << endl;
}
