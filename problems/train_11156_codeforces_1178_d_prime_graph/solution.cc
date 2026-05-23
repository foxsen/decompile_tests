#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  int m = n;
  while (!isPrime(m)) m++;
  cout << m << "\n";
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", i, i + 1);
  }
  printf("%d %d\n", n, 1);
  for (int i = 1; i <= m - n; i++) {
    printf("%d %d\n", i, i + n / 2);
  }
}
