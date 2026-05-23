#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long MOD = 1e9 + 9;
long long sum[N << 2], lazy1[N << 2], lazy2[N << 2], F[N];
inline void read(long long &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x = x * f;
}
struct Matrix {
  long long v[10][10];
  int lena, lenb;
  void init1(int a, int b) {
    v[0][0] = 1;
    v[0][1] = 1;
    v[1][0] = 1;
    v[1][1] = 0;
    lena = a, lenb = b;
  }
  void init2(int a, int b) {
    v[0][0] = 1;
    v[0][1] = 0;
    v[1][0] = 0;
    v[1][1] = 1;
    lena = a, lenb = b;
  }
  void init3(long long f1, long long f2, int a, int b) {
    v[0][0] = f2;
    v[0][1] = 0;
    v[1][0] = f1;
    v[1][1] = 0;
    lena = a, lenb = b;
  }
};
Matrix Mul(Matrix a, Matrix b) {
  Matrix ans;
  ans.lena = a.lena, ans.lenb = b.lenb;
  for (int i = 0; i < a.lena; i++) {
    for (int j = 0; j < b.lenb; j++) {
      ans.v[i][j] = 0;
      for (int k = 0; k < a.lenb; k++)
        ans.v[i][j] = (ans.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
    }
  }
  return ans;
}
void print(Matrix a) {
  for (int i = 0; i < a.lena; i++) {
    for (int j = 0; j < a.lenb; j++) {
      cout << a.v[i][j] << ' ';
    }
    cout << endl;
  }
}
pair<long long, long long> get_f(long long f1, long long f2, int n) {
  pair<long long, long long> ans =
      pair<long long, long long>(f2, (f1 + f2) % MOD);
  if (n < 3) return ans;
  ans = pair<long long, long long>((f1 * F[n - 2] + f2 * F[n - 1]) % MOD,
                                   (f1 * F[n - 1] + f2 * F[n]) % MOD);
  return ans;
}
void modify(int rt, int l, int r, long long f1, long long f2) {
  lazy1[rt] = (lazy1[rt] + f1) % MOD;
  lazy2[rt] = (lazy2[rt] + f2) % MOD;
  sum[rt] = (sum[rt] + (get_f(f1, f2, r - l + 2).second - f2) + MOD) % MOD;
}
void pushDown(int rt, int l, int mid, int r) {
  if (lazy1[rt] && lazy2[rt]) {
    modify(rt << 1, l, mid, lazy1[rt], lazy2[rt]);
    pair<long long, long long> P = get_f(lazy1[rt], lazy2[rt], mid - l + 2);
    modify(rt << 1 | 1, mid + 1, r, P.first, P.second);
    lazy1[rt] = lazy2[rt] = 0;
  }
}
void Build(int rt, int l, int r) {
  lazy1[rt] = lazy2[rt] = sum[rt] = 0;
  if (l == r) {
    read(sum[rt]);
    return;
  }
  int mid = (l + r) >> 1;
  Build(rt << 1, l, mid);
  Build(rt << 1 | 1, mid + 1, r);
  sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % MOD;
}
void Update(int rt, int l, int r, int x, int y, long long f1, long long f2) {
  if (l == x && r == y) {
    modify(rt, l, r, f1, f2);
    return;
  }
  int mid = (l + r) >> 1;
  pushDown(rt, l, mid, r);
  if (y <= mid)
    Update(rt << 1, l, mid, x, y, f1, f2);
  else if (x > mid)
    Update(rt << 1 | 1, mid + 1, r, x, y, f1, f2);
  else {
    pair<long long, long long> P = get_f(f1, f2, mid - x + 2);
    Update(rt << 1, l, mid, x, mid, f1, f2),
        Update(rt << 1 | 1, mid + 1, r, mid + 1, y, P.first, P.second);
  }
  sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % MOD;
}
long long Query(int rt, int l, int r, int x, int y) {
  if (l == x && r == y) {
    return sum[rt];
  }
  int mid = (l + r) >> 1;
  pushDown(rt, l, mid, r);
  if (y <= mid)
    return Query(rt << 1, l, mid, x, y);
  else if (x > mid)
    return Query(rt << 1 | 1, mid + 1, r, x, y);
  else
    return (Query(rt << 1, l, mid, x, mid) +
            Query(rt << 1 | 1, mid + 1, r, mid + 1, y)) %
           MOD;
}
int main() {
  F[0] = 0, F[1] = 1;
  for (int i = 2; i < N; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;
  long long n, m, opt, l, r;
  read(n);
  read(m);
  Build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    read(opt);
    read(l);
    read(r);
    if (opt == 1)
      Update(1, 1, n, l, r, 1, 1);
    else
      printf("%I64d\n", Query(1, 1, n, l, r));
  }
  return 0;
}
