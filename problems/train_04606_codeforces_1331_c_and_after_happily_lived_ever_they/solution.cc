#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 2e3 + 7;
int book[10];
void cal(int x) {
  for (int i = (0); i <= (5); i++) {
    if ((1 << i) & x)
      book[i] = 1;
    else
      book[i] = 0;
  }
  swap(book[2], book[3]);
  swap(book[0], book[4]);
  int res = 0;
  for (int i = (5); i >= (0); i--) {
    if (book[i]) {
      res += 1 << i;
    }
  }
  printf("%d\n", res);
}
int main() {
  int x;
  scanf("%d", &x);
  cal(x);
  return 0;
}
