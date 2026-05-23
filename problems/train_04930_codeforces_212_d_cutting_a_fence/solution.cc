#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
long long int getint() {
  long long int ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int MAXN = 1000000;
int a[MAXN + 10], L[MAXN + 10], R[MAXN + 10];
int stk[MAXN + 10];
long long int p[MAXN + 10], ans[MAXN + 10];
int main() {
  int n = getint();
  for (int i = 1; i <= n; ++i) a[i] = getint();
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top && a[stk[top]] >= a[i]) {
      R[stk[top]] = i - stk[top];
      --top;
    }
    stk[++top] = i;
    L[i] = i - stk[top - 1];
  }
  for (int i = 1; i <= top; ++i) R[stk[i]] = n + 1 - stk[i];
  for (int i = 1; i <= n; ++i) {
    if (L[i] > R[i]) swap(L[i], R[i]);
    p[1] += a[i];
    p[L[i] + 1] -= a[i];
    p[R[i] + 1] -= a[i];
    p[L[i] + R[i] + 1] += a[i];
  }
  long long int ret = 0, t = 0;
  for (int i = 1; i <= n; ++i) {
    t += p[i];
    ret += t;
    ans[i] = ret;
  }
  int q = getint();
  while (q--) {
    int k = getint();
    printf("%.15f\n", 1.0 * ans[k] / (n - k + 1));
  }
}
