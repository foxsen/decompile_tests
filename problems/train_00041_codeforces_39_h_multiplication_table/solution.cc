#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int inline in() {
  int x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -in();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
int k;
int main() {
  cin >> k;
  for (int i = 0; i < (k - 1); i++) {
    for (int j = 0; j < (k - 1); j++) {
      int pro = (i + 1) * (j + 1);
      if (pro >= k) {
        int tmp = pro / k;
        pro %= k;
        pro += tmp * 10;
      }
      cout << pro << ' ';
    }
    cout << endl;
  }
  return 0;
}
