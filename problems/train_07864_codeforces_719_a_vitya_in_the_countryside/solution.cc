#include <bits/stdc++.h>
using namespace std;
static int n;
static vector<int> ve;
int main() {
  while (scanf("%d", &n) != EOF) {
    ve.clear();
    ve.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &ve[i]);
    if (n == 1 && ve[n - 1] != 15 && ve[n - 1] != 0) {
      printf("-1\n");
    } else {
      if (ve[n - 1] == 15) {
        printf("DOWN\n");
      } else if (ve[n - 1] == 0) {
        printf("UP\n");
      } else if (ve[n - 1] == 1) {
        if (ve[n - 2] == 2)
          printf("DOWN\n");
        else if (ve[n - 2] == 0)
          printf("UP\n");
      } else {
        if (ve[n - 1] > ve[n - 2])
          printf("UP\n");
        else
          printf("DOWN\n");
      }
    }
  }
  return 0;
}
