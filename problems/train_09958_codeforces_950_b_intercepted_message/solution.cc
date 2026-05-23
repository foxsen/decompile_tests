#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m;
  cin >> n >> m;
  unsigned long long a, b, s = 0, s1[n], s2[m], c = 0;
  for (unsigned long long i = 0; i < n; i++) {
    cin >> a;
    s += a;
    s1[i] = s;
  }
  s = 0;
  for (unsigned long long i = 0; i < m; i++) {
    cin >> b;
    s += b;
    s2[i] = s;
  }
  unsigned long long i = 0, j = 0;
  while (1) {
    if (i == n) break;
    if (s1[i] == s2[j])
      c++;
    else if (s2[j] < s1[i]) {
      j++;
      continue;
    } else {
      i++;
      continue;
    }
    i++;
  }
  cout << c;
}
