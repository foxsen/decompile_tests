#include <bits/stdc++.h>
using namespace std;
int mini(int a, int b, int c) {
  int minm = min(a, b);
  minm = min(c, minm);
  return minm;
}
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0)
    cout << "1\n";
  else
    cout << mini(n / 2, n - m, m) << endl;
}
