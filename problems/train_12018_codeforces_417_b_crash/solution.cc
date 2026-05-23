#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
using namespace std;
int a[100100];
int main() {
  int n, x, k;
  cin >> n;
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%d %d", &x, &k);
    if (a[k] < x) {
      printf("NO");
      return 0;
    }
    if (a[k] == x) {
      ++a[k];
    }
  }
  printf("YES");
  return 0;
}
