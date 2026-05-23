#include <bits/stdc++.h>
using namespace std;
long long N, A[500];
template <typename T>
inline void RI(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    f |= (c == '-');
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
}
int main() {
  RI(N);
  for (long long i = 1; i <= N; ++i) RI(A[i]);
  sort(A + 1, A + N + 1);
  long long i;
  for (i = 1; i <= N; i += 2) printf("%I64d ", A[i]);
  if (N & 1)
    i = N - 1;
  else
    i = N;
  for (; i > 1; i -= 2) printf("%I64d ", A[i]);
  return 0;
}
