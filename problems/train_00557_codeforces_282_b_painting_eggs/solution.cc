#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long sa = 0, sg = 0;
  string ans = "";
  while (n--) {
    int a, g;
    scanf("%d %d", &a, &g);
    if (abs((sa + a) - sg) <= 500) {
      sa += a;
      ans += 'A';
    } else if (abs(sa - (sg + g)) <= 500) {
      sg += g;
      ans += 'G';
    } else {
      printf("%d", -1);
      return 0;
    }
  }
  cout << ans;
  return 0;
}
