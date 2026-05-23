#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  int n;
  scanf("%d", &n);
  ;
  int x1 = 0, x2 = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    char c[10];
    scanf("%s", c);
    if (strlen(c) == 4) {
      y++;
    } else {
      if (c[0] == 'U' && c[1] == 'R') {
        x1++;
      } else if (c[0] == 'D' && c[1] == 'L') {
        x1++;
      } else {
        x2++;
      }
    }
  }
  long long a = y + 1 + x1;
  long long b = y + 1 + x2;
  cout << a * b;
  return 0;
}
