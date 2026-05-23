#include <bits/stdc++.h>
long long n;
int k;
long long res;
struct matrix {
  long long a11, a12;
  long long a21, a22;
};
matrix A = (matrix){1, 1, 1, 0};
matrix multiply(matrix A, matrix B) {
  matrix C = (matrix){
      ((A.a11 * B.a11) % 1000000007ll + (A.a12 * B.a21) % 1000000007ll) %
          1000000007ll,
      ((A.a11 * B.a21) % 1000000007ll + (A.a12 * B.a22) % 1000000007ll) %
          1000000007ll,
      ((A.a21 * B.a11) % 1000000007ll + (A.a22 * B.a21) % 1000000007ll) %
          1000000007ll,
      ((A.a21 * B.a12) % 1000000007ll + (A.a22 * B.a22) % 1000000007ll) %
          1000000007ll};
  return C;
}
matrix power(matrix A, long long n) {
  if (n == 0) {
    matrix id = (matrix){1, 0, 0, 1};
    return id;
  }
  if (n == 1) {
    return A;
  }
  if (n % 2 == 1) {
    matrix B = power(A, n / 2);
    return multiply(B, multiply(B, A));
  }
  if (n % 2 == 0) {
    matrix B = power(A, n / 2);
    return multiply(B, B);
  }
}
long long fib(long long n) {
  matrix F = power(A, n);
  return F.a12;
}
long long pwr(long long base, int exp) {
  long long res = 1;
  for (int i = 0; i < exp; i++) res = (res * base) % 1000000007ll;
  return res;
}
long long choose[41][41];
long long S[41];
int main() {
  scanf("%lld%d", &n, &k);
  if (n <= 10) {
    long long s = 0;
    for (int i = 1; i <= n; i++) {
      s += (fib(i + 1) * pwr(i, k)) % 1000000007ll;
      s %= 1000000007ll;
    }
    printf("%lld\n", s);
    return 0;
  }
  for (int i = 0; i <= k; i++) choose[i][0] = 1;
  for (int i = 0; i <= k; i++) choose[i][i] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j < i; j++)
      choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % 1000000007ll;
  S[0] = (fib(n + 3) - 2) % 1000000007ll;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= i; j++) {
      S[i] += ((choose[i][j] * (pwr(2, j) + 1)) % 1000000007ll * S[i - j]) %
              1000000007ll;
      S[i] %= 1000000007ll;
    }
    S[i] = (1000000007ll - S[i]) % 1000000007ll;
    S[i] +=
        (pwr(2, i) - 1 - pwr(2, i + 1) +
         (pwr((n + 1) % 1000000007ll, i) * fib(n)) % 1000000007ll +
         ((pwr((n + 1) % 1000000007ll, i) + pwr((n + 2) % 1000000007ll, i)) *
          fib(n + 1)) %
             1000000007ll) %
        1000000007ll;
    S[i] %= 1000000007ll;
  }
  printf("%lld\n", S[k]);
  return 0;
}
