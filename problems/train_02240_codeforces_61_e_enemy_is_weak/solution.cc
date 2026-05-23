#include <bits/stdc++.h>
using namespace std;
const long long Mod = 7 + 1e9;
const long long INF32 = 5 + 2e9;
const long long INF64 = 5 + 1e18;
const long long MAX = 5 + 1e6;
int n, a[MAX];
pair<int, int> b[MAX];
long long T1[4 * MAX], T2[4 * MAX], TAR, VAL;
long long update(long long T[], int x = 1, int l = 0, int r = n - 1) {
  if (l > TAR || r < TAR) return T[x];
  if (l == r) return T[x] = VAL;
  int mid = l + r >> 1, c1 = x << 1, c2 = x << 1 | 1;
  return T[x] = update(T, c1, l, mid) + update(T, c2, mid + 1, r);
}
long long query(long long T[], int x = 1, int l = 0, int r = n - 1) {
  if (r < TAR) return 0;
  if (l >= TAR) return T[x];
  int mid = l + r >> 1, c1 = x << 1, c2 = x << 1 | 1;
  return query(T, c1, l, mid) + query(T, c2, mid + 1, r);
}
int main() {
  cin >> n;
  for (int i = 0, j; i < n; i++) scanf("%d", &j), b[i] = pair<int, int>(j, i);
  sort(b, b + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    TAR = b[i].second + 1;
    if (TAR < n - 1) ans += query(T2);
    VAL = query(T1);
    TAR = b[i].second;
    update(T2);
    VAL = 1;
    update(T1);
  }
  cout << ans << endl;
  return 0;
}
