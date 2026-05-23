#include <bits/stdc++.h>
using namespace std;
const int MAX = 1E6 + 10;
const int MAXP = 3E6;
int n, m;
int a[MAX];
long long c[MAX];
long long f[3 * MAX], f_less[3 * MAX];
long long all;
int main() {
  scanf("%d", &n);
  all = (long long)n * (n - 1);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != a[j]) {
      j++;
      a[j] = a[i];
    }
    c[j]++;
  }
  n = j + 1;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      if (MAXP / a[i] < a[j]) break;
      if (i == j)
        f[a[i] * a[i]] += c[i] * (c[i] - 1);
      else
        f[a[i] * a[j]] += 2 * c[i] * c[j];
    }
  for (int i = 1; i <= MAXP; i++) f_less[i] = f_less[i - 1] + f[i - 1];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int p;
    scanf("%d", &p);
    printf("%I64d\n", all - f_less[p]);
  }
}
