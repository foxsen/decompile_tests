#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, s, k;
    scanf("%d%d%d", &n, &s, &k);
    map<int, int> a;
    for (int i = 1; i <= k; i++) {
      int tep;
      scanf("%d", &tep);
      a[tep] = 1;
    }
    int ans = 0;
    if (a[s] == 0)
      printf("0\n");
    else {
      int num = 1;
      while (1) {
        if (s - num >= 1) {
          if (a[s - num] == 0) {
            printf("%d\n", num);
            break;
          }
        }
        if (s + num <= n) {
          if (a[s + num] == 0) {
            printf("%d\n", num);
            break;
          }
        }
        num++;
      }
    }
  }
}
