#include <bits/stdc++.h>
using namespace std;
long long x1, x2, a, b;
int main() {
  cin >> x1 >> x2 >> a >> b;
  long long dx = x1 - x2;
  if (a <= 0 && 0 <= b) {
    if (-b <= dx && dx <= -a) {
      puts("FIRST");
      cout << x1 - dx << endl;
    } else
      puts("DRAW");
    return 0;
  }
  if (dx * a > 0) {
    puts("DRAW");
    return 0;
  }
  long long len = abs(a) + abs(b);
  dx %= len;
  if (dx == 0) {
    puts("SECOND");
    return 0;
  }
  if (-b <= dx && dx <= -a) {
    puts("FIRST");
    cout << x1 - dx << endl;
  } else
    puts("DRAW");
  return 0;
}
