#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MOD = 1000000007;
const int INF = 0x7fffffff;
const double eps = 1e-10;
const int N = 200005;
set<pair<int, int> > com;
pair<int, int> soc[N];
int id[N], match[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    com.insert(make_pair(a, i));
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &soc[i].first);
    soc[i].second = i;
  }
  sort(soc + 1, soc + m + 1);
  int c = 0, u = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= 30; j++) {
      auto it = com.lower_bound(make_pair(soc[i].first, 0));
      if (it != com.end() && it->first == soc[i].first) {
        u += j;
        c++;
        id[soc[i].second] = j;
        match[it->second] = soc[i].second;
        com.erase(it);
        break;
      }
      soc[i].first = (soc[i].first + 1) / 2;
    }
  }
  printf("%d %d\n", c, u);
  for (int i = 1; i <= m; i++) printf("%d ", id[i]);
  cout << endl;
  for (int i = 1; i <= n; i++) printf("%d ", match[i]);
}
