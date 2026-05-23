#include <bits/stdc++.h>
using namespace std;
struct diem {
  int x, y;
};
int n, ans = 0;
diem a[3005];
bool cmp(diem a, diem b) {
  if (a.x == b.x) return a.y <= b.y;
  return a.x <= b.x;
}
int binary_search(int l, int r, diem value) {
  if (l > r) return 0;
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (cmp(value, a[mid]))
    return binary_search(l, mid, value);
  else
    return binary_search(mid + 1, r, value);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n - 2; i++)
    for (int j = i + 2; j <= n; j++)
      if (abs(a[j].x - a[i].x) % 2 == 0 && abs(a[j].y - a[i].y) % 2 == 0) {
        diem temp;
        temp.x = (a[j].x + a[i].x) / 2;
        temp.y = (a[j].y + a[i].y) / 2;
        int vt = binary_search(i, j, temp);
        if (a[vt].x == temp.x && a[vt].y == temp.y) ans++;
      }
  cout << ans;
}
