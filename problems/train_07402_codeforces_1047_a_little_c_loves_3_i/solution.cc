#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  printf("1 ");
  if ((n - 1) % 3 == 1)
    printf("2 %lld", n - 3);
  else
    printf("1 %lld", n - 2);
  return 0;
}
