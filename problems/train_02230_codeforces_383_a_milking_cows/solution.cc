#include <bits/stdc++.h>
using namespace std;
long long n, a, t, sum;
void output(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  long long len = 0, data[10];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
int main() {
  cin >> n;
  while (n--) {
    cin >> a;
    if (a)
      t += a;
    else
      sum += t;
  }
  output(sum);
}
