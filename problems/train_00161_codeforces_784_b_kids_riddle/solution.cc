#include <bits/stdc++.h>
using namespace std;
int s[114514] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  int n, m = 0;
  scanf("%d", &n);
  if (n == 0) m = 1;
  while (n != 0) m += s[n % 16], n /= 16;
  printf("%d", m);
}
