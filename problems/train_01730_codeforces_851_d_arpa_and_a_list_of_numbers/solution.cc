#include <bits/stdc++.h>
using namespace std;
int n, X, Y;
long long A[1000007] = {0}, B[1000007] = {0};
long long cnt(int l, int r) {
  r = min(r, 1000007 - 1);
  if (l > r) return 0;
  return A[r] - A[l - 1];
}
long long sum(int l, int r) {
  r = min(r, 1000007 - 1);
  if (l > r) return 0;
  return B[r] - B[l - 1];
}
long long check(int k) {
  long long res = 0;
  int d = X / Y;
  d = min(k, d);
  for (int i = 1; i < 1000007; i += k) {
    int l = i, r = l + k - 1;
    int mid = r - d;
    mid = max(mid, l);
    res += (cnt(mid, r) * (long long)r - sum(mid, r)) * (long long)Y;
    res += cnt(l, mid - 1) * (long long)X;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &X, &Y);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    A[a]++;
  }
  for (int i = 1; i < 1000007; i++) B[i] = A[i] * (long long)i + B[i - 1];
  for (int i = 1; i < 1000007; i++) A[i] += A[i - 1];
  long long ans = 0x7FFFFFFFFFFFFFFFLL;
  for (int i = 2; i < 1000007; i++) ans = min(ans, check(i));
  printf("%lld\n", ans);
  return 0;
}
