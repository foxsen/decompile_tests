#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, rez = 0, c;
  string a, b;
  cin >> n >> a >> b;
  while (n--) {
    c = abs(a[n] - b[n]);
    rez += min(c, 10 - c);
  }
  cout << rez;
  return 0;
}
