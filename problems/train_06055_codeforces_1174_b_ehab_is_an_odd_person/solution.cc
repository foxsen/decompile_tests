#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  bool odd = false;
  bool even = false;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] % 2)
      odd = true;
    else
      even = true;
  }
  if (odd && even) sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
  return 0;
}
