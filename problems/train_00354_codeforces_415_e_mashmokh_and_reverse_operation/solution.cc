#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n, m;
int a[int(1048576 + 2000)], b[int(1048576 + 2000)];
long long f[30][2];
long long res = 0;
void build(int l, int r, int h) {
  if (l == r) return;
  int mid = (l + r) / 2;
  build(l, mid, h + 1);
  build(mid + 1, r, h + 1);
  int i = l;
  int j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
      b[k] = a[i];
      i++;
      f[h][1] += j - (mid + 1);
    } else {
      b[k] = a[j];
      j++;
      f[h][0] += (i - l);
    }
    k++;
  }
  while (i <= mid) {
    b[k] = a[i];
    i++;
    k++;
    f[h][1] += r - mid;
  }
  while (j <= r) {
    b[k] = a[j];
    j++;
    k++;
    f[h][0] += (mid - l + 1);
  }
  j = mid;
  int d = 0;
  for (int i = (l), _b = (mid); i <= _b; i++) {
    if (i == l || a[i] != a[i - 1]) d = 0;
    while (j + 1 <= r && a[j + 1] <= a[i]) {
      j++;
      if (a[j] == a[i]) d++;
    }
    f[h][0] -= d;
  }
  for (int i = (l), _b = (r); i <= _b; i++) a[i] = b[i];
}
void solve(int x) {
  for (int i = (x), _b = (n); i <= _b; i++) {
    res -= f[i][1];
    swap(f[i][1], f[i][0]);
    res += f[i][1];
  }
  printf("%I64d\n", res);
}
int main() {
  scanf("%d", &n);
  m = (1 << n);
  for (int i = (1), _b = (m); i <= _b; i++) scanf("%d", &a[i]);
  build(1, m, 0);
  for (int i = (0), _b = (n); i <= _b; i++) res += f[i][1];
  int q;
  scanf("%d", &q);
  for (int i = (1), _b = (q); i <= _b; i++) {
    int x;
    scanf("%d", &x);
    solve(n - x);
  }
}
