#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long f[1000010];
int h[1000010];
void upd(int first, int v) {
  while (first < 1000010) f[first] += v, h[first]++, first += first & -first;
}
pair<long long, long long> query(int first) {
  long long ans = 0, res = 0;
  while (first > 0) ans += f[first], res += h[first], first -= first & -first;
  return {ans, res};
}
int a[1000010];
int main() {
  int T, i, j, k, ca = 0, m = 0, n, K = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long p1, p2, sum = 0;
  double tot = 1LL * n * (n + 1) / 2, ans = 0;
  for (int i = 0; i < n; i++) {
    if (i) {
      pair<long long, long long> res = query(a[i]);
      p2 = res.first, K = res.second;
      p1 = sum - p2;
      K = i - K;
      ans += K + (p2 - p1) / tot * (n - i) / 2;
    }
    upd(a[i], i + 1);
    sum += i + 1;
  }
  printf("%.9lf\n", ans);
  return 0;
}
