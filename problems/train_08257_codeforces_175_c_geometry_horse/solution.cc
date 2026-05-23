#include <bits/stdc++.h>
using namespace std;
struct st {
  int x;
  int c;
};
int pr(st a, st b) { return a.c < b.c; }
st a[1005];
long long b[1005];
int i, j, k, n, m, x, y;
long long res, t, z;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].c;
  }
  sort(a, a + n, pr);
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (i = m - 1; i > 0; i--) {
    b[i] -= b[i - 1];
  }
  j = 0;
  i = 0;
  b[m] = 1000000000;
  b[m] *= b[m];
  while (i < n) {
    if (a[i].x == 0) {
      i++;
      continue;
    }
    if (b[j] == 0) {
      j++;
      continue;
    }
    t = min((long long)a[i].x, b[j]);
    res += t * (j + 1) * a[i].c;
    a[i].x -= t;
    b[j] -= t;
  }
  cout << res << endl;
  return 0;
}
