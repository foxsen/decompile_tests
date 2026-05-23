#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 5;
const long long inf = 0x3f3f3f3f;
int a[2][maxn], num[maxn * 2];
int n, c;
void update(int l, int r) {
  num[l]++;
  num[r + 1]--;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int i, j, l, r, ans, tmpl, tmpr, tmp, tag = 1, t = 0;
  cin >> n >> c;
  cin >> a[1 % 2][0];
  for (j = 1; j <= a[1 % 2][0]; j++) {
    cin >> a[1 % 2][j];
  }
  for (i = 2; i <= n; i++) {
    cin >> a[i % 2][0];
    for (j = 1; j <= a[i % 2][0]; j++) {
      cin >> a[i % 2][j];
    }
    if (tag) {
      for (j = 1; j <= min(a[i % 2][0], a[(i - 1) % 2][0]); j++) {
        if (a[i % 2][j] > a[(i - 1) % 2][j]) {
          t++;
          update(0, c - a[i % 2][j]);
          update(c - a[(i - 1) % 2][j] + 1, c - 1);
          break;
        }
        if (a[i % 2][j] < a[(i - 1) % 2][j]) {
          tmpl = c - a[(i - 1) % 2][j] + 1;
          tmpr = c - a[i % 2][j];
          t++;
          update(tmpl, tmpr);
          break;
        }
      }
      if (j > min(a[i % 2][0], a[(i - 1) % 2][0])) {
        if (a[i % 2][0] < a[(i - 1) % 2][0]) {
          tag = 0;
        }
      }
    }
  }
  for (i = 1; i <= c - 1; i++) {
    num[i] += num[i - 1];
  }
  ans = -1;
  if (tag) {
    for (i = 0; i <= c - 1; i++) {
      if (t == num[i]) {
        ans = i;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
