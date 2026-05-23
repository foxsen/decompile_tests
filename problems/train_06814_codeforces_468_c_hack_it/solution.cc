#include <bits/stdc++.h>
using namespace std;
long long a, k = 1e17, x;
int main() {
  scanf("%lld", &a);
  a -= 9 * (k * 18 % a) % a * 5 % a;
  printf("%lld %lld", a, a + k * 10 - 1);
  return 0;
}
