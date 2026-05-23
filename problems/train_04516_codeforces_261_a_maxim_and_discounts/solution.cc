#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, m, a[100000], b[100000], min1, sum;
  while (scanf("%d", &n) != EOF) {
    min1 = 10000000, sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < min1) min1 = a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(b, b + m, cmp);
    for (int i = 0; i < m; i++) {
      if (i % (2 + min1) < min1) sum += b[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
