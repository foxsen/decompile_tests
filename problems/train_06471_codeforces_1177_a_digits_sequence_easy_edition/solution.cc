#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, num, len;
  num = len = 1;
  cin >> k;
  while (1)
    if (k < num * 9 * len) {
      num = num - 1 + k / len + (k % len > 0);
      k = len - (k % len ? k % len : len);
      while (k--) num /= 10;
      cout << num % 10;
      exit(0);
    } else
      k -= num * 9 * len++, num *= 10;
  return 0;
}
