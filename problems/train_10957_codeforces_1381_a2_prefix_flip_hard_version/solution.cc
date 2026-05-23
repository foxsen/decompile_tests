#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[200005], b[200005];
int rs, rt, l, r;
void rd() {
  cin >> n;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
}
int gb() {
  if (rs)
    return (a[l] - '0') ^ rt;
  else
    return (a[r] - '0') ^ rt;
}
int gf() {
  if (!rs)
    return (a[l] - '0') ^ rt;
  else
    return (a[r] - '0') ^ rt;
}
int ans[200005], nn;
void wxw(int x) {
  nn++;
  ans[nn] = x;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    rd();
    l = 1;
    r = n;
    rt = rs = 0;
    nn = 0;
    for (int i = n; i >= 1; i--) {
      int t = b[i] - '0';
      if (gb() == t) {
        if (rs)
          l++;
        else
          r--;
      } else {
        int u = gf();
        if (u == t) {
          wxw(1);
        }
        wxw(i);
        if (rs)
          r--;
        else
          l++;
        rs ^= 1;
        rt ^= 1;
      }
    }
    cout << nn << " ";
    for (int i = 1; i <= nn; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
