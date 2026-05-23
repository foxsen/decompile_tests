#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  int c = 0;
  while (n != m) {
    if (m % 2 == 0 && m > n) {
      c++;
      m /= 2;
      continue;
    }
    m++;
    c++;
  }
  cout << c << endl;
  return 0;
}
