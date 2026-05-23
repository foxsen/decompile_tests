#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  int a, b, c, i, j, k;
  cin >> a >> b >> c;
  for (i = 0; i <= c / a; i++)
    if ((c - i * a) % b == 0) {
      cout << "Yes";
      return 0;
    }
  cout << "No";
}
