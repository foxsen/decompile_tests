#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int i, n, k, m, v, t, mx = 0;
  long long s = 0, x, cnt = 0, y;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
    mx = max(mx, a[i]);
  }
  x = s - n;
  sort(a, a + n);
  int pos = 0;
  for (i = 0; i < n; i++) {
    cnt++;
    if (a[i] > pos) pos++;
  }
  cnt += (mx - pos);
  cout << s - cnt;
}
