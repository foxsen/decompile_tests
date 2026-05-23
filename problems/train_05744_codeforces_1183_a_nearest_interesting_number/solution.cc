#include <bits/stdc++.h>
using namespace std;
int dig(int a) {
  if (a / 10 == 0) return a;
  return (a % 10) + dig(a / 10);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    if (dig(n + i) % 4 == 0) {
      cout << (n + i);
      break;
    }
  }
  return 0;
}
