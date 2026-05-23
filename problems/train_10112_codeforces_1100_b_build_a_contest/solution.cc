#include <bits/stdc++.h>
using namespace std;
int main() {
  long int m, n, t = 0;
  cin >> n >> m;
  long int *p, *c, l = 0, v = 0;
  p = (long int *)malloc(m * sizeof(long int));
  c = (long int *)calloc(n, sizeof(long int));
  for (long int i = 0; i < m; i++) {
    long int temp;
    cin >> temp;
    if (c[temp - 1] == l) t++;
    c[temp - 1]++;
    if (t == n) {
      l++;
      v = 0;
      for (long int j = 0; j < n; j++)
        if (c[j] == l) v++;
      cout << "1";
      t -= v;
    } else
      cout << "0";
  }
  return 0;
}
