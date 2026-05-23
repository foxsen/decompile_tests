#include <bits/stdc++.h>
using namespace std;
int T, sum, maxx, s[255];
int main() {
  scanf("%d", &T);
  while (T--) {
    sum = maxx = 0;
    for (int i = 1; i <= 250; i++)
      scanf("%d", s + i), sum += s[i], maxx = max(s[i], maxx);
    double aver = sum / 250.0, fang = 0;
    for (int i = 1; i <= 250; i++) fang += (s[i] - aver) * (s[i] - aver);
    printf("%.0f\n", fang / 250.0 / aver > 2 ? maxx * 1.04 / 2 : aver);
  }
}
