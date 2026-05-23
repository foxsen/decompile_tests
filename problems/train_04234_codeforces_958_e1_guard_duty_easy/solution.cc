#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      int u, v;
      cin >> u >> v;
    }
    for (int j = 1; j <= m; j++) {
      int u, v;
      cin >> u >> v;
    }
    if (n == m)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
