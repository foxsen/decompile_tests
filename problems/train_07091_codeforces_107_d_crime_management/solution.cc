#include <bits/stdc++.h>
using namespace std;
const int mod = 12345;
char A;
long long n;
vector<int> ok[30];
int pcnt = 0, m, ans = 0, maxn[30], x, c;
struct Matrix {
  int a[125][125];
  Matrix() { memset(a, 0, sizeof(a)); };
  Matrix operator*(const Matrix &x) const {
    Matrix ans = Matrix();
    for (int i = 1; i <= 123; i++)
      for (int j = 1; j <= 123; j++)
        for (int k = 1; k <= 123; k++)
          ans.a[i][j] += a[i][k] * x.a[k][j] % mod, ans.a[i][j] %= mod;
    return ans;
  }
  Matrix operator^(const long long &x) const {
    Matrix ans = (*this), tmp = (*this);
    long long now = x;
    while (now) {
      if (now & 1) ans = ans * tmp;
      tmp = tmp * tmp, now >>= 1;
    }
    return ans;
  }
} mat;
struct dat {
  int val[30];
  bool operator<(const dat &a) const {
    for (int i = 1; i <= 26; i++) {
      if (val[i] == a.val[i]) continue;
      return val[i] < a.val[i];
    }
    return 0;
  }
} crl;
map<dat, int> mp;
void dfs(int pos, dat now) {
  if (pos == 27) {
    mp[now] = ++pcnt;
    return;
  }
  if (maxn[pos] == 0) dfs(pos + 1, now);
  for (int i = 0; i < maxn[pos]; i++) now.val[pos] = i, dfs(pos + 1, now);
}
void calc(int pos, dat now) {
  if (pos == 27) {
    (ans += mat.a[1][mp[now]]) %= mod;
    return;
  }
  if (maxn[pos] == 0) calc(pos + 1, now);
  for (int i = 0; i < maxn[pos]; i++) {
    bool flg = 0;
    for (unsigned int j = 0; j < ok[pos].size() && !flg; j++)
      if (i % ok[pos][j] == 0) flg = 1;
    if (flg) now.val[pos] = i, calc(pos + 1, now);
  }
}
int main() {
  scanf("%lld%d", &n, &m);
  if (n == 0) return puts("1") * 0;
  if (m == 0) return puts("0") * 0;
  for (int i = 1; i <= m; i++) {
    scanf(" %c %d", &A, &x), c = A - 'A' + 1;
    if (maxn[c] == 0)
      maxn[c] = x;
    else
      maxn[c] *= x;
    ok[c].push_back(x);
  }
  dfs(1, crl);
  for (map<dat, int>::iterator i = mp.begin(); i != mp.end(); i++) {
    int s = i->second;
    dat now = i->first;
    for (int j = 1; j <= 26; j++) {
      if (maxn[j] == 0) continue;
      dat tmp = now;
      tmp.val[j] = (tmp.val[j] + 1) % maxn[j], mat.a[s][mp[tmp]]++;
    }
  }
  mat = mat ^ (1ll * n - 1), calc(1, crl), printf("%d\n", ans);
}
