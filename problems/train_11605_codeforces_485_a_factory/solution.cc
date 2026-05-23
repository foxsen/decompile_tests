#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, m;
  cin >> a >> m;
  for (int i = 0; i <= m; i++) {
    a += (a % m);
    a %= m;
    if (a == 0) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}
