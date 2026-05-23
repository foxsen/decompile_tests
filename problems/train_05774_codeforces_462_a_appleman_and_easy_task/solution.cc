#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
char p[102][102];
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) p[i][j] = getchar();
    getchar();
  }
  bool foo = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cnt = 0;
      if (p[i - 1][j] == 'o') ++cnt;
      if (p[i][j - 1] == 'o') ++cnt;
      if (p[i][j + 1] == 'o') ++cnt;
      if (p[i + 1][j] == 'o') ++cnt;
      if (cnt % 2) {
        foo = false;
        break;
      }
    }
  }
  if (foo)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
