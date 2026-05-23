#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[1005];
  int i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++) {
      int l = a[i], r = a[i + 1];
      if (l > r) swap(l, r);
      for (j = 0; j < n - 1; j++) {
        int l1 = a[j], r1 = a[j + 1];
        if (l1 > r1) swap(l1, r1);
        if ((r1 < r && l > l1 && l < r1) || (r < r1 && l1 > l && l1 < r) ||
            (l1 < l && r1 > l && r1 < r) || (l < l1 && r > l1 && r < r1)) {
          cout << "yes" << endl;
          return 0;
        }
      }
    }
    cout << "no" << endl;
  }
  return 0;
}
