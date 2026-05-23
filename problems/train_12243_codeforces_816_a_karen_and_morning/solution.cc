#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d;
  char e, f;
  scanf("%c%c:%d", &e, &f, &c);
  int a = e - '0', b = f - '0';
  int t = a * 10 + b, t2 = b * 10 + a;
  int ans = 0;
  while (t2 != c) {
    if (t2 < 60 && t2 >= c) {
      ans += t2 - c;
      break;
    }
    if (t2 == 32) {
      ans += 60 - c;
      break;
    }
    b++;
    if (b == 10) {
      a++;
      b = 0;
    }
    t2 = b * 10 + a;
    ans += 60 - c;
    c = 0;
  }
  cout << ans << endl;
  return 0;
}
