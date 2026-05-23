#include <bits/stdc++.h>
using namespace std;
vector<int> f(100001);
int comp(int i) {
  int b = 0, d = 0;
  while (i > 0) {
    if (i & 1 == 1) b++;
    i = i >> 1;
  }
  return b;
}
int main() {
  int m, i, n;
  int h[65];
  long long j, s;
  for (i = 0; i < 65; i += 2) {
    h[i] = 0;
    h[i + 1] = 0;
  }
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (i = 0; i < n; i++) {
    h[comp(f[i])]++;
  }
  s = 0;
  for (i = 0; i < 65; i++) {
    j = h[i];
    j = j * (j - 1);
    j = j / 2;
    s += j;
  }
  cout << s;
  return 0;
}
