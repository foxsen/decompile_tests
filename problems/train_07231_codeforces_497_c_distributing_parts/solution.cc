#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MINF = 0x80000000;
const long long mod = 1000000007;
const int cons = 100001;
int k[cons];
int ans[cons];
int high[cons];
int parth[cons];
set<pair<pair<int, int>, pair<int, int> > > dat;
set<pair<int, int> > parts;
set<pair<int, int> > tmp;
int main() {
  int n;
  int m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    dat.insert(make_pair(make_pair(x, 1), make_pair(2, i)));
    dat.insert(make_pair(make_pair(y, 2), make_pair(2, i)));
    parth[i] = y;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int low, info;
    scanf("%d%d%d", &low, &high[i], &k[i]);
    dat.insert(make_pair(make_pair(low, 1), make_pair(1, i)));
    dat.insert(make_pair(make_pair(high[i], 2), make_pair(1, i)));
  }
  set<pair<int, int> > dat2;
  for (auto it1 : dat) {
    int t = it1.second.first;
    if (t == 1) {
      if (it1.first.second == 1) {
        dat2.insert(make_pair(high[it1.second.second], it1.second.second));
      } else {
      }
    } else {
      if (it1.first.second == 1) {
        if (dat2.size() == 0) {
          puts("NO");
          return 0;
        }
        auto it = dat2.lower_bound(make_pair(parth[it1.second.second], 0));
        if (it == dat2.end()) {
          puts("NO");
          return 0;
        }
        k[it->second]--;
        ans[it1.second.second] = it->second;
        if (k[it->second] == 0)
          dat2.erase(make_pair(high[it->second], it->second));
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
