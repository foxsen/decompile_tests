#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int Max_Bit = 63;
const int INF = 2000000000;
const long long LINF = 1000000000000000007ll;
const int MOD = 1000000007;
const int NMAX = 100005;
const int MMAX = 505;
long long x;
int gnx() {
  x = (x * 37LL + 10007) % 1000000007;
  return x;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int a[NMAX], b[NMAX], to[NMAX], first[NMAX], n, d;
  scanf("%d%d", &n, &d);
  scanf("%I64d", &x);
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) swap(a[i], a[gnx() % (i + 1)]);
  for (int i = 0; i < n; ++i) {
    if (i < d) {
      b[i] = 1;
    } else {
      b[i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) swap(b[i], b[gnx() % (i + 1)]);
  for (int i = 0; i < n; ++i)
    if (b[i]) first[++first[0]] = i;
  int second = 30;
  for (int i = 0; i < n; ++i) to[a[i]] = i;
  for (int i = 0; i < n; ++i) {
    int j;
    for (j = n; j >= n - second; j--)
      if (j > 0 && i >= to[j] && b[i - to[j]]) {
        printf("%d\n", j);
        break;
      }
    if (j < n - second) {
      int maxi = 0;
      for (j = 1; j <= first[0] && first[j] <= i; j++)
        maxi = max(maxi, a[i - first[j]]);
      printf("%d\n", maxi);
    }
  }
  return 0;
}
