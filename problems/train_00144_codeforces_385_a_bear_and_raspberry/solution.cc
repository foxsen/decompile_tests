#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  int m;
  int dif;
  int ans;
  while (scanf("%d %d", &n, &c) == 2) {
    vector<int> num;
    for (int i = 0; i < n; i++) {
      scanf("%d", &m);
      num.push_back(m);
    }
    dif = ans = 0;
    for (int i = 1; i < num.size(); i++) {
      if (num[i - 1] - num[i] > dif) {
        dif = num[i - 1] - num[i];
        ans = num[i - 1] - num[i] - c;
      }
    }
    if (ans < 0)
      printf("0\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
