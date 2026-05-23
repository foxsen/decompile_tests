#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a, b;
long long aa[16] = {0,   4,   10,  20,  35,  56,  83,  116,
                    155, 198, 244, 292, 341, 390, 439, 488};
int main() {
  cin >> a;
  if (a <= 15) {
    cout << aa[a];
    return 0;
  }
  cout << a * 49 - 247;
  return 0;
}
