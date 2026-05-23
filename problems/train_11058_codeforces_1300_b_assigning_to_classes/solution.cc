#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + 2 * n);
    printf("%d\n", a[n + 1] - a[n]);
  }
  return 0;
}
