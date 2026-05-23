#include <bits/stdc++.h>
using namespace std;
int a, b;
int y = 0;
int main() {
  cin >> a >> b;
  while (a <= b) {
    a = a * 3;
    b = b * 2;
    y++;
  }
  cout << y;
  return 0;
}
