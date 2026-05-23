#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
int W, N, M;
int a[100001];
int k[100001];
int Max;
bool check(int ans) {
  int tmp;
  int sum = 0, day = M;
  memset(k, 0, sizeof(k));
  for (int i = 1; i <= N; i++) {
    sum += k[i];
    tmp = max(ans - a[i] - sum, 0);
    day -= tmp;
    if (day < 0) return false;
    if (i + 1 <= N) k[i + 1] += tmp;
    if (i + W <= N) k[i + W] -= tmp;
  }
  return true;
}
int main() {
  N = read(), M = read(), W = read();
  for (int i = 1; i <= N; i++) {
    a[i] = read();
    Max = max(Max, a[i]);
  }
  int l = 1, r = Max + M;
  int ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
}
