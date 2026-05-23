#include <bits/stdc++.h>
using namespace std;
int n, m, cntN[2][400010], cntM[2][400010];
char op[5], le[100010], ri[100010], up[100010], dn[100010];
bool revN[2][400010], revM[2][400010], revmarkN[2][400010], revmarkM[2][400010];
struct Matrix {
  int a[2][2];
  Matrix(int t = 0) { a[0][0] = a[0][1] = a[1][0] = a[1][1] = t; }
  void operator+=(int t) {
    a[0][0] += t;
    a[0][1] += t;
    a[1][0] += t;
    a[1][1] += t;
  }
  Matrix operator*(Matrix t) const {
    Matrix ans(1e9);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          ans.a[i][j] = min(ans.a[i][j], a[i][k] + t.a[k][j]);
    return ans;
  }
} sN[2][2][400010], sM[2][2][400010];
namespace Seg1 {
void pushupN(int rt) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      sN[i][j][rt] = sN[i][j][rt * 2 + 1] * sN[i][j][rt * 2];
}
void pushupM(int rt) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      sM[i][j][rt] = sM[i][j][rt * 2 + 1] * sM[i][j][rt * 2];
}
void pushdownN(int rt) {
  if (revN[0][rt]) {
    revN[0][rt * 2] ^= 1;
    revN[0][rt * 2 + 1] ^= 1;
    for (int i = 0; i < 2; i++) {
      swap(sN[0][i][rt * 2], sN[1][i][rt * 2]);
      swap(sN[0][i][rt * 2 + 1], sN[1][i][rt * 2 + 1]);
    }
    revN[0][rt] = 0;
  }
  if (revN[1][rt]) {
    revN[1][rt * 2] ^= 1;
    revN[1][rt * 2 + 1] ^= 1;
    for (int i = 0; i < 2; i++) {
      swap(sN[i][0][rt * 2], sN[i][1][rt * 2]);
      swap(sN[i][0][rt * 2 + 1], sN[i][1][rt * 2 + 1]);
    }
    revN[1][rt] = 0;
  }
}
void pushdownM(int rt) {
  if (revM[0][rt]) {
    revM[0][rt * 2] ^= 1;
    revM[0][rt * 2 + 1] ^= 1;
    for (int i = 0; i < 2; i++) {
      swap(sM[0][i][rt * 2], sM[1][i][rt * 2]);
      swap(sM[0][i][rt * 2 + 1], sM[1][i][rt * 2 + 1]);
    }
    revM[0][rt] = 0;
  }
  if (revM[1][rt]) {
    revM[1][rt * 2] ^= 1;
    revM[1][rt * 2 + 1] ^= 1;
    for (int i = 0; i < 2; i++) {
      swap(sM[i][0][rt * 2], sM[i][1][rt * 2]);
      swap(sM[i][0][rt * 2 + 1], sM[i][1][rt * 2 + 1]);
    }
    revM[1][rt] = 0;
  }
}
void buildN(int rt, int l, int r) {
  if (l > r) return;
  if (l == r) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        sN[i][j][rt].a[0][1] = sN[i][j][rt].a[1][0] = m;
        for (int k = 0; k < 2; k++) {
          sN[i][j][rt].a[k][0] += (i ^ k ? le[l] == 'B' : le[l] == 'R') +
                                  (j ^ k ? ri[l] == 'B' : ri[l] == 'R');
          sN[i][j][rt].a[k][1] += (i ^ k ? le[l] == 'B' : le[l] == 'R') +
                                  (j ^ k ? ri[l] == 'B' : ri[l] == 'R');
        }
      }
    return;
  }
  int mid = (l + r) / 2;
  buildN(rt * 2, l, mid);
  buildN(rt * 2 + 1, mid + 1, r);
  pushupN(rt);
}
void buildM(int rt, int l, int r) {
  if (l > r) return;
  if (l == r) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        sM[i][j][rt].a[0][1] = sM[i][j][rt].a[1][0] = n;
        for (int k = 0; k < 2; k++) {
          sM[i][j][rt].a[k][0] += (i ^ k ? up[l] == 'B' : up[l] == 'R') +
                                  (j ^ k ? dn[l] == 'B' : dn[l] == 'R');
          sM[i][j][rt].a[k][1] += (i ^ k ? up[l] == 'B' : up[l] == 'R') +
                                  (j ^ k ? dn[l] == 'B' : dn[l] == 'R');
        }
      }
    return;
  }
  int mid = (l + r) / 2;
  buildM(rt * 2, l, mid);
  buildM(rt * 2 + 1, mid + 1, r);
  pushupM(rt);
}
void updateN(int rt, int l, int r, int x, int y, int z) {
  if (l > r || l > y || r < x) return;
  if (l >= x && r <= y) {
    revN[z][rt] ^= 1;
    for (int i = 0; i < 2; i++)
      if (z)
        swap(sN[i][0][rt], sN[i][1][rt]);
      else
        swap(sN[0][i][rt], sN[1][i][rt]);
    return;
  }
  pushdownN(rt);
  int mid = (l + r) / 2;
  updateN(rt * 2, l, mid, x, y, z);
  updateN(rt * 2 + 1, mid + 1, r, x, y, z);
  pushupN(rt);
}
void updateM(int rt, int l, int r, int x, int y, int z) {
  if (l > r || l > y || r < x) return;
  if (l >= x && r <= y) {
    revM[z][rt] ^= 1;
    for (int i = 0; i < 2; i++)
      if (z)
        swap(sM[i][0][rt], sM[i][1][rt]);
      else
        swap(sM[0][i][rt], sM[1][i][rt]);
    return;
  }
  pushdownM(rt);
  int mid = (l + r) / 2;
  updateM(rt * 2, l, mid, x, y, z);
  updateM(rt * 2 + 1, mid + 1, r, x, y, z);
  pushupM(rt);
}
}  // namespace Seg1
namespace Seg2 {
void pushupN(int rt) {
  cntN[0][rt] = cntN[0][rt * 2] + cntN[0][rt * 2 + 1];
  cntN[1][rt] = cntN[1][rt * 2] + cntN[1][rt * 2 + 1];
}
void pushupM(int rt) {
  cntM[0][rt] = cntM[0][rt * 2] + cntM[0][rt * 2 + 1];
  cntM[1][rt] = cntM[1][rt * 2] + cntM[1][rt * 2 + 1];
}
void pushdownN(int rt, int l, int r) {
  int mid = (l + r) / 2;
  if (revmarkN[0][rt]) {
    revmarkN[0][rt * 2] ^= 1;
    revmarkN[0][rt * 2 + 1] ^= 1;
    cntN[0][rt * 2] = mid - l + 1 - cntN[0][rt * 2];
    cntN[0][rt * 2 + 1] = r - mid - cntN[0][rt * 2 + 1];
    revmarkN[0][rt] = 0;
  }
  if (revmarkN[1][rt]) {
    revmarkN[1][rt * 2] ^= 1;
    revmarkN[1][rt * 2 + 1] ^= 1;
    cntN[1][rt * 2] = mid - l + 1 - cntN[1][rt * 2];
    cntN[1][rt * 2 + 1] = r - mid - cntN[1][rt * 2 + 1];
    revmarkN[1][rt] = 0;
  }
}
void pushdownM(int rt, int l, int r) {
  int mid = (l + r) / 2;
  if (revmarkM[0][rt]) {
    revmarkM[0][rt * 2] ^= 1;
    revmarkM[0][rt * 2 + 1] ^= 1;
    cntM[0][rt * 2] = mid - l + 1 - cntM[0][rt * 2];
    cntM[0][rt * 2 + 1] = r - mid - cntM[0][rt * 2 + 1];
    revmarkM[0][rt] = 0;
  }
  if (revmarkM[1][rt]) {
    revmarkM[1][rt * 2] ^= 1;
    revmarkM[1][rt * 2 + 1] ^= 1;
    cntM[1][rt * 2] = mid - l + 1 - cntM[1][rt * 2];
    cntM[1][rt * 2 + 1] = r - mid - cntM[1][rt * 2 + 1];
    revmarkM[1][rt] = 0;
  }
}
void buildN(int rt, int l, int r) {
  if (l == r)
    return cntN[0][rt] = (le[l] == 'B'), cntN[1][rt] = (ri[l] == 'B'), void();
  int mid = (l + r) / 2;
  buildN(rt * 2, l, mid);
  buildN(rt * 2 + 1, mid + 1, r);
  pushupN(rt);
}
void buildM(int rt, int l, int r) {
  if (l == r)
    return cntM[0][rt] = (up[l] == 'B'), cntM[1][rt] = (dn[l] == 'B'), void();
  int mid = (l + r) / 2;
  buildM(rt * 2, l, mid);
  buildM(rt * 2 + 1, mid + 1, r);
  pushupM(rt);
}
void updateN(int rt, int l, int r, int x, int y, int z) {
  if (l > y || r < x) return;
  if (l >= x && r <= y)
    return revmarkN[z][rt] ^= 1, cntN[z][rt] = r - l + 1 - cntN[z][rt], void();
  pushdownN(rt, l, r);
  int mid = (l + r) / 2;
  updateN(rt * 2, l, mid, x, y, z);
  updateN(rt * 2 + 1, mid + 1, r, x, y, z);
  pushupN(rt);
}
void updateM(int rt, int l, int r, int x, int y, int z) {
  if (l > y || r < x) return;
  if (l >= x && r <= y)
    return revmarkM[z][rt] ^= 1, cntM[z][rt] = r - l + 1 - cntM[z][rt], void();
  pushdownM(rt, l, r);
  int mid = (l + r) / 2;
  updateM(rt * 2, l, mid, x, y, z);
  updateM(rt * 2 + 1, mid + 1, r, x, y, z);
  pushupM(rt);
}
int queryN(int rt, int l, int r, int x, int y) {
  if (l == r) return cntN[y][rt];
  pushdownN(rt, l, r);
  int mid = (l + r) / 2;
  if (x <= mid)
    return queryN(rt * 2, l, mid, x, y);
  else
    return queryN(rt * 2 + 1, mid + 1, r, x, y);
}
int queryM(int rt, int l, int r, int x, int y) {
  if (l == r) return cntM[y][rt];
  pushdownM(rt, l, r);
  int mid = (l + r) / 2;
  if (x <= mid)
    return queryM(rt * 2, l, mid, x, y);
  else
    return queryM(rt * 2 + 1, mid + 1, r, x, y);
}
}  // namespace Seg2
int solve() {
  int l1 = Seg2::queryN(1, 1, n, 1, 0), r1 = Seg2::queryN(1, 1, n, 1, 1),
      u1 = Seg2::queryM(1, 1, m, 1, 0), d1 = Seg2::queryM(1, 1, m, 1, 1),
      f0 = m - cntM[0][1] + !l1 + !r1, f1 = cntM[0][1] + l1 + r1,
      g0 = n - cntN[0][1] + !u1 + !d1, g1 = cntN[0][1] + u1 + d1, ans = 1e9;
  Matrix sn = sN[0][0][1], sm = sM[0][0][1];
  if (n == 1)
    ans = min(ans, min(f0 + m - cntM[1][1], f1 + cntM[1][1]));
  else {
    int tf0 = min(f0 + sn.a[0][0], f1 + sn.a[0][1]),
        tf1 = min(f0 + sn.a[1][0], f1 + sn.a[1][1]);
    ans = min(ans, min(tf0 + m - cntM[1][1], tf1 + cntM[1][1]));
  }
  if (m == 1)
    ans = min(ans, min(g0 + n - cntN[1][1], g1 + cntN[1][1]));
  else {
    int tg0 = min(g0 + sm.a[0][0], g1 + sm.a[0][1]),
        tg1 = min(g0 + sm.a[1][0], g1 + sm.a[1][1]);
    ans = min(ans, min(tg0 + n - cntN[1][1], tg1 + cntN[1][1]));
  }
  return ans;
}
int main() {
  int q, x, y;
  scanf("%d%d%d%s%s%s%s", &n, &m, &q, le + 1, ri + 1, up + 1, dn + 1);
  Seg1::buildN(1, 2, n);
  Seg1::buildM(1, 2, m);
  Seg2::buildN(1, 1, n);
  Seg2::buildM(1, 1, m);
  cout << solve() << endl;
  while (q--) {
    scanf("%s%d%d", op, &x, &y);
    if (op[0] == 'L')
      Seg1::updateN(1, 2, n, x, y, 0), Seg2::updateN(1, 1, n, x, y, 0);
    else if (op[0] == 'R')
      Seg1::updateN(1, 2, n, x, y, 1), Seg2::updateN(1, 1, n, x, y, 1);
    else if (op[0] == 'U')
      Seg1::updateM(1, 2, m, x, y, 0), Seg2::updateM(1, 1, m, x, y, 0);
    else
      Seg1::updateM(1, 2, m, x, y, 1), Seg2::updateM(1, 1, m, x, y, 1);
    printf("%d\n", solve());
  }
  return 0;
}
