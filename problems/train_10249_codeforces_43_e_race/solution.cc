#include <bits/stdc++.h>
using namespace std;
int n, s, k[101], ct;
pair<int, int> dat[101][101];
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k[i]);
    for (int j = 0; j < k[i]; j++) {
      scanf("%d%d", &dat[i][j].first, &dat[i][j].second);
    }
    for (int j = 0; j < i; j++) {
      int st1 = 0, st2 = 0, r1 = 0, r2 = 0, pl, t1 = 0, t2 = 0, tn = 0, dt;
      pl = (dat[i][0].first > dat[j][0].first ? i : j);
      while (st1 < s && st2 < s) {
        dt = (t1 + dat[j][r1].second < t2 + dat[i][r2].second
                  ? t1 + dat[j][r1].second
                  : t2 + dat[i][r2].second) -
             tn;
        tn += dt;
        st1 += dt * dat[j][r1].first;
        st2 += dt * dat[i][r2].first;
        if (st1 != st2 && max(st1, st2) <= s &&
            ((pl == i && st1 > st2) || (pl == j && st2 > st1))) {
          ct++;
          pl = (pl == i ? j : i);
        }
        if (t1 + dat[j][r1].second > t2 + dat[i][r2].second)
          t2 += dat[i][r2++].second;
        else
          t1 += dat[j][r1++].second;
      }
    }
  }
  printf("%d\n", ct);
  return 0;
}
