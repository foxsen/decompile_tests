#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 200005;
const int BL = 300;
long long ans;
char s[N];
int n, p[N], cnt[N * BL + N], rem[N];
int main() {
  scanf("%s", s + 1);
  n = (int)strlen(s + 1);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + s[i] - '0';
  int shift = n * BL;
  for (int k = 1; k <= BL; k++) {
    for (int i = 0; i <= n; i++) {
      rem[i] = i - k * p[i] + shift;
      ans += cnt[rem[i]];
      cnt[rem[i]]++;
    }
    for (int i = 0; i <= n; i++) cnt[rem[i]] = 0;
  }
  rem[0] = 0;
  for (int num = 1; num <= n / BL; num++) {
    for (int i = 1; i <= n; i++) {
      rem[i] = rem[i - 1] + 1;
      if (rem[i] == num) rem[i] = 0;
    }
    int L = 1, R = 0;
    int cur = BL * num;
    for (int i = 1; i <= n && p[i - 1] + num <= p[n]; i++) {
      while (L <= n && (L < cur + i || p[i - 1] + num > p[L])) cnt[rem[L++]]--;
      while (R < n && p[R + 1] <= p[i - 1] + num) cnt[rem[++R]]++;
      if (L > R) continue;
      ans += cnt[rem[i - 1]];
    }
    for (int i = 1; i <= n; i++) cnt[rem[i]] = 0;
  }
  cout << ans;
  return 0;
}
