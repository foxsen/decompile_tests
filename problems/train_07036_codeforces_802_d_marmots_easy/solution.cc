#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T bpow(T p, T e) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
struct data {
  int el1, el2, el3;
  data() {}
  data(int a, int b, int c) { el1 = a, el2 = b, el3 = c; }
  bool friend operator<(data a, data b) { return a.el1 > b.el1; }
};
int n, m, k;
long long N, M, K;
int a[300];
int main() {
  int t, tc = 1;
  scanf("%d", &t);
  while (t--) {
    double sum = 0;
    for (int i = 1; i <= 250; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    double avg = sum / 250.0;
    double var = 0;
    for (int i = 1; i <= 250; i++) {
      var += (avg - a[i]) * (avg - a[i]);
    }
    var = var / 250.0;
    if (fabs(avg - var) <= avg) {
      printf("poisson\n");
    } else {
      printf("uniform\n");
    }
  }
  return 0;
}
