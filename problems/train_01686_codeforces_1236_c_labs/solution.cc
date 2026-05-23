#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e2 + 7;
int main() {
  int n;
  int mp[MAXN][MAXN], cnt = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1)
      for (int j = 1; j <= n; j++) mp[j][i] = cnt++;
    else
      for (int j = n; j >= 1; j--) mp[j][i] = cnt++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", mp[i][j]);
    }
    printf("\n");
  }
}
