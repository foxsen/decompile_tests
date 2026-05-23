#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[1001];
  int b[1001];
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) a[i] = i;
  int p = n;
  for (int x = n - k; x > 0; x--) {
    while (b[x]) {
      for (int y = 1; y < n; y++)
        if (a[y] == x) {
          for (int z = y + 1; z <= n; z++)
            if (a[z] >= p) {
              for (int w = y; w < z; w++) swap(a[w], a[w + 1]);
              break;
            }
          break;
        }
      b[x]--;
    }
    p--;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
