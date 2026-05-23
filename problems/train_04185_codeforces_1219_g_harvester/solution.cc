#include <bits/stdc++.h>
using namespace std;
vector<int> ve[100005];
long long a[100005], b[10005], c[100005];
long long fun(int n) {
  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] > x) {
      y = x;
      x = c[i];
    } else if (c[i] > y)
      y = c[i];
  }
  return x + y;
}
int main() {
  int n, m;
  long long sum = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      sum += x;
      a[i] += x;
      b[j] += x;
      ve[i].push_back(x);
    }
  if (n <= 4 || m <= 4) {
    printf("%lld\n", sum);
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) c[j] = b[j] - ve[i][j];
    sort(c, c + m);
    ans = max(ans, a[i] + c[m - 1] + c[m - 2] + c[m - 3]);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) c[j] = a[j] - ve[j][i];
    sort(c, c + n);
    ans = max(ans, b[i] + c[n - 1] + c[n - 2] + c[n - 3]);
  }
  if (n < m) {
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < m; k++) c[k] = b[k] - ve[i][k] - ve[j][k];
        long long x = fun(m);
        ans = max(ans, a[i] + a[j] + x);
      }
  } else {
    for (int i = 0; i < m - 1; i++)
      for (int j = i + 1; j < m; j++) {
        for (int k = 0; k < n; k++) c[k] = a[k] - ve[k][i] - ve[k][j];
        long long x = fun(n);
        ans = max(ans, b[i] + b[j] + x);
      }
  }
  sort(a, a + n);
  ans = max(ans, a[n - 1] + a[n - 2] + a[n - 3] + a[n - 4]);
  sort(b, b + m);
  ans = max(ans, b[m - 1] + b[m - 2] + b[m - 3] + b[m - 4]);
  printf("%lld\n", ans);
}
