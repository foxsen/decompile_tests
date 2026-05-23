#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& num) {
  num = 0;
  bool f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num = num * 10 + ch - '0';
    ch = getchar();
  }
  num = f ? num : -num;
}
template <class T>
inline void write(T x, char ch) {
  int s[100];
  if (x == 0) {
    putchar('0');
    putchar(ch);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int num = 0;
  while (x) {
    s[num++] = (x % 10);
    x = x / 10;
  }
  for (int i = (num - 1); i >= (0); i--) putchar(s[i] + '0');
  putchar(ch);
}
const double pi = acos(-1);
const double eps = 1e-8;
int main() {
  long long ans = 100000000000000;
  long long A[4], ord[4];
  for (int i = (1); i <= (3); i++) {
    read(A[i]);
    ord[i] = i;
  }
  do {
    long long a = A[ord[1]], b = A[ord[2]], c = A[ord[3]];
    if (b < c) swap(b, c);
    long long res = c;
    a += c, b -= c;
    res += (b / 2) * 2;
    if (b & 1) res += a;
    ans = min(ans, res);
  } while (next_permutation(ord + 1, ord + 4));
  write(ans, '\n');
}
