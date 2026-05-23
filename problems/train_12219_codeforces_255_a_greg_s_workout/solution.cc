#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, chest = 0, bi = 0, back = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (i % 3 == 1)
      chest += x;
    else if (i % 3 == 2)
      bi += x;
    else if (i % 3 == 0)
      back += x;
  }
  int m = max(chest, max(bi, back));
  if (m == chest)
    cout << "chest";
  else if (m == bi)
    cout << "biceps";
  else
    cout << "back";
  return 0;
}
