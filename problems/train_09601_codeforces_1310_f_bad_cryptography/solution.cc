#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
using namespace std;
using ull = unsigned long long;
using ld = long double;
ull ans[64][64], a, b;
ull dmul(ull a, ull b);
ull gmul(ull a, ull b) {
  if (a == 1 || b == 1) return a * b;
  ull n = 0, p = 0;
  while (n < 5 && (1ull << (1 << (n + 1))) <= max(a, b)) ++n;
  n = (1ull << (1 << n));
  if (a >= n && b >= n)
    p = dmul(n * 3ull / 2, gmul(a / n, b / n));
  else if (a >= n)
    p = gmul(a / n, b) * n;
  else
    p = gmul(a, b / n) * n;
  return p;
}
ull dmul(ull a, ull b) {
  ull ret = 0;
  while (a) {
    ull c = b;
    while (c) ret ^= gmul(a & -a, c & -c), c -= c & -c;
    a -= a & -a;
  }
  return ret;
}
ull mul(ull a, ull b) {
  ull p = 0;
  for (int i = 0; i < 64; i++)
    if (a & (1ull << i))
      for (int j = 0; j < 64; j++)
        if (b & (1ull << j)) p ^= ans[i][j];
  return p;
}
ull qpow(ull a, ull b) {
  ull ret = 1;
  while (b) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}
struct CRT {
  ull p, v;
};
inline ull mul(ull x, ull y, ull P) {
  return (x * y - ull(ld(x) / P * y) * P + P) % P;
}
ull qpow(ull a, ull b, ull P) {
  ull ret = 1;
  while (b) {
    if (b & 1) ret = mul(ret, a, P);
    a = mul(a, a, P);
    b >>= 1;
  }
  return ret;
}
CRT merge(CRT a, CRT b) {
  if (a.v == -1ull || b.v == -1ull) return {a.p * b.p, -1ull};
  ull tt = mul((b.v + b.p - a.v % b.p) % b.p, qpow(a.p, b.p - 2, b.p), b.p);
  return {a.p * b.p, tt * a.p + a.v};
}
CRT solve(ull p) {
  int bl = int(sqrt(p));
  ull a = qpow(::a, (-1ull) / p), b = qpow(::b, (-1ull) / p);
  set<ull> st;
  ull ml = a, cur = 1;
  for (int i = 0; i < bl; i++) st.insert(cur), cur = mul(cur, ml);
  ml = qpow(cur, -2ull);
  cur = 1;
  for (int i = 0; i <= bl + 1; i++) {
    if (st.count(mul(cur, b))) {
      cur = qpow(cur, -2ull);
      for (int j = 0; j < bl; j++) {
        if (cur == b) return {p, i * 1ull * bl + j};
        cur = mul(cur, a);
      }
    }
    cur = mul(cur, ml);
  }
  return {p, -1ull};
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 64; i++)
    for (int j = 0; j < 64; j++) ans[i][j] = gmul(1ull << i, 1ull << j);
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    CRT ans{1, 0};
    ans = merge(ans, solve(3));
    ans = merge(ans, solve(5));
    ans = merge(ans, solve(17));
    ans = merge(ans, solve(257));
    ans = merge(ans, solve(641));
    ans = merge(ans, solve(65537));
    ans = merge(ans, solve(6700417));
    if (qpow(a, ans.v) != b)
      cout << -1 << '\n';
    else
      cout << ans.v << '\n';
  }
  return 0;
}
