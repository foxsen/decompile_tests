#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
template <class T>
inline void read(T& a) {
  T x = 0, s = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') s = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + (c ^ '0');
    c = getchar();
  }
  a = x * s;
  return;
}
bool isprime[1000100];
int prime[1000100];
int n, cnt = 0;
long long sum[1000100];
void prepare() {
  isprime[0] = isprime[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    if (!isprime[i]) {
      prime[++cnt] = i;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= maxn; ++j) {
      isprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  return;
}
int main() {
  prepare();
  for (int i = 1; i <= maxn; i++) {
    sum[i] = sum[i - 1] + (!isprime[i]);
  }
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    printf("%lld\n", sum[n] - sum[(int)sqrt(n)] + 1);
  }
  return 0;
}
