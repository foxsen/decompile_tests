#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m;
string A, B;
char buf[1000010];
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}
int AP[26][1000010];
int main() {
  scanf("%lld %lld", &n, &m);
  scanf("%s", buf);
  A = buf;
  scanf("%s", buf);
  B = buf;
  int N = A.length(), M = B.length();
  if (N < M) {
    swap(n, m);
    swap(A, B);
    swap(N, M);
  }
  unsigned long long L = (N * n) / lcm(N, M);
  unsigned long long G = gcd(N, M);
  unsigned long long totalHamming = 0LL;
  for (int i = 0; i < M; i++) {
    AP[B[i] - 'a'][i % G]++;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) {
      if (A[i] - 'a' == j) continue;
      totalHamming += AP[j][i % G];
    }
  }
  printf("%lld\n", totalHamming * L);
  return 0;
}
