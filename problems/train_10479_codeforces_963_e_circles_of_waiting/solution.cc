#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int R, p[4], id[122][123], N = 55, cnt;
pair<int, int> pr[105 * 105];
int A[7850][7850], ans[105 * 105];
void gaw() {
  int M = 0;
  for (int(i) = 1; (i) <= (int)(cnt); (i)++) {
    int x = pr[i].first, y = pr[i].second;
    M = max(M, id[x][y + 1]);
    for (int j = i + 1; j <= M; j++) {
      long long w = 1000000007 - (long long)A[j][i] *
                                     fastPow(A[i][i], 1000000007 - 2) %
                                     1000000007;
      for (int k = i; k <= M; k++) {
        addmod(A[j][k], w * A[i][k] % 1000000007);
      }
      addmod(A[j][cnt + 1], w * A[i][cnt + 1] % 1000000007);
    }
  }
  ans[cnt + 1] = 1;
  for (int i = cnt; i; i--) {
    int zz = A[i][cnt + 1];
    for (int j = i + 1; j <= cnt; j++) {
      addmod(zz, 1000000007 - (long long)ans[j] * A[i][j] % 1000000007);
    }
    ans[i] = (long long)zz * fastPow(A[i][i], 1000000007 - 2) % 1000000007;
  }
}
void fmain(int ID) {
  scanf("%d", &R);
  for (int(i) = 0; (i) < (int)(4); (i)++) scanf("%d", p + i);
  int S = 0;
  for (int(i) = 0; (i) < (int)(4); (i)++) S += p[i];
  S = fastPow(S, 1000000007 - 2);
  for (int(i) = 0; (i) < (int)(4); (i)++)
    p[i] = (long long)p[i] * S % 1000000007;
  swap(p[0], p[3]);
  swap(p[1], p[2]);
  for (int y = -R; y <= R; y++)
    for (int x = -R; x <= R; x++)
      if (x * x + y * y <= R * R) {
        id[x + N][y + N] = ++cnt;
        pr[cnt] = {x + N, y + N};
      }
  for (int(i) = 1; (i) <= (int)(cnt); (i)++) {
    A[i][i] = 1000000007 - 1;
    A[i][cnt + 1] = 1000000007 - 1;
    for (int(k) = 0; (k) < (int)(4); (k)++) {
      int z = id[pr[i].first + dx[k]][pr[i].second + dy[k]];
      if (z) A[i][z] = p[k];
    }
  }
  gaw();
  printf("%d\n", ans[id[N][N]]);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
