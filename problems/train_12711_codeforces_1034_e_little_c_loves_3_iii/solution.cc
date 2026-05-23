#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(long long& x, long long y, long long mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, long long mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
long long a[(1 << 21) + 5], b[(1 << 21) + 5], p4[30], P;
char ins[(1 << 21) + 5];
int N, cnt[(1 << 21) + 5];
inline void FWT_or(long long* A, const int fla, int lenth) {
  for (int i = 1; i < lenth; i <<= 1)
    for (int j = 0; j < lenth; j += (i << 1))
      for (int k = 0; k < i; k++) {
        if (fla == 1) {
          (A[j + k + i] += A[j + k]) %= P;
        } else {
          (A[j + k + i] += P - A[j + k]) %= P;
        }
      }
}
void fmain(int ID) {
  scanf("%d", &n);
  N = 1 << n;
  P = 1;
  p4[0] = 1;
  for (int(i) = 1; (i) <= (int)(n + 1); (i)++) {
    P *= 4;
    p4[i] = p4[i - 1] * 4;
  }
  scanf("%s", ins);
  for (int(i) = 0; (i) < (int)(N); (i)++) cnt[i] = __builtin_popcount(i);
  for (int(i) = 0; (i) < (int)(N); (i)++) {
    a[i] = (long long)(ins[i] - '0') * p4[cnt[i]] % P;
  }
  scanf("%s", ins);
  for (int(i) = 0; (i) < (int)(N); (i)++) {
    b[i] = (long long)(ins[i] - '0') * p4[cnt[i]] % P;
  }
  FWT_or(a, 1, N);
  FWT_or(b, 1, N);
  for (int(i) = 0; (i) < (int)(N); (i)++) a[i] = a[i] * b[i] % P;
  FWT_or(a, -1, N);
  for (int(i) = 0; (i) < (int)(N); (i)++) {
    printf("%d", (a[i] / p4[cnt[i]]) % 4);
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
