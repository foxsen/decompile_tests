#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long a[N];
int n, cnt[N][N], ans[N], p[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    long long f = 1;
    if (a[i] < 0) f = -1, a[i] = -a[i];
    for (int j = 2; j * j <= a[i]; j++)
      while (a[i] % (j * j) == 0) a[i] /= j * j;
    a[i] *= f;
    if (a[i] == 0) {
      p[i] = i;
      cnt[i][i] = 0;
    } else {
      for (int j = i - 1; j; j--)
        if (a[i] == a[j]) {
          p[i] = j;
          break;
        }
      cnt[i][i] = 1;
    }
  }
  ans[1] = n;
  for (int l = 2; l <= n; l++)
    for (int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      cnt[i][j] = cnt[i][j - 1];
      if (p[j] < i) cnt[i][j]++;
      ans[max(1, cnt[i][j])]++;
    }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
