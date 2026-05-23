#include <bits/stdc++.h>
using namespace std;
int T[5050];
set<pair<int, int> > S;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  S.insert(make_pair(0, 0));
  for (int i = (0); i <= (int(n) - 1); ++i) {
    scanf("%d", &T[i]);
    int sum = T[i];
    for (int j = (1); j <= (k); ++j) {
      S.insert(make_pair(sum, j));
      sum += T[i];
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = (0); i <= (int(q) - 1); ++i) {
    int z;
    int ans = 1000;
    scanf("%d", &z);
    for (int j = (0); j <= (int(n) - 1); ++j) {
      for (int l = (1); l <= (k); ++l) {
        int qq = T[j] * l;
        if (z - qq < 0) break;
        S.insert(make_pair(z - qq, -1));
        auto x = S.find(make_pair(z - qq, -1));
        x++;
        if (x == S.end()) continue;
        if ((*x).first != z - qq) continue;
        ans = min(ans, l + (*x).second);
        S.erase(make_pair(z - qq, -1));
      }
    }
    if (ans > k) ans = -1;
    printf("%d\n", ans);
  }
}
