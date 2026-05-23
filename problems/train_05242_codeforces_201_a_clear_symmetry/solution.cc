#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
long long x;
int main() {
  int biao[25] = {0};
  cin >> x;
  for (int i = 1; i <= 20; i++) {
    int now = (i + 1) / 2;
    if (i % 2 == 0)
      biao[i] = biao[i - 1];
    else
      biao[i] = now * now + (now - 1) * (now - 1);
  }
  if (x == 3)
    printf("5\n");
  else
    printf("%d\n", lower_bound(biao + 1, biao + 20 + 1, x) - biao);
  return 0;
}
