#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001], c[1001], i = -1, n, x, s;
int main() {
  cin >> n;
  while (++i < n) {
    cin >> a[i] >> x;
    if (b[a[i]]) {
      c[i]++;
      s++;
    }
    for (int j = 0; j < i; j++)
      if (a[j] == x && !c[j]) {
        c[j]++;
        s++;
      }
    b[x]++;
  }
  cout << n - s;
}
