#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
int A[MAX_N], N, C[MAX_N], G[MAX_N];
bool U[MAX_N];
long long ans;
inline int inc(int v) { return (v + 1 == N) ? 0 : (v + 1); }
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int i, j, g, l, r, mx, len;
  long long ans = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", A + i);
  for (i = 1; i <= N; i++) G[i] = gcd(i, N);
  for (g = 1; g < N; g++) {
    if (N % g != 0) continue;
    for (i = 0; i < N; i++) U[i] = false, C[i] = 0;
    for (i = 0; i < g; i++) {
      mx = -1;
      for (j = i; j < N; j += g) mx = max(mx, A[j]);
      for (j = i; j < N; j += g)
        if (A[j] == mx) U[j] = true;
    }
    bool any = false;
    for (l = 0; l < N;) {
      r = inc(l);
      if (U[l]) {
        l++;
        continue;
      }
      any = true;
      len = 0;
      while (U[r]) len++, r = inc(r);
      for (i = 1; i <= len; i++) C[i] += len - i + 1;
      if (r <= l) break;
      l = r;
    }
    if (!any)
      for (i = 1; i <= N; i++) C[i] += N;
    for (i = 1; i <= N; i++)
      if (G[i] == g) ans += C[i];
  }
  printf("%I64d", ans);
  return 0;
}
