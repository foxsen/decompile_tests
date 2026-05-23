#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n], b[m], p[m];
    long long sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum = sum + a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i], p[i] = a[b[i] - 1], sum1 = sum1 + p[i];
    sort(p, p + m, greater<int>());
    long long sum2 = sum - sum1;
    for (int i = 0; i < m; i++) {
      if (sum2 > p[i])
        sum2 = sum2 + sum2;
      else
        sum2 = sum2 + p[i];
    }
    cout << sum2;
  }
}
