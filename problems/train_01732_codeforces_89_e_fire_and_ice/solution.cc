#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, a[N], b[N];
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (n + 1); ++i) scanf("%d", a + i);
  while (!a[n]) --n;
  int Min = 1 << 30, d = 1;
  for (int i = 1; i < (n + 1); ++i) {
    for (int j = 1; j < (n + 1); ++j) b[j] = a[j] - (j >= i && a[j]);
    int cost = -i;
    for (int i = 1; i < (n + 1); ++i)
      cost += 3 * b[i] + 2 * max(0, b[i] - b[i - 1]);
    if (cost < Min) Min = cost, d = i;
  }
  for (int i = 1; i < (n + 1); ++i) b[i] = a[i] - (i >= d && a[i]);
  for (int i = 1; i < (n + 1); ++i) {
    while (b[i]) {
      int j = i;
      for (; b[j]; ++j) s += "AR", --b[j];
      s += "A" + string(j - i, 'L') + "A";
    }
    s += "AR";
  }
  s += "A" + string(n - d + 1, 'L') + "A";
  puts(s.c_str());
  return 0;
}
