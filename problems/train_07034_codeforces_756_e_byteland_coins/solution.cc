#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 300000 + 19;
const int oo = (1 << 30) - 1;
const int p = 1e9 + 7;
int dp[2][20 * N], mx[2];
int A[N], b[N], c[N], s[N];
int n, l, t, len;
char str[N];
void upd(int t, int x, int v) {
  dp[t][x] = (dp[t][x] + v) % p;
  if (x > mx[t]) mx[t] = x;
}
void Div(int x, int &rem) {
  long long tmp = 0;
  for (int i = l; i; i--) {
    tmp = (tmp * 1000000000 + s[i]);
    s[i] = tmp / x;
    tmp %= x;
  }
  rem = tmp;
  while (l > 1 && !s[l]) l--;
}
int main() {
  n = IN();
  A[1] = 1;
  for (int i = 2; i < n + 1; i++) A[i] = IN();
  for (int i = 1; i < n + 1; i++) b[i] = IN();
  scanf("%s", str + 1);
  len = strlen(str + 1);
  reverse(str + 1, str + len + 1);
  l = len / 9 + (len % 9 != 0);
  for (int i = 1; i < l + 1; i++) {
    for (int j = min(i * 9, len); j > (i - 1) * 9; j--) {
      s[i] = (s[i] * 10 + str[j] - '0');
    }
  }
  A[n + 1] = oo;
  for (int i = 1; i < n + 1; i++)
    if (A[i + 1] > 1) Div(A[i + 1], c[i]);
  if (l != 1 || s[1] != 0) {
    puts("0");
    return 0;
  }
  dp[t][0] = 1;
  dp[t][1] = p - 1;
  mx[t] = 1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < mx[t] + 1; j++) {
      dp[t][j] = (dp[t][j] + dp[t][j - 1]) % p;
    }
    for (int j = 0; j < mx[t] + 1; j++)
      if (dp[t][j]) {
        int k = (c[i] - j % A[i + 1] + A[i + 1]) % A[i + 1];
        int l = (j + k - c[i]) / A[i + 1],
            r = b[i] / A[i + 1] + 1 - (b[i] % A[i + 1] < k);
        upd(t ^ 1, l, dp[t][j]);
        upd(t ^ 1, l + r, p - dp[t][j]);
        dp[t][j] = 0;
      }
    mx[t] = 0;
    t ^= 1;
  }
  printf("%d\n", dp[t][0]);
}
