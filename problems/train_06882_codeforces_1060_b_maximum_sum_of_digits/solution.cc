#include <bits/stdc++.h>
using namespace std;
static const int mod = 1e9 + 7;
static const int mmx = 1e7 + 5;
bool chkbt(int n, int pos) { return (bool)(n & (1 << pos)); }
long long fun(long long n) {
  long long sum = 0;
  while (1) {
    long long r = n % 10;
    sum += r;
    n /= 10;
    if (n == 0) return sum;
  }
}
int main() {
  long long n, i;
  while (scanf("%lld", &n) == 1) {
    int l = log10(n) + 1;
    long long sum = 0;
    for (i = 0; i < l; i++) {
      sum = (sum * 10) + 9;
    }
    if (sum > n) sum /= 10;
    long long sum2 = n - sum;
    printf("%lld\n", fun(sum) + fun(sum2));
  }
  return 0;
}
