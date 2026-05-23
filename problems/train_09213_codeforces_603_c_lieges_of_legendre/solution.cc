#include <bits/stdc++.h>
using namespace std;
int k;
const int N = 1e5 + 5;
int a[N];
inline int GetSG(int x) {
  if (x < 2) return x;
  if (k & 1) {
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x == 4) return 2;
    if (x & 1)
      return 0;
    else {
      int tmp = GetSG(x / 2);
      return tmp > 1 ? 1 : tmp + 1;
    }
  } else {
    if (x == 2) return 2;
    if (x & 1)
      return 0;
    else
      return 1;
  }
}
int main() {
  int n = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans ^= GetSG(a[i]);
  printf("%s\n", ans ? "Kevin" : "Nicky");
  return 0;
}
