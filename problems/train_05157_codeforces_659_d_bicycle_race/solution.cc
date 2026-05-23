#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 1e3;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
inline int read_int() {
  char c;
  int ret = 0, sgn = 1;
  do {
    c = getchar();
  } while ((c < '0' || c > '9') && c != '-');
  if (c == '-')
    sgn = -1;
  else
    ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  return sgn * ret;
}
inline long long read_ll() {
  char c;
  long long ret = 0, sgn = 1;
  do {
    c = getchar();
  } while ((c < '0' || c > '9') && c != '-');
  if (c == '-')
    sgn = -1;
  else
    ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  return sgn * ret;
}
inline long long quick_pow(long long base, long long index, long long p) {
  long long res = 1;
  while (index) {
    if (index & 1) res = res * base % p;
    base = base * base % p;
    index >>= 1;
  }
  return res;
}
pair<int, int> arr[maxn + 5];
int n;
int main() {
  n = read_int();
  for (int i = 1; i <= n; ++i)
    arr[i].first = read_int(), arr[i].second = read_int();
  printf("%d\n", (n - 4) / 2);
  return 0;
}
