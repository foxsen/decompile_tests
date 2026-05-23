#include <bits/stdc++.h>
using namespace std;
inline int _Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long int bigMod(long long int A, long long int P, int M) {
  long long int R = 1;
  for (A %= M; P; P >>= 1) {
    if (P & 1) R = (R * A) % M;
    A = (A * A) % M;
  }
  return R;
}
long long int bigMul(long long int A, long long int B, long long int M) {
  long long int R = 0;
  for (A %= M; B; B >>= 1) {
    if (B & 1) R = (R + A) % M;
    A = (A + A) % M;
  }
  return R;
}
long long int negMod(long long int A, long long int B) {
  return (((A % B) + B) % B);
}
long long int invMod(long long int A, long long int M) {
  return bigMod(A, M - 2, M);
}
unsigned long long int _pow(unsigned long long int A, int P) {
  unsigned long long int R = 1;
  for (; P; P >>= 1) {
    if (P & 1) R = (R * A);
    A = (A * A);
  }
  return R;
}
template <class T>
T GCD(T x, T y) {
  while (x) x ^= y ^= x ^= y %= x;
  return y;
}
template <class T>
bool inRng(T u, T v, T x) {
  return u <= x && x <= v;
}
int fr[1024 + 3];
int newfr[1024 + 3];
void Main() {
  int n = _Int();
  int k = _Int();
  int x = _Int();
  for (int i = 0; i < n; i++) {
    fr[_Int()]++;
  }
  while (k--) {
    int cnt = 0;
    for (int i = 0; i < 1024; i++) {
      int yyy = (fr[i] >> 1);
      int xxx = yyy + (fr[i] & 1);
      if (cnt & 1) {
        newfr[i] += xxx;
        newfr[i ^ x] += yyy;
      } else {
        newfr[i] += yyy;
        newfr[i ^ x] += xxx;
      }
      cnt += fr[i];
    }
    for (int i = 0; i < 1024; i++) {
      fr[i] = newfr[i];
      newfr[i] = 0;
    }
  }
  for (int i = 1023; i >= 0; i--) {
    if (fr[i]) {
      printf("%d ", i);
      break;
    }
  }
  for (int i = 0; i < 1024; i++) {
    if (fr[i]) {
      printf("%d\n", i);
      break;
    }
  }
}
int main() {
  Main();
  return 0;
}
