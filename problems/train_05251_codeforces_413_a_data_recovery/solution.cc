#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  int max;
  int min;
  cin >> n >> m >> min >> max;
  int x;
  int darch = n - m;
  int a = 0;
  int b = 0;
  for (int k = 1; k <= m; k++) {
    cin >> x;
    if (x < min || x > max) {
      cout << "Incorrect";
      return 0;
    }
    if (x == min) a = 1;
    if (x == max) b = 1;
  }
  int s = 2 - (a + b);
  if (darch < s)
    cout << "Incorrect";
  else
    cout << "Correct";
  return 0;
}
