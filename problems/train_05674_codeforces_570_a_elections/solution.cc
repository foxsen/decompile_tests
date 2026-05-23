#include <bits/stdc++.h>
using namespace std;
int res[111];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    pair<int, int> add;
    add.first = -1;
    for (int i = 0; i < n; i++) {
      int kol;
      scanf("%d", &kol);
      if (kol > add.first) {
        add.first = kol;
        add.second = i + 1;
      }
    }
    res[add.second]++;
  }
  pair<int, int> ans;
  ans.first = -1;
  for (int i = 1; i <= n; i++) {
    if (res[i] > ans.first) {
      ans.first = res[i];
      ans.second = i;
    }
  }
  printf("%d", ans.second);
}
