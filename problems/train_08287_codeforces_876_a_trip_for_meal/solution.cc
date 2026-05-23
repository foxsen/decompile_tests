#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  cout << min(a, b) + min(min(a, b), c) * (n - 2);
}
