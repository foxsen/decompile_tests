#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, d = 0;
  pair<int, int> h[2005];
  while (~scanf("%d", &n)) {
    int id[10002];
    for (i = 0; i < n; i++) {
      scanf("%d", &h[i].first);
      h[i].second = i + 1;
    }
    sort(h, h + n);
    int c = 0;
    for (i = 1; i <= n; ++i) {
      if (h[i].first == h[i - 1].first) id[++c] = i - 1;
    }
    if (c < 2) {
      printf("NO\n");
      continue;
    } else {
      printf("YES\n");
      for (i = 0; i < n; ++i) {
        if (i < n - 1)
          printf("%d ", h[i].second);
        else
          printf("%d\n", h[i].second);
      }
      swap(h[id[1]], h[id[1] + 1]);
      for (i = 0; i < n; ++i) {
        if (i < n - 1)
          printf("%d ", h[i].second);
        else
          printf("%d\n", h[i].second);
      }
      swap(h[id[2]], h[id[2] + 1]);
      for (i = 0; i < n; ++i) {
        if (i < n - 1)
          printf("%d ", h[i].second);
        else
          printf("%d\n", h[i].second);
      }
    }
  }
  return 0;
}
