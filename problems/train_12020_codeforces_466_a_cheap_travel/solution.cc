#include <bits/stdc++.h>
using namespace std;
int make1(int n, int m, int a, int b) {
  int wk = 0;
  while (n > 0) {
    n--;
    wk += a;
  }
  return wk;
}
int make2(int n, int m, int a, int b) {
  int wk = 0;
  while (n > 0) {
    n -= m;
    wk += b;
  }
  return wk;
}
int make3(int n, int m, int a, int b) {
  int wk = 0;
  while (n >= m) {
    n -= m;
    wk += b;
  }
  while (n > 0) {
    n--;
    wk += a;
  }
  return wk;
}
int main() {
  int n = 0, m = 0, a = 0, b = 0, last = 0;
  scanf("%i%i%i%i", &n, &m, &a, &b);
  if (a * m < b) {
    last = a * n;
    printf("%i\n", last);
  } else {
    int q = make1(n, m, a, b);
    int qq = make2(n, m, a, b);
    int qqq = make3(n, m, a, b);
    int min = q;
    if (qq < min) {
      min = qq;
    }
    if (qqq < min) {
      min = qqq;
    }
    printf("%i\n", min);
  }
  return 0;
}
