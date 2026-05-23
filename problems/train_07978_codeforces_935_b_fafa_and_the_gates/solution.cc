#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long int x = 0, y = 0, px = 0, py = 0;
  unsigned int n, count = 0;
  char c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == 'R')
      x += 1;
    else
      y += 1;
    if (i > 0 && x != y && ((x < y) ^ (px < py))) {
      count++;
    }
    if (x != y) {
      px = x;
      py = y;
    }
  }
  cout << count << endl;
  return 0;
}
